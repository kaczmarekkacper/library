#ifndef READER_H_INCLUDED
#define READER_H_INLCUDED

#include <vector>
#include "human.h"
#include "publication.h"

class reader: public human, public operations
{
    static int amount;
public:
    reader();
    ~reader();
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};

#endif // READER_H_INCLUDED
