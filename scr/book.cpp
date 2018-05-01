
#include <random>
#include "book.h"

using namespace std;

int book::amount = 1;
double book::fee = 1.5;
int book::time = 3;

book::book()
{
    position = amount;
    active = true;
    iterations = 0;
    amount++;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(20, 500);
    pages = dist( gen );
}

book::~book()
{
    delete this;
}

bool book::order()
{
    return true;
}

bool book::get()
{
    return true;
}

bool book::giveback()
{
    return true;
}

double book::check_fee()
{
    return fee;
}
