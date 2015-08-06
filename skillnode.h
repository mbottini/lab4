// skillnode.h
// Header file for skillNode class, used as building blocks for tree class.

#ifndef SKILLNODE_H
#define SKILLNODE_H

#define MAX_CHILDREN 3

#include <iostream>
#include "skill.h"
class skillNode {
    private:
        Skill _skill;
        skillNode **_children; // Array of pointers to children.
        int _numberOfChildren;
        int _maxChildren; // Defaults to 3 in this program.

    public:
        skillNode();
        void setValues();
        ~skillNode();
        void chainDelete();
        skillNode(const skillNode& originalNode);
        skillNode& operator =(const skillNode& originalNode);

        const Skill& getSkill() const;
        int getNumberOfChildren() const;
        skillNode* operator [](const int index) const;

        void setSkill(const Skill& newSkill);
        bool addChild(const Skill& newSkill);
};

std::ostream& operator <<(std::ostream& os, const skillNode& s);
#endif
