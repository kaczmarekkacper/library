#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "publication.h"

class book: public publication
{
    static int amount;
public:
    book(int HOW_MANY): position(amount), how_many(HOW_MANY), active(true), fee(1.5);
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};

#endif // BOOK_H_INCLUDED
