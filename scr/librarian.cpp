
#include "librarian.h"

int librarian::amount = 1;

librarian::librarian(): number(amount)
{
    amount++;
}

librarian::~librarian()
{
    delete this;
}

bool librarian::lend()
{
    return true;
}

bool librarian::give_back()
{
    return true;
}

bool librarian::order()
{
    return true;
}

double librarian::check_fee()
{
    return 1.5;
}
