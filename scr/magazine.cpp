
#include <random>
#include "magazine.h"

int magazine::amount = 1;
double magazine::fee = 2.0;
int magazine::time = 4;

magazine::magazine()
{
    amount++;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(5, 20);
    amount_of_articles =  dist( gen );
}

magazine::~magazine()
{
    delete this;
}

virtual bool magazine::order()
{
    return true;
}

virtual bool magazine::get()
{
    return true;
}

virtual bool magazine::giveback()
{
    return true;
}

virtual double magazine::check_fee()
{
    return fee;
}
