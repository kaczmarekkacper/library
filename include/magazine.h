#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "publication.h"

class magazine: public operations, public publication
{
    static int amount; // a counter for position
    static int time; // how many iterations it could be taken without paying
    int amount_of_articles; //simple field
public:
    magazine();
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};
#endif // MAGAZINE_H_INCLUDED
