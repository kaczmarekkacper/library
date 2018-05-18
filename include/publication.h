#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED

#include <vector>
#include "human.h"

using namespace std;

#include "pub_interface.h"

class publication: public pub_interface
{
protected:
    int position; // first book/magazine has number one, next number two etc
    int type; // 1 for books, 2 for magazines
    bool active; // is already taken?
    int iterations; // how many iterations when taken
    int time;
    double fee; // how much will you pay for each iteration delay
    human *owner; // human who has a book right now
    int ordered; // if book isnt ordered, value is -1, in other case, value is amount of iterations it take to be taken
    vector <human *> ordering;
public:
    publication();
    ~publication();
    virtual bool order( human *selected ); // return 0 if publication isnt taken
    virtual bool get( human *selected );
    virtual bool giveback( human *selected );
    virtual double check_fee();
    virtual void iter();
    virtual bool isactive();
    virtual bool check_owner( human *client );
};

#endif // PUBLICATION_H_INCLUDED
