#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication: public operations
{
protected:
    int position; // first book/magazine has number one, next number two etc
    bool active; // is already taken?
    int iterations; // how many iterations when taken
    double fee; // how much will you pay for each iteration delay
    human *owner // human who has a book right now
    int ordered; // if book isnt ordered, value is -1, in other case, value is amount of iterations it should be ordered
public:
    virtual bool order( human *selected, int loops );
    virtual bool get( human *selected );
    virtual bool giveback( human *selected );
    virtual double check_fee();
    virtual void iter();
};

#endif // PUBLICATION_H_INCLUDED
