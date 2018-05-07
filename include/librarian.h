#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "human.h"

class librarian: public human
{
    static int amount;
    std::vector<human> clients;
public:
    librarian();
    ~librarian();
};

#endif // LIBRARIAN_H_INCLUDED
