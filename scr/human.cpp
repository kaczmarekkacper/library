#include "human.h"
#include "publication.h"
#include <iostream>
#include <vector>

using namespace std;

human::human()
{
    fee = 0;
}

human::~human()
{
    if ( !books_n_magazines.size() )
    {
        books_n_magazines.clear();
    }
    if ( !status.size() )
    {
        status.clear();
    }
}

bool human::order( publication *work )
{
    if ( work->isactive() ) // if work is active
    {
        if ( work->order( this ) ) // if publication can be geted
        {
            books_n_magazines.push_back( work );
            status.push_back( 2 );
            return true;
        }
        else // if we cant order it because of something
        {
            return false;
        }
    }
    else // if is active
    {
        return false;
    }
}
bool human::get( publication *work )
{
    if ( !work->isactive() ) // if is active
    {
        if ( work->get( this ) ) // if publication can be geted
        {
            books_n_magazines.push_back( work );
            status.push_back( 1 );
            return true;
        }
        else
        {
            return false;
        }
    }
    else // if isnt active
    {
        return false;
    }

}
double human::giveback( publication *work )
{
    if ( work->isactive() )
    {
        if ( work->check_owner( this ) )
        {
            if ( work->giveback( this ) )
            {
                fee = fee + work->check_fee();
                work->set_fee_as_zero();
                int i = 0;
                for ( ; i < books_n_magazines.size()-1 ; i++ )
                {
                    if ( work == books_n_magazines[i] )
                        break;
                }
                books_n_magazines.erase( books_n_magazines.begin() + i );
                status.erase( status.begin() + i );
                return fee;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
}
double human::check_fee( )
{
    return fee;
}

int human::get_number()
{
    return number;
}
