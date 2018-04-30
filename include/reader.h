#ifndef READER_H_INCLUDED
#define READER_H_INLCUDED

#include "human.h"

class reader: public human
{

public:
    reader();

    bool give_back();
    bool pay();

};

#endif // READER_H_INCLUDED
