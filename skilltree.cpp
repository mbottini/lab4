// skilltree.cpp
// Implementation file for skilltree class.

#include "SkillTree.h"

SkillTree::SkillTree(const char* title) {
    _title = new char[strlen(title) + 1];
    if(_title) {
        strncpy(_title, title, strlen(title) + 1);
    }
    _root = NULL;
    return;
}

SkillTree::SkillTree(const SkillTree& originalTree) {
    _title = NULL;
    _root = NULL;
    *this = originalTree;
    return;
}

SkillTree& SkillTree::operator =(const SkillTree& originalTree) {
    if(_title != originalTree.getTitle()) {
        delete [] _title;
        delete _root;
        _title = new char[strlen(originalTree.getTitle()) + 1];

        if(_title) {
            strncpy(_title, originalTree.getTitle(),
                            strlen(originalTree.getTitle()) + 1);
        }

        _root = new skillNode;

        if(_root) {
            _root = originalTree.getRoot();
        }

        else {
            delete [] _title;
            _title = NULL;
        }
    }

    return *this;
}

SkillTree::~SkillTree() {
    delete [] _title;
    delete _root;
    return;
}

void SkillTree::AddSkill(const char* name, const char* description, int level) {
    Skill newSkill(name, description, level);
    if(!_root) {
        _root = new skillNode;
        if(_root) {
            _root->setSkill(newSkill);
        }
    }

    else {
        skillNode* tempNode = new skillNode;
        if(tempNode) {
            tempNode->setSkill(newSkill);
            tempNode->addChild(_root);
            _root = tempNode;
        }
    }

    return;
}

void SkillTree::AddSkill(const char* name, const char* description, int level,
                         const char* parentName) {
    if(!FindSkill(name)) { // Don't want duplicates in the tree.
        skillNode *parent = findSkillNode(parentName);

        if(parent) {
            parent->addChild(Skill(name, description, level));
        }
    }

    return;
}

Skill* SkillTree::FindSkill(const char* name) {
    skillNode *node = findSkillNode(name);

    if(node) {
        return node->getSkillPtr();
    }

    else {
        return NULL;
    }
}

skillNode* SkillTree::findSkillNode(const char* name) {
    return _root->findSkillNode(name);
}

char* SkillTree::getTitle() const {
    return _title;
}

skillNode* SkillTree::getRoot() const {
    return _root;
}

std::ostream& SkillTree::Display(std::ostream& os) {
    os << "Skill Tree: " << _title << "\n";
    if(_root) {
        _root->Display(os, 0);
    }

    else {
        os << "  Empty\n";
    }
    return os;
}
