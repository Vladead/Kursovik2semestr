//
// Created by deadj on 14.05.2019.
//

#include "JobSeeker.h"

NodeJobSeeker::NodeJobSeeker() {
    surname = nullptr;
    name = nullptr;
    patronymic = nullptr;
    position = nullptr;
    field_of_activity = nullptr;
    work_experience = nullptr;
    education = nullptr;
    schedule = nullptr;
    salary = nullptr;

    next = nullptr;
}

NodeJobSeeker::~NodeJobSeeker() = default;

JobSeeker::JobSeeker() {
    head = nullptr;
    last = nullptr;
}

JobSeeker::~JobSeeker() {
    NodeJobSeeker *temp;
    while (head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void JobSeeker::MakeNewNode() {
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
