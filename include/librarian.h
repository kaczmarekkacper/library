#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "human.h"

class librarian: public human
{
    static int amount;
    int number;
public:
    librarian();
    virtual bool lend();
    virtual bool giveback();
    virtual bool order();
    double check_fee();

};

#endif // LIBRARIAN_H_INCLUDED
