//
// Created by deadj on 14.05.2019.
//

#include "Vacancy.h"

NodeVacancy::NodeVacancy() {
    position = nullptr;
    schedule = nullptr;
    salary = nullptr;
    education = nullptr;
    workExperience = nullptr;
    fieldOfActivity = nullptr;
    employerApplications = nullptr;

    vacant = 'n';

    next = nullptr;
}

NodeVacancy::~NodeVacancy() = default;

Vacancy::Vacancy() {
    head = nullptr;
    last = nullptr;
}

Vacancy::~Vacancy() {
    NodeVacancy *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void Vacancy::makeNewNode() {
    auto *temp = new NodeVacancy;
    temp->next = nullptr;

    if (head != nullptr) {
        last->next = temp;
        last = temp;
        last->next = nullptr;
    } else {
        head = last = temp;
    }
}
