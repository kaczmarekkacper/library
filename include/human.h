#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <vector>

#include "human_interface.h"
#include "publication.h"

class human: public human_interface
{
protected:
    int number;
    double fee;
    std::vector<publication *> books_n_magazines; // field of books and magazines for humans
public:
    human();
    ~human();
    virtual bool order( publication *work, human *assistant );
    virtual bool get( publication *work, human *assistant );
    virtual bool giveback( publication *work, human *assistant );
    virtual double check_fee( publication *work, human *assistant );
    virtual void change_fee ( double extra_fee );
};
#endif // HUMAN_H_INCLUDED
