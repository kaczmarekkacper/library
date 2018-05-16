
#include <iostream>
#include "publication.h"
#include <vector>

using namespace std;

publication::publication()
{

}

publication::~publication()
{
    if ( !ordering.size() )
        ordering.clear();
}

bool publication::order( human *selected )
{
    if ( !active ) // obs³uga wyj¹tków
    {
        return false;
    }
    else
    {
        if ( ordered = -1 )
            ordered = time + 1;
        else
            ordered = ordered + time;
        ordering.push_back( selected );
        return true;
    }
}
bool publication::get( human *selected )
{
    if ( !active )
    {
        owner = selected;
        active = true;
        return true;
    }
    else // oblusga wykatkow
    {
        cout << "Cannot get a book because its active, you will order it as well." << endl;
        if ( order ( selected ) )
            return true;
        else
            return false;
    }
}

bool publication::giveback( human *selected )
{
    if ( !active )
    {
        // oblusga wyjatkow
    }
    else
    {
        active = 0;
        if ( iterations > time )
        {
            selected->change_fee( fee*iterations );
            cout << "Too many iterations" << endl;
        }
        iterations = 0;
        owner = nullptr;
        if ( !ordering.size() )
        {
            owner = ordering[1];
            ordering.erase( ordering.begin() );
            get ( owner );
        }
        else
            ordered = -1;

    }
}

double publication::check_fee()
{
    return fee;
}

void publication::iter()
{
    iterations++;
}

bool publication::isactive()
{
    return active;
}
