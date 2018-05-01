#include <iostream>
#include <random>

#include "book.h"

using namespace std;

int book::amount = 1;
double book::fee = 1.5;
int book::time = 3;

book::book()
{
    cout << "Book numer " << amount << " constructor" << endl;
    position = amount;
    active = true;
    iterations = 0;
    amount++;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(20, 500);
    pages = dist( gen );

}

bool book::order()
{
    cout << "Book number " << position << " order function" << endl;
    return true;
}

bool book::get()
{
    cout << "Book number " << position << " get function" << endl;
    return true;
}

bool book::giveback()
{
    cout << "Book number " << position << " giveback function" << endl;
    return true;
}

double book::check_fee()
{
    cout << "Book number " << position << " check_fee function" << endl;
    return fee;
}
