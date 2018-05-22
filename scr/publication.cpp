#include <iostream>
#include "publication.h"
#include <vector>
#include <random>
#include "librarian.h"

using namespace std;

publication::publication()
{
    position = 0;
    type = 0;
    active = false;
    iterations = 0;
    loops = 0;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 1000);
    fee = ( dist( gen ) / 100.0 );
    owner = nullptr;
    ordered = -1;

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
            ordered = loops + 1;
        else
            ordered = ordered + loops;
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
        if ( check_owner( selected ))
        {
            owner = nullptr;
            iterations = 0;
            active = false;
            int truefalse = ordering.size();
            if ( truefalse )
            {
                ordered = ordered - loops;
                owner = ordering[0];
                active = true;
                ordering.erase ( ordering.begin() );
            }
            else
            {
                ordered = -1;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

double publication::check_fee()
{
    if ( iterations > loops )
        return fee*(iterations - loops);
    else
        return 0.0;
}

int publication::iter()
{
    if ( active )
    {
        if ( iterations >= loops )
        {
            iterations++;
            return 1;
        }
        else
        {
            iterations++;
            return 0;
        }
    }

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

void publication::status( fstream *file )
{
    type-1 ? cout << "Book " : cout <<"Magazine " ;
    cout << "number " << position << endl;
    cout << "This publication is ";
    active ? cout << "active" : cout << "not active";
    cout << " now." << endl;
    cout << "Value of iterations is " << iterations << "." << endl;
    cout << "Fee is " << fee << endl;
    owner ? cout << "It has an owner." : cout << "It doesnt have an owner." ;
    cout << endl;
    cout << "It is ordered for " << ordered << " and the is " << ordering.size() << " people in queue." << endl;
    if ( file )
    {
        type-1 ? *file << "Book " : *file <<"Magazine " ;
        *file << "number " << position << endl;
        *file << "This publication is ";
        active ? *file << "active" : *file << "not active";
        *file << " now." << endl;
        *file << "Value of iterations is " << iterations << "." << endl;
        *file << "Fee is " << fee << endl;
        owner ? *file << "It has an owner." : *file << "It doesnt have an owner." ;
        *file << endl;
        *file << "It is ordered for " << ordered << " and the is " << ordering.size() << " people in queue." << endl;
    }
}

bool publication::statusqueue()
{
    if ( ordering.size() )
        return true;
    else
        return false;
}

int publication::get_position()
{
    return position;
}

void publication::whats_your_name( fstream *file )
{
    type-1 ? cout << "book" : cout << "magazine" ;
    if ( file )
    {
        type-1 ? *file << "book" : *file << "magazine" ;
        *file << " number " << position << " ";
    }
    cout << " number " << position << " ";
}

