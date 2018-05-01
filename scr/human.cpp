
#include "human.h"

human::~human()
{
    delete this;
}

bool human::lend()
{
    return true;
}

bool human::give_back()
{
    return true;
}

bool human::order()
{
    return true;
}
