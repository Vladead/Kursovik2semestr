//
// Created by vladead on 08.05.19.
//

#ifndef KURSOVIK_LINEWITHMARKER_H
#define KURSOVIK_LINEWITHMARKER_H


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


#endif //KURSOVIK_LINEWITHMARKER_H
