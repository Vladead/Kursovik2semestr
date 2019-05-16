//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_BLOCKSLIST_H
#define KURSOVIK_BLOCKSLIST_H


#include "LineWithMarker.h"

class BlocksList {
public:
    unsigned max_symbols_in_block;
    LineWithMarker *block;
    BlocksList *next;

    BlocksList() : max_symbols_in_block(0), block(nullptr), next(nullptr) {
        max_symbols_in_block = 5;
    }
    ~BlocksList() {
        delete block;
    }
};


#endif //KURSOVIK_BLOCKSLIST_H
