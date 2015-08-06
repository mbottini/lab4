// skill.h
// Header file for skill class, used in skill tree program.

#include <iostream>
#include <cstring>

class Skill {
    private:
        char* _name;
        char* _description;
        int _level;

    public:
        Skill(const char* name = "", const char* description = "",
              int level = 0);
        ~Skill();
        std::ostream& Display(std::ostream& os);
};
