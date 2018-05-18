#include <iostream>
#include <random>
#include <vector>

#include "book.h"

using namespace std;

int book::amount = 1;
int book::time = 3;

book::book()
{
    position = amount;
    amount++;
    type = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 1000);
    pages =  dist( gen );
}
