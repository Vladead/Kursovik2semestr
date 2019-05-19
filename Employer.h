//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_EMPLOYER_H
#define KURSOVIK_EMPLOYER_H


#include "List1.h"

class Employer {
public:
    BlocksList *title;
    BlocksList *field_of_activity;
    BlocksList *address;
    BlocksList *phone_number;

    Employer* next;

    Employer();

    ~Employer();
};


#endif //KURSOVIK_EMPLOYER_H
