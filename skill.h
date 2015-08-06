// skill.h
// Header file for skill class, used in skill tree program.

#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <cstring>

class Skill {
    private:
        char* _name;
        char* _description;
        int _level;

    public:
        Skill(const char* name = "", const char* description = "",
              const int& level = 0);
        void setValues(const char* name, const char* description,
                       const int& level);
        Skill(const Skill& originalSkill);
        Skill& operator =(const Skill& originalSkill);
        ~Skill();

        char* getName() const;
        char* getDescription() const;
        int getLevel() const;

        std::ostream& Display(std::ostream& os);
};

std::ostream& operator <<(std::ostream& os, const Skill& s);
#endif
