#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include "publication.h"

class magazine: public publication
{
    static int amount;
    static double fee;
    static int time;
    int amount_of_articles;
public:
    magazine();
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};
#endif // MAGAZINE_H_INCLUDED
