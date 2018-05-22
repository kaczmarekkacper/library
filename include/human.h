#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <vector>
#include <fstream>

#include "human_interface.h"
#include "publication.h"

class human: public human_interface
{
protected:
    int number;
    int type;
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
    virtual void human_status ( std::fstream *file = nullptr);
};
#endif // HUMAN_H_INCLUDED
