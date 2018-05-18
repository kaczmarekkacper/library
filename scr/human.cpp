#include "human.h"
#include "publication.h"
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
        {
            if ( work->order( this ) ) // if publication can be geted
            {
                books_n_magazines.push_back( work );
                return true;
            }
            else // if we cant order it because of something
            {
                return false;
            }
        }
    }
    else // if is active
    {
        return false;
    }
}
bool human::get( publication *work )
{
    if ( work->isactive() ) // if is active
    {
        {
            if ( work->get( this ) ) // if publication can be geted
            {
                books_n_magazines.push_back( work );
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else // if isnt active
    {
        return false;
    }

}
bool human::giveback( publication *work )
{
    if ( work->isactive() )
    {
        if ( work->check_owner( this ) )
        {
            fee = fee + work->check_fee();
            int i = 0;
            for ( ; i < books_n_magazines.size() ; i++ )
            {
                if ( work == books_n_magazines[i] )
                    break;
            }
            books_n_magazines.erase( books_n_magazines.begin() + i );
            status.erase( status.begin() + i );
            return true;
        }
        else
            return false;
    }
    else
    {
        return false;
    }
}
double human::check_fee( )
{
    return fee;
}

