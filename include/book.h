#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "publication.h"

class book: public publication
{
    static int amount;
    static double fee;
    static int time;
    int pages;
public:
    book(): position(amount), active(true), iterations(0);
    ~book();
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};

#endif // BOOK_H_INCLUDED
