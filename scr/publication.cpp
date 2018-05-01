
#include "publication.h"

publication::publication()
{

}

publication::~publication()
{
    delete this;
}

bool publication::order()
{
    return true;
}

bool publication::get()
{
    return true;
}

bool publication::giveback()
{
    return true;
}

double publication::check_fee()
{
    return 1.5;
}
