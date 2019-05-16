//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_EMPLOYER_H
#define KURSOVIK_EMPLOYER_H


#include "List1.h"

class Employer {
public:
    List1 *title;
    List1 *field_of_activity;
    List1 *address;
    List1 *phone_number;

    Employer();

    ~Employer();
};


#endif //KURSOVIK_EMPLOYER_H
