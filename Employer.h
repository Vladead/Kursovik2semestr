//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_EMPLOYER_H
#define KURSOVIK_EMPLOYER_H


#include "List1.h"

#pragma pack(push, 1)

class NodeEmp {
public:
    BlocksList *title;
    BlocksList *field_of_activity;
    BlocksList *address;
    BlocksList *phone_number;

    NodeEmp *next;

    NodeEmp();

    ~NodeEmp();
};

class Employer {
public:
    NodeEmp *head, *last;

    Employer();

    ~Employer();

    void MakeNewNode();
};

#pragma pack(pop)


#endif //KURSOVIK_EMPLOYER_H
