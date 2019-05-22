//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_LIST1_H
#define KURSOVIK_LIST1_H


#include "BlocksList.h"

#pragma pack(push, 1)

class List1 {
public:
    BlocksList *line;
    int symbolsInLine;
    List1 *next;

    List1() : line(nullptr), symbolsInLine(0), next(nullptr) {

    }

    ~List1() {
        delete line;
    }
};

#pragma pack(pop)


#endif //KURSOVIK_LIST1_H
