// skilltree.h
// Header file for skilltree class.

#include "skillnode.h"
#include "skill.h"
#include <iostream>

class SkillTree {
    private:
        char* _title;
        skillNode *_root;

    public:
        SkillTree(const char* title = "Default");
        SkillTree(const SkillTree& originalTree);
        SkillTree& operator =(const SkillTree& originalTree);
        ~SkillTree();

        void AddSkill(const char* name, const char* description, int level);
        void AddSkill(const char* name, const char* description, int level,
                      const char* parentName);

        Skill* FindSkill(const char* name);
        skillNode* findSkillNode(const char* name);

        char* getTitle() const;
        skillNode* getRoot() const;

        std::ostream& Display(std::ostream& os);
};

