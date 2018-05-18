#include "human.h"
#include "publication.h"
#include <iostream>
#include <vector>

using namespace std;

human::human()
{
    cout << "Human number " << number << "constructor." << endl;
    fee = 0;
    cout << "Fee is " << fee << "." ;
    cout << "End of constructor human number " << number << "." << endl;
}

human::~human()
{
    cout << "Human number" << number << "desctructor." << endl;
    if ( !books_n_magazines.size() )
    {
        books_n_magazines.clear();
        cout << "Clearing books_n_magazines." << endl;
    }
    if ( !status.size() )
    {
        status.clear();
        cout << "Clearing status." << endl;
    }
    cout << "End of destructor human number " << number << endl;
}

bool human::order( publication *work )
{
    cout << "Human number " << number << "order function." << endl;
    if ( work->isactive() ) // if work is active
    {
        {
            if ( work->order( this ) ) // if publication can be geted
            {
                books_n_magazines.push_back( work );
                status.push_back( 2 );
                cout << "Push back work to booksnmagazines with status ordered in human " << number << "." << endl;
                cout << "End of human " << number << "order function." << endl;
                return true;
            }
            else // if we cant order it because of something
            {
                cout << "Cannot order.";
                cout << "End of human " << number << "order function." << endl;
                return false;
            }
        }

    }
    else // if is active
    {
        cout << "Book number " << number <<" isnt active" << endl;
        cout << "End of human " << number << "order function." << endl;
        return false;
    }
}
bool human::get( publication *work )
{
    cout << "Human number " << number << "get function." << endl;
    if ( work->isactive() ) // if is active
    {
        {
            if ( work->get( this ) ) // if publication can be geted
            {
                books_n_magazines.push_back( work );
                status.push_back( 1 );
                cout << "End of human " << number << "get function." << endl;
                return true;
            }
            else
            {
                cout << "End of human " << number << "get function." << endl;
                return false;
            }
        }
    }
    else // if isnt active
    {
        cout << "End of human " << number << "get function." << endl;
        return false;
    }

}
bool human::giveback( publication *work )
{
    cout << "Human number " << number << "giveback function." << endl;
    if ( work->isactive() )
    {
        if ( work->check_owner( this ) )
        {
            cout << "Human number " << number << " gives back a publication." << endl ;
            fee = fee + work->check_fee();
            int i = 0;
            for ( ; i < books_n_magazines.size()-1 ; i++ )
            {
                if ( work == books_n_magazines[i] )
                    break;
            }
            books_n_magazines.erase( books_n_magazines.begin() + i );
            status.erase( status.begin() + i );
            cout << "End of human " << number << "giveback function." << endl;
            return true;
        }
        else
        {
            cout << "Publication isnt yours." << endl;
            cout << "End of human " << number << "iveback function." << endl;
        }
            return false;
    }
    else
    {
        cout << "Publication isnt active." << endl;
        cout << "End of human " << number << "giveback function." << endl;
        return false;
    }
}
double human::check_fee( )
{
    cout << "End of human " << number << "check_fee function." << endl;
    return fee;
}

