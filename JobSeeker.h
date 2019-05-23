//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_JOBSEEKER_H
#define KURSOVIK_JOBSEEKER_H


#include "List1.h"

#pragma pack(push, 1)

class NodeJobSeeker {
public:
    List1 *surname;
    List1 *name;
    List1 *patronymic;
    List1 *position;
    List1 *fieldOfActivity;
    List1 *workExperience;
    List1 *education;
    List1 *schedule;
    List1 *salary;

    NodeJobSeeker *next;

    NodeJobSeeker();

    ~NodeJobSeeker();
};

class JobSeeker {
public:
    NodeJobSeeker *head, *last;

    JobSeeker();

    ~JobSeeker();

    void makeNewNode();
};

#pragma pack(pop)


#endif //KURSOVIK_JOBSEEKER_H
