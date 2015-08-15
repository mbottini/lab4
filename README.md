# lab4
CS 260 lab 4.

Implementation of a tree abstract data type. 

Make with the following command:

    $ make

Run with the following command:

    $ ./lab4.

Program currently runs with no memory leaks or crashes, which is nice.

Files are the following:

## skill.cpp: Skill class. 
Class has the following members:
Name (dynamically allocated character array)
Description (dynamically allocated character array)
Level (integer)

Standard getter functions apply, returning const char*, const char*, and const int, respectively.

Assignment operator and copy constructor perform deep copies.

"Display" function is a requirement for the assignment.

## skillnode.cpp: skillNode class, a "branch" class - the building blocks of the tree.
Class has the following members:
data (Skill object)
children (dynamically allocated array with MAX_CHILDREN elements of pointers to SkillNodes, defined in skillnode.h).
maxChildren (integer, equal to MAX_CHILDREN but is there in case it needs to be changed in future assignments.
numberOfChildren (integer, equal to the number of defined children).

Standard getter functions apply, returning the types defined.

Assignment operator and copy constructor perform deep copies, recursively copying all children (and children of 
children, and so on). Destructor recursively deletes all children in a similar manner.

The [] operator is overloaded to return a pointer to the child in that index. It returns NULL if there is no
child there or if the index is invalid.

The addChild operator will work with either a pointer to a skillNode object or a Skill object. In either case,
the function will check to see if it is possible to add the child. No other checks are done to make sure that
the skill is valid; that checking is done by the SkillTree class.

The << operator is overloaded to print the contents of the node to ostream. Like the copy, it will recursively
print all children (and children's children, and so on). The "depth" of the node being printed will impact its
level of indentation.

## skilltree.cpp SkillTree class, a "tree" class of SkillNode objects.
Class has the following members:
Title (dynamically allocated character array)
Root (pointer to skillNode object)

Most of the functionality is actually done by the skillNode class; for example, printing the contents of the tree
is as simple as printing the root. All functions in the tree are there to fulfill the criteria for the assignment.

Assignment operator and copy constructor perform deep copies, as it's just as simple as copying the root nodes over.

No duplicates are allowed in the tree. When a skill is added to the tree, the function will search the tree first
and do nothing if a duplicate is found.

## main.cpp Instructor-provided main function, which tests the tree.

Yep, it has lots of spelling errors and includes "SkillTree.h." The instructor is speaking ex cathedra, so he is
always right. I work around this. Happy happy joy joy.
