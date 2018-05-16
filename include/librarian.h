#ifndef LIBRARIAN_H_INCLUDED
#define LIBRARIAN_H_INCLUDED

#include "human.h"
#include "publication.h"


class librarian: public human
{
    static int amount;
    std::vector<human *> clients;
    std::vector<publication *> works;
public:
    librarian();
    ~librarian();
    bool lib_order( human *client, publication *work);
    bool lib_get ( human *client, publication *work);
    bool lib_giveback ( human *client, publication *work);
    double lib_check_fee();
};

#endif // LIBRARIAN_H_INCLUDED
