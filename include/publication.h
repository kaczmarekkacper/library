#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED

#include <vector>
#include <fstream>
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
    double fee; // how much will you pay for each iteration delay
    int loops; // something like "time" in magaizne/book
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
    virtual int iter();
    virtual bool isactive();
    virtual bool check_owner( human *client );
    virtual void status( fstream *file = nullptr);
    virtual bool statusqueue();
    virtual void set_fee_as_zero();
    virtual int get_position();
    virtual void whats_your_name( fstream *file = nullptr );
};

#endif // PUBLICATION_H_INCLUDED
