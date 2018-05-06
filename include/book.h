#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "publication.h"

class book: public operations, public publication
{
    static int amount; // a counter for position
    static int time; // how many iterations it could be taken without paying
    int pages; // simple field
public:
    book();
    ~book();
    virtual bool order( human *selected );
    virtual bool get( human *selected );
    virtual bool giveback( human *selected );
    virtual double check_fee();
    virtual void iter();
};

#endif // BOOK_H_INCLUDED
