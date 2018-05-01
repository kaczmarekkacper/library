#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "human.h"

class librarian: public human
{
    static int amount;
    int number;
public:
    librarian();
    ~librarian();
    virtual bool lend();
    virtual bool give_back();
    virtual bool order();
    double check_fee();

};

#endif // LIBRARIAN_H_INCLUDED
