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

bool human::order( publication *work, human *assistant )
{
    if ( work->isactive() ) // if work is active
    {
        if ( !assistant->lib_order ( this, work ) ) // if librarian cant get a book for reader
            return false;
        else // if he can
        {
            if ( !work->order( this ) ) // if publication cant be geted
            {
                return false;
            }
            else // if everything is ok and human can get a publication
            {
                books_n_magazines.push_back( work );
                return true;
            }
        }
    }
    else // if is active
    {

    }
}
bool human::get( publication *work, human *assistant )
{
    if ( !work->isactive() ) // if isnt active
    {
        return false;
    }
    else // if is active
    {
        if ( !assistant->lib_get ( this, work ) ) // if librarian cant get a book for reader
            return false;
        else // if he can
        {
            if ( !work->get( this ) ) // if publication cant be geted
            {
                return false;
            }
            else // if everything is ok and human can get a publication
            {
                books_n_magazines.push_back( work );
                return true;
            }
        }
    }

}
bool human::giveback( publication *work, human *assistant )
{

}
double human::check_fee( )
{
    return fee;
}
void human::change_fee ( double extra_fee )
{

}
