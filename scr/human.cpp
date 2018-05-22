#include "human.h"
#include "publication.h"
#include <iostream>
#include <vector>
#include <fstream>

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
            double fee_for_book = work->check_fee();
            fee = fee + fee_for_book;
            cout << "dobrze" << endl;
            if ( work->giveback( this ) )
            {
                cout << "dobrze" << endl;
                int i = 0;
                int counter = books_n_magazines.size();
                for ( ; i < counter-1 ; i++ )
                {
                    if ( work == books_n_magazines[i] )
                        break;
                }
                cout << "dobrze" << endl;
                books_n_magazines.erase( books_n_magazines.begin() + i );
                cout << "zle" << endl;
                status.erase( status.begin() + i );
                return fee_for_book;
            }
        }
        else
        {
            return -1.0;
        }
    }
    else
    {
        return -2.0;
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

void human::human_status ( fstream *file )
{
    type ? cout << "Librarian" : cout << "Reader";
    cout << " number " << number;
    cout << "." << endl;
    cout << "He/She wallet is -" << fee << "." << endl;
    int counter_for_owned = 0;
    int counter_for_ordered = 0;
    int statussize = status.size();
    for ( int i = 0 ; i <= (statussize-1) ; i++ )
    {
        if ( status[i] - 1)
            counter_for_ordered++;
        else
            counter_for_owned++;
    }
    cout << "He/She has " << counter_for_owned << " publications in home." << endl;
    cout << "And ordered " << counter_for_ordered << " publications." << endl;
    if ( file )
    {
        type ? *file << "Librarian" : *file << "Reader";
        *file << " number " << number;
        *file << "He/She wallet is -" << fee << "." << endl;
        int counter_for_owned = 0;
        int counter_for_ordered = 0;
        int statussize = status.size();
        for ( int i = 0 ; i <= (statussize-1) ; i++ )
        {
            if ( status[i]-1)
                counter_for_ordered++;
            else
                counter_for_owned++;
        }
        *file << "He/She has " << counter_for_owned << " publications in home." << endl;
        *file << "And ordered " << counter_for_ordered << " publications." << endl;
    }
}

