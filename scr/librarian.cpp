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
        if ( client->check_ordering( work ) )
            return false;
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
            int clientssize = clients.size();
            for ( ; i < clientssize ; i++ )
            {
                if ( work == works[i] )
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

bool librarian::change_status ( publication *work )
{
    int counter = works.size();
    int i = 0;
    for ( ; i < counter ; i++ )
    {
        if ( work == works[i] )
            break;
    }
    if ( i != counter )
    {
        status[i] = 1;
        return true;
    }
    else
        return false;
}
