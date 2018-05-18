#include <iostream>
#include <random>

#include "magazine.h"

int magazine::amount = 1;
int magazine::time = 4;

using namespace std;

magazine::magazine()
{
    position = amount;
    amount++;
    type = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 1000);
    amount_of_articles =  dist( gen );
}
