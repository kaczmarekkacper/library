#include <iostream>

#include "librarian.h"

using namespace std;

int librarian::amount = 1;

librarian::librarian(): number(amount)
{
    cout << "Librarian number "<< number << " constructor" << endl;
    amount++;
}

bool librarian::lend()
{
    cout << "Librarian number "<< number << " lend function" << endl;
    return true;
}

bool librarian::giveback()
{
    cout << "Librarian number "<< number << " giveback function" << endl;
    return true;
}

bool librarian::order()
{
    cout << "Librarian number "<< number << " order function" << endl;
    return true;
}

double librarian::check_fee()
{
    cout << "Librarian number "<< number << " check_fee function" << endl;
    return 1.5;
}
