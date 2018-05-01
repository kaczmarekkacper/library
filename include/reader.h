#ifndef READER_H_INCLUDED
#define READER_H_INLCUDED

#include <vector>
#include "human.h"
#include "publication.h"

class reader: public human
{
    int number;
    static int amount;
    std::vector <publication> publications;
    double fee;
public:
    reader();
    virtual bool lend();
    virtual bool giveback();
    virtual bool order();
    bool pay_fee();
};

#endif // READER_H_INCLUDED
