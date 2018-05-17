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
    if ( !status.size() )
        status.clear();
}

bool librarian::lib_order( human *client, publication *work)
{
    if ( !work->isactive() )
    {
        clients.push_back( client );
        works.push_back( work );
        status.push_back ( 2 );
        return true;
    }
    else
    {
        return false;
    }
}
bool librarian::lib_get ( human *client, publication *work)
{
    if ( work->isactive() )
    {
        clients.push_back( client );
        works.push_back( work );
        status.push_back ( 1 );
        return true;
    }
    else
    {
        return false;
    }

}
bool librarian::lib_giveback ( human *client, publication *work)
{

}
