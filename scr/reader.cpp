
#include "reader.h"

int reader::amount = 1;

reader::reader(): number(amount)
{
    amount++;
    fee = 0.0;

}

reader::~reader()
{
    delete this;
}

bool reader::lend()
{
    return true;
}

bool reader::give_back()
{
    return true;
}

bool reader::order()
{
    return true;
}

bool reader::pay_fee()
{
    return true;
}
