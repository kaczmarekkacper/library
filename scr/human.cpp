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
}

bool human::order( publication *work, human *assistant )
{
    if ( assistant->lib_order( this ) ) // obsluga wyjatkow
    {
        assistant->lib_order();
    }
    else
        return 0;

}
bool human::get( publication *work, human *assistant )
{

}
bool human::giveback( publication *work, human *assistant ) {}
double human::check_fee( publication *work, human *assistant ) {}
void human::change_fee ( double extra_fee ) {}
