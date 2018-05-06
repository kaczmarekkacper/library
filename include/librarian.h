#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "human.h"

class librarian: public human, public operations
{
    static int amount;
    std::vector<human> clients;
public:
    librarian();
    ~librarian();
    virtual bool order( publication work );
    virtual bool get( publication work );
    virtual bool giveback( publication work );
    virtual double check_fee( publication work );
    virtual bool getback( publication work, human client );
    virtual bool set_ordered( publication work, human client );
    virtual bool put_in( publication work, human client );
    virtual double check_fee( publication work );
};

#endif // LIBRARIAN_H_INCLUDED
