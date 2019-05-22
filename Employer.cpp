//
// Created by deadj on 14.05.2019.
//

#include "Employer.h"

NodeEmp::NodeEmp() {
    title = nullptr;
    field_of_activity = nullptr;
    address = nullptr;
    phone_number = nullptr;

    next = nullptr;
}

NodeEmp::~NodeEmp() = default;

Employer::Employer() {
    head = nullptr;
    last = nullptr;
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
