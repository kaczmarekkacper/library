#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication
{
protected:
    int position; // first book has number one, next number two etc
    bool active; // is already taken
    int iterations; // how many iterations when taken
    double fee; // how much will you pay for each iteration delay
public:
    virtual void iter();
};

#endif // PUBLICATION_H_INCLUDED
