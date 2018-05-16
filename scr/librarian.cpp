#include <iostream>

#include "librarian.h"

using namespace std;

int librarian::amount = 1;

librarian::librarian()
{
    number = amount;
    amount++;
}

librarian::~librarian()
{
    if ( !clients.size() )
        clients.clear();
    if ( !works.size() )
        works.clear();
}

bool librarian::lib_order( human *client, publication *work)
{

}
bool librarian::lib_get ( human *client, publication *work)
{
    if ( work->isactive() )

}
bool librarian::lib_giveback ( human *client, publication *work){}
double librarian::lib_check_fee() {}
