//
// Created by deadj on 14.05.2019.
//

#include <fstream>
#include "JobSeeker.h"

NodeJobSeeker::NodeJobSeeker() {
    surname = nullptr;
    name = nullptr;
    patronymic = nullptr;
    position = nullptr;
    fieldOfActivity = nullptr;
    workExperience = nullptr;
    education = nullptr;
    schedule = nullptr;
    salary = nullptr;

    next = nullptr;
}

NodeJobSeeker::~NodeJobSeeker() = default;

JobSeeker::JobSeeker() {
    head = nullptr;
    last = nullptr;
    current = nullptr;
}

JobSeeker::~JobSeeker() {
    NodeJobSeeker *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void JobSeeker::makeNewNode() {
    auto *temp = new NodeJobSeeker;
    temp->next = nullptr;

    if (head != nullptr) {
        last->next = temp;
        last = temp;
        last->next = nullptr;
    } else {
        head = last = temp;
    }
}

void JobSeeker::printJobSeeker(int numberOfRequiredVacancy, std::fstream &outputFile) {
    this->current = this->head;
    for (int i = 1; i < numberOfRequiredVacancy; i++) {
        this->current = this->current->next;
    }
    auto temp = this->current->surname->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->name->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->patronymic->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->position->line;
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
    temp = this->current->education->line;
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
}