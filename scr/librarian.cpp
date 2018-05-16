#include <iostream>

#include "librarian.h"

using namespace std;

int librarian::amount = 1;

librarian::librarian()
{
    cout << "Librarian number "<< number << " constructor" << endl;
    amount++;
}

librarian::~librarian() {}
bool librarian::lib_order( human *client, publication *work) {}
bool librarian::lib_get ( human *client, publication *work) {}
bool librarian::lib_giveback ( human *client, publication *work){}
double librarian::lib_check_fee() {}
