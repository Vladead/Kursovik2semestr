//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_FORMBLOCK_H
#define KURSOVIK_FORMBLOCK_H

#include "BlocksList.h"

class FormBlock {
public:
    BlocksList *head, *current, *last;

    FormBlock() : head(nullptr), current(nullptr), last(nullptr) {

    }

    ~FormBlock() = default;
};


#endif //KURSOVIK_FORMBLOCK_H
