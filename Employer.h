//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_EMPLOYER_H
#define KURSOVIK_EMPLOYER_H


#include "List1.h"

#pragma pack(push, 1)

class NodeEmp {
public:
    List1 *title;
    List1 *fieldOfActivity;
    List1 *address;
    List1 *phoneNumber;

    NodeEmp *next;

    NodeEmp();

    ~NodeEmp();
};

class Employer {
public:
    NodeEmp *head, *last, *current;

    Employer();

    ~Employer();

    void MakeNewNode();

    void printEmployer(int numberOfRequiredVacancy, std::fstream &outputFile);
};

#pragma pack(pop)


#endif //KURSOVIK_EMPLOYER_H
