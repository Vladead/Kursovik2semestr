//
// Created by deadj on 14.05.2019.
//

#include "Vacancy.h"

Vacancy::Vacancy() {
    position = nullptr;
    schedule = nullptr;
    salary = nullptr;
    education = nullptr;
    field_of_activity = nullptr;
    work_experience = nullptr;
    employer_applications = nullptr;

    vacant = 'n';

    next = nullptr;
}

Vacancy::~Vacancy() = default;

void Vacancy::MakeNewNode() {
    auto* temp = new Vacancy;
    this->next = temp;
}