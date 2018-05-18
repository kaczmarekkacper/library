
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
    if ( active ) // obs³uga wyj¹tków
    {
        if ( ordered = -1 )
            ordered = time + 1;
        else
            ordered = ordered + time;
        ordering.push_back( selected );
        return true;
    }
    else
    {
        return false;
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
        return false;
    }
}

bool publication::giveback( human *selected )
{
    if ( active )
    {
        owner = nullptr;
        iterations = 0;

    }
    else
    {
    }
}

double publication::check_fee()
{
    if ( iterations > time )
        return fee*iterations;
    else
        return 0.0;
}

void publication::iter()
{
    iterations++;
}

bool publication::isactive()
{
    return active;
}

bool publication::check_owner( human *client )
{
    if ( client == owner )
        return true;
    else
        return false;
}
