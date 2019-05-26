//
// Created by deadj on 14.05.2019.
//

#ifndef KURSOVIK_VACANCY_H
#define KURSOVIK_VACANCY_H


#include <fstream>
#include "List1.h"

#pragma pack(push, 1)

class NodeVacancy {
public:
    List1 *position;
    List1 *schedule;
    List1 *salary;
    List1 *education;
    List1 *workExperience;
    List1 *fieldOfActivity;
    List1 *employerApplications;

    char vacant;

    NodeVacancy *next;

    NodeVacancy();

    ~NodeVacancy();
};

class Vacancy {
public:
    NodeVacancy *head, *last, *current;

    Vacancy();

    ~Vacancy();

    void makeNewNode();

    void printVacancy(int numberOfRequiredVacancy, std::fstream &outputFile);
};

#pragma pack(pop)


#endif //KURSOVIK_VACANCY_H
