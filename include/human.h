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
    std::vector<int> status;
public:
    human();
    ~human();
    virtual bool order( publication *work );
    virtual bool get( publication *work );
    virtual double giveback( publication *work );
    virtual double check_fee( );
    virtual int get_number();
};
#endif // HUMAN_H_INCLUDED
