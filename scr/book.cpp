
#include <random>
#include "book.h"

using namespace std;

int book::amount = 1;
double book::fee = 1.5;
int book::time = 3;

book::book( )
{
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

virtual bool book::order()
{
    return true;
}

virtual bool book::get()
{
    return true;
}

virtual bool book::giveback()
{
    return true;
}

virtual double book::check_fee()
{
    return fee;
}
