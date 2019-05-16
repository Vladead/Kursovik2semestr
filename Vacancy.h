//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_VACANCY_H
#define KURSOVIK_VACANCY_H


#include "List1.h"

class Vacancy {
public:
    BlocksList *position;
    BlocksList *schedule;
    BlocksList *salary;
    BlocksList *education;
    BlocksList *work_experience;
    BlocksList *field_of_activity;
    BlocksList *employer_applications;

    Vacancy();

    ~Vacancy();
};


#endif //KURSOVIK_VACANCY_H
