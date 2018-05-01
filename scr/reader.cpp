
#include "reader.h"

int reader::amount = 1;

reader::reader()
{
    amount++;
    fee = 0.0;

}

reader::~reader()
{
    delete this;
}

virtual bool reader::lend()
{
    return true;
}

virtual bool reader::give_back()
{
    return true;
}

virtual bool reader::order()
{
    return true;
}

bool reader::pay_fee()
{
    return true;
}
