//
// Created by deadj on 14.05.2019.
//

#include "Vacancy.h"

Node::Node() {
    position = nullptr;
    schedule = nullptr;
    salary = nullptr;
    education = nullptr;
    work_experience = nullptr;
    field_of_activity = nullptr;
    employer_applications = nullptr;

    vacant = 'n';

    next = nullptr;
}

Node::~Node() = default;

Vacancy::Vacancy() {
    head = nullptr;
    last = nullptr;
}

Vacancy::~Vacancy() {
    Node *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void Vacancy::MakeNewNode() {
    auto *temp = new Node;
    temp->next = nullptr;

    if (head != nullptr) {
        last->next = temp;
        last = temp;
        last->next = nullptr;
    } else {
        head = last = temp;
    }
}
