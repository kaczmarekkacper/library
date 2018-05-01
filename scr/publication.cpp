#include <iostream>

#include "publication.h"

using namespace std;

publication::publication()
{
    cout << "Publication constructor" << endl;
}

bool publication::order()
{
    cout << "Publication order function" << endl;
    return true;
}

bool publication::get()
{
    cout << "Publication order function" << endl;
    return true;
}

bool publication::giveback()
{
    cout << "Publication order function" << endl;
    return true;
}

double publication::check_fee()
{
    cout << "Publication order function" << endl;
    return 1.5;
}
