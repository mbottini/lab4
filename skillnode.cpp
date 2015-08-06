// skillnode.cpp
// Implementation file for skillNode class, used as building blacks for tree
// class.

#include "skillnode.h"

skillNode::skillNode() {
    setValues();
    return;
}

void skillNode::setValues() {
    _children = new skillNode*[MAX_CHILDREN];

    if(_children) {
        for(int i = 0; i < MAX_CHILDREN; i++) {
            _children[i] = NULL;
        }

        _maxChildren = MAX_CHILDREN;
    }

    else {
        _maxChildren = 0;
    }

    _numberOfChildren = 0;
    return;
}

skillNode::~skillNode() {
    chainDelete();
    return;
}

void skillNode::chainDelete() {
    for(int i = 0; i < _numberOfChildren; i++) {
        delete _children[i];
    }

    delete [] _children;
    _children = NULL;
    return;
}


skillNode::skillNode(const skillNode& originalNode) {
    _numberOfChildren = 0;
    _children = NULL;
    *this = originalNode;
    return;
}

skillNode& skillNode::operator =(const skillNode& originalNode) {
    chainDelete();
    setValues();

    for(int i = 0; i < originalNode.getNumberOfChildren(); i++) {
        _children[i] = new skillNode;
        if(_children[i]) {
            *(_children[i]) = *originalNode[i];
            _numberOfChildren++;
        }
    }

    _skill = originalNode.getSkill();

    return *this;
}

const Skill& skillNode::getSkill() const {
    return _skill;
}

int skillNode::getNumberOfChildren() const {
    return _numberOfChildren;
}

skillNode* skillNode::operator [](const int index) const {
    if(index >= 0 && index < _numberOfChildren) {
        return _children[index];
    }

    else {
        return NULL;
    }
}

void skillNode::setSkill(const Skill& newSkill) {
    _skill = newSkill;
    return;
}

bool skillNode::addChild(const Skill& newSkill) {
    bool childPredicate = false;

    if(_numberOfChildren < _maxChildren) {
        _children[_numberOfChildren] = new skillNode;

        if(_children[_numberOfChildren]) {
            _children[_numberOfChildren]->setSkill(newSkill);
            _numberOfChildren++;
            childPredicate = true;
        }
    }

    return childPredicate;
}

std::ostream& operator <<(std::ostream& os, const skillNode& s) {
    os << "  - " << s.getSkill();
    for(int i = 0; i < s.getNumberOfChildren(); i++) {
        os << "  " << *(s[i]);
    }

    return os;
}
