//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_JOBSEEKER_H
#define KURSOVIK_JOBSEEKER_H


#include "List1.h"

class JobSeeker {
public:
    BlocksList *surname;
    BlocksList *name;
    BlocksList *patronymic;
    BlocksList *position;
    BlocksList *field_of_activity;
    BlocksList *work_experience;
    BlocksList *education;
    BlocksList *schedule;
    BlocksList *salary;

    JobSeeker();

    ~JobSeeker();
};


#endif //KURSOVIK_JOBSEEKER_H
