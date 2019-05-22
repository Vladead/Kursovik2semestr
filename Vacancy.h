//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_VACANCY_H
#define KURSOVIK_VACANCY_H


#include "List1.h"

#pragma pack(push, 1)

class Node {
public:
    BlocksList *position;
    BlocksList *schedule;
    BlocksList *salary;
    BlocksList *education;
    BlocksList *work_experience;
    BlocksList *field_of_activity;
    BlocksList *employer_applications;

    char vacant;

    Node *next;

    Node();

    ~Node();
};

class Vacancy {
public:
    Node *head, *last;

    Vacancy();

    ~Vacancy();

    void MakeNewNode();
};

#pragma pack(pop)


#endif //KURSOVIK_VACANCY_H
