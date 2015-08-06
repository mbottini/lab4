// skill.cpp
// Implementation file for skill class, used in skill tree program.

#include "skill.h"

Skill::Skill(const char* name, const char* description, int level) {
    _name = new char[strlen(name) + 1];

    if(_name) {
        _description = new char[strlen(description) + 1];

        if(_description) {
            strncpy(_name, name, strlen(name) + 1);
            strncpy(_description, description, strlen(description) + 1);
            _level = level;
        }

        else {
            _level = 0;
            delete [] _name;
            _name = NULL;
        }
    }

    else {
        _description = NULL;
        _level = 0;
    }

    return;
}

Skill::~Skill() {
    delete [] _name;
    delete [] _description;
    _level = 0;
    return;
}

std::ostream& Skill::Display(std::ostream& os) {
    os << _name << " -- " << _description << " [Lvl: " << _level << "]\n";
    return os;
}

int main() {
    Skill s("Alphabet", "Mastery of letters and sounds", 0);
    s.Display(std::cout);
    return 0;
}
