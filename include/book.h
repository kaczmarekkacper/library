#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "publication.h"

class book: public publication
{
    static int amount; // a counter for position
    static int time; // how many iterations it could be taken without paying
    int pages; // simple field
public:
    book();
};

#endif // BOOK_H_INCLUDED
