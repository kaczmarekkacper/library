#include <iostream>

#include "librarian.h"

using namespace std;

int librarian::amount = 1;

librarian::librarian()
{
    number = amount;
    type = 0;
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
    if ( work->isactive() )
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
    if ( !work->isactive() )
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
    if ( work->isactive() )
    {
        if ( work->check_owner( client ) )
        {
            int i = 0;
            for ( ; i < clients.size()-1 ; i++ )
            {
                if ( work == books_n_magazines[i] )
                    break;
            }
            clients.erase( clients.begin() + i );
            works.erase( works.begin() + i );
            status.erase( status.begin() + i );
            return true;
        }
        else
            return false;
    }
    else
        return false;
}
