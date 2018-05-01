#include <iostream>
#include <random>

#include "magazine.h"

int magazine::amount = 1;
double magazine::fee = 2.0;
int magazine::time = 4;

using namespace std;

magazine::magazine()
{
    position = amount;
    cout << "Magazine number" << position << " constructor" << endl;
    amount++;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(5, 20);
    amount_of_articles =  dist( gen );
}

bool magazine::order()
{
    cout << "Magazine number" << position << " order function" << endl;
    return true;
}

bool magazine::get()
{
    cout << "Magazine number" << position << " get function" << endl;
    return true;
}

bool magazine::giveback()
{
    cout << "Magazine number" << position << " giveback function" << endl;
    return true;
}

double magazine::check_fee()
{
    cout << "Magazine number" << position << " check_fee function" << endl;
    return fee;
}
