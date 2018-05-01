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
    ~reader();
    virtual bool lend();
    virtual bool give_back();
    virtual bool order();
    bool pay_fee();
};

#endif // READER_H_INCLUDED
