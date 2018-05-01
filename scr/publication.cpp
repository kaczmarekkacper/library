
#include "publication.h"

publication::publication()
{

}

publication::~publication()
{
    return this;
}

virtual bool publication::order()
{
    return true;
}

virtual bool publication::get()
{
    return true;
}

virtual bool publication::giveback()
{
    return true;
}

virtual double publication::check_fee()
{
    return 1.5;
}
