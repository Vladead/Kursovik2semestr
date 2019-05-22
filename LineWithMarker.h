//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_LINEWITHMARKER_H
#define KURSOVIK_LINEWITHMARKER_H


#pragma pack(push, 1)

class LineWithMarker {
public:
    char *symbols;
    char Marker;

    LineWithMarker() : symbols(nullptr), Marker('@') {

    }
    ~LineWithMarker() {
        delete[] symbols;
    }
};

#pragma pack(pop)


#endif //KURSOVIK_LINEWITHMARKER_H
