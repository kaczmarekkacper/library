#include <iostream>
#include <vector>
#include <random>

#include "test_for_library.h"

using namespace std;

test_for_library::test_for_library( int hmr, int hml, int hmb, int hmm, int hmloops)
{
    for ( int i= 0; i < hmr ; i++ )
    {
        vec_of_readers.push_back( reader() );
    }
    for ( int i= 0; i < hml ; i++ )
    {
        vec_of_librarians.push_back( librarian() );
    }
    for ( int i= 0; i < hmb ; i++ )
    {
        vec_of_books.push_back( book() );
    }
    for ( int i= 0; i < hmm ; i++ )
    {
        vec_of_magazines.push_back( magazine() );
    }
    for (int i = 0 ; i < hmloops ; i++)
    {
        for (int i = 0 ; i < vec_of_readers.size() ; i++)
        {
            long option = rdnumber(1, 5);
            switch (option)
            {
            case 1:
                vec_of_readers[i].lend();
                break;
            case 2:
                vec_of_readers[i].giveback();
                break;
            case 3:
                vec_of_readers[i].order();
                break;
            case 4:
                vec_of_readers[i].pay_fee();
                break;
            default:
                cout << "Nothing to do." << endl;
                break;
            };
        }
    }
}

test_for_library::~test_for_library()
{
    vec_of_readers.clear();
    vec_of_librarians.clear();
    vec_of_books.clear();
    vec_of_magazines.clear();
    delete this;
}

long test_for_library::rdnumber(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    long number =  dist( gen );
    return number;
}
