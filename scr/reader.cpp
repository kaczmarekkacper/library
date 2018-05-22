#include <iostream>

#include "reader.h"

using namespace std;

int reader::amount = 1;

reader::reader()
{
    number = amount;
    type = 1;
    amount++;
}
