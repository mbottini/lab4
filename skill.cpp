// skill.cpp
// Implementation file for skill class, used in skill tree program.

#include "skill.h"

Skill::Skill(const char* name, const char* description, const int& level) {
    setValues(name, description, level);
    return;
}

// Default constructor. Defaults to "", "", 0 when called with no args.
void Skill::setValues(const char* name, const char* description,
                      const int& level) {
    _name = new char[strlen(name) + 1];

    if(_name) {
        _description = new char[strlen(description) + 1];

        if(_description) {
            strncpy(_name, name, strlen(name) + 1);
            strncpy(_description, description, strlen(description) + 1);
            _level = level;
        }

        else { // Description alloc failed, so we delete name as well.
            _level = 0;
            delete [] _name;
            _name = NULL;
        }
    }

    else { // Name is already NULL from failed alloc.
        _description = NULL;
        _level = 0;
    }

    return;
}

Skill::Skill(const Skill& originalSkill) {
    _name = NULL;
    _description = NULL;
    *this = originalSkill; // See below for overloaded = operator.
    return;
}

Skill& Skill::operator =(const Skill& originalSkill) {
    if(_name != originalSkill.getName()) { // Don't delete if they're the same.
        delete [] _name;
        delete [] _description;
        _level = 0;

        setValues(originalSkill.getName(), originalSkill.getDescription(),
                  originalSkill.getLevel());
    }

    return *this;
}

Skill::~Skill() {
    delete [] _name;
    delete [] _description;
    _level = 0;
    return;
}

char* Skill::getName() const {
    return _name;
}

char* Skill::getDescription() const {
    return _description;
}

int Skill::getLevel() const {
    return _level;
}

// I prefer overloaded operators, so this is just a wrapper for the assignment.
std::ostream& Skill::Display(std::ostream& os) {
    os << *this;
    return os;
}

std::ostream& operator <<(std::ostream& os, const Skill& s) {
    os << s.getName() << " -- " << s.getDescription() << " [Lvl: " 
       << s.getLevel() << "]";
    return os;
}
