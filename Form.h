//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_FORM_H
#define KURSOVIK_FORM_H


#include "List1.h"

#pragma pack(push, 1)

class Form {
public:
    List1 *head, *current, *last;

    Form() : head(nullptr), current(nullptr), last(nullptr) {

    }

    ~Form() = default;
};

#pragma pack(pop)


#endif //KURSOVIK_FORM_H
