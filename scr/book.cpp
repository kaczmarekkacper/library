#include <iostream>
#include <random>
#include <vector>

#include "book.h"

using namespace std;

int book::amount = 1;
int book::time = 3;

book::book()
{
    cout << "Book constructor." << endl;
    position = amount;
    cout << "Postion set as " << amount << "." << endl;
    amount++;
    type = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(10, 1000);
    pages =  dist( gen );
    loops = time;
    cout << "It has " << pages << "pages." << endl;
}
