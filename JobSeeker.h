//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_JOBSEEKER_H
#define KURSOVIK_JOBSEEKER_H


#include "List1.h"

#pragma pack(push, 1)

class NodeJobSeeker {
public:
    BlocksList *surname;
    BlocksList *name;
    BlocksList *patronymic;
    BlocksList *position;
    BlocksList *fieldOfActivity;
    BlocksList *workExperience;
    BlocksList *education;
    BlocksList *schedule;
    BlocksList *salary;

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
