
#include <random>

#include "magazine.h"

int magazine::amount = 1;
double magazine::fee = 2.0;
int magazine::time = 4;

using namespace std;

magazine::magazine()
{
    position = amount;
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

bool magazine::order()
{
    return true;
}

bool magazine::get()
{
    return true;
}

bool magazine::giveback()
{
    return true;
}

double magazine::check_fee()
{
    return fee;
}
