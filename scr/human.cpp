
#include "human.h"

human::~human()
{
    delete this;
}

virtual bool human::lend()
{
    return true;
}

virtual bool human::give_back()
{
    return true;
}

virtual bool human::order()
{
    return true;
}
