#include <iostream>

#include "reader.h"

using namespace std;

int reader::amount = 1;

reader::reader(): number(amount)
{
    cout << "Reader number "<< number << " constructor" << endl;
    amount++;
    fee = 2.0;
}

bool reader::lend()
{
    cout << "Reader number "<< number << " lend function" << endl;
    return true;
}

bool reader::giveback()
{
    cout << "Reader number "<< number << " giveback function" << endl;
    return true;
}

bool reader::order()
{
    cout << "Reader number "<< number << " order function" << endl;
    return true;
}

bool reader::pay_fee()
{
    cout << "Reader number "<< number << " pay_fee function" << endl;
    return true;
}
