
#include "librarian.h"

int librarian::amount = 1;

librarian::librarian()
{
    amount++;
}

librarian::~librarian()
{
    delete this;
}

virtual bool librarian::lend()
{
    return true;
}

virtual bool librarian::give_back()
{
    return true;
}

virtual bool librarian::order()
{
    return true;
}

double librarian::check_fee()
{
    return 1.5;
}
