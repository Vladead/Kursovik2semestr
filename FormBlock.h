//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_FORMBLOCK_H
#define KURSOVIK_FORMBLOCK_H

#include "BlocksList.h"

#pragma pack(push, 1)

class FormBlock {
public:
    BlocksList *head, *current, *last;

    FormBlock() : head(nullptr), current(nullptr), last(nullptr) {

    }

    ~FormBlock() = default;
};

#pragma pack(pop)


#endif //KURSOVIK_FORMBLOCK_H
