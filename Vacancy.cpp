//
// Created by deadj on 14.05.2019.
//

#include "Vacancy.h"
#include <fstream>

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
    current = nullptr;
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

void Vacancy::printVacancy(int numberOfRequiredVacancy, std::fstream &outputFile) {
    this->current = this->head;
    for (int i = 1; i < numberOfRequiredVacancy; i++) {
        this->current = this->current->next;
    }
    auto temp = this->current->position->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->schedule->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->salary->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->education->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->fieldOfActivity->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->workExperience->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->employerApplications->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
}
