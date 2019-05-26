//
// Created by deadj on 14.05.2019.
//

#include <fstream>
#include "Employer.h"

NodeEmp::NodeEmp() {
    title = nullptr;
    fieldOfActivity = nullptr;
    address = nullptr;
    phoneNumber = nullptr;

    next = nullptr;
}

NodeEmp::~NodeEmp() = default;

Employer::Employer() {
    head = nullptr;
    last = nullptr;
    current = nullptr;
}

Employer::~Employer() {
    NodeEmp *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void Employer::MakeNewNode() {
    auto *temp = new NodeEmp;
    temp->next = nullptr;

    if (head != nullptr) {
        last->next = temp;
        last = temp;
        last->next = nullptr;
    } else {
        head = last = temp;
    }
}

void Employer::printEmployer(int numberOfRequiredVacancy, std::fstream &outputFile) {
    this->current = this->head;
    for (int i = 1; i < numberOfRequiredVacancy; i++) {
        this->current = this->current->next;
    }
    auto temp = this->current->title->line;
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
    temp = this->current->address->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
    temp = this->current->phoneNumber->line;
    for (int j = 0; temp->block->symbols[j] != temp->block->marker; j++) {
        outputFile << temp->block->symbols[j];
        if (j == 4) {
            temp = temp->next;
            j = -1;
        }
    }
    outputFile << std::endl;
}