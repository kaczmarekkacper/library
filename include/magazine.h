#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "publication.h"

class magazine: public publication
{
    static int amount; // a counter for position
    static int time; // how many iterations it could be taken without paying
    int amount_of_articles; // simple field
public:
    magazine(); //
};
#endif // MAGAZINE_H_INCLUDED
