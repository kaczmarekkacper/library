#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <windows.h>

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
        long option = rdnumber(1, 5);
        int which_one = rdnumber(0, hmr-1);
        switch (option)
        {
        case 1:
            vec_of_readers[which_one].lend();
            break;
        case 2:
            vec_of_readers[which_one].giveback();
            break;
        case 3:
            vec_of_readers[which_one].order();
            break;
        case 4:
            vec_of_readers[which_one].pay_fee();
            break;
        default:
            cout << "Nothing to do." << endl;
            break;
        };
        Sleep(1000);

        option = rdnumber(1, 5);
        which_one = rdnumber(0, hml-1);
        switch (option)
        {
        case 1:
            vec_of_librarians[which_one].lend();
            break;
        case 2:
            vec_of_librarians[which_one].giveback();
            break;
        case 3:
            vec_of_librarians[which_one].order();
            break;
        case 4:
            vec_of_librarians[which_one].check_fee();
            break;
        default:
            cout << "Nothing to do." << endl;
            break;
        };
        Sleep(1000);

        option = rdnumber(1, 5);
        which_one = rdnumber(0, hmb-1);
        switch (option)
        {
        case 1:
            vec_of_books[which_one].get();
            break;
        case 2:
            vec_of_books[which_one].giveback();
            break;
        case 3:
            vec_of_books[which_one].order();
            break;
        case 4:
            vec_of_books[which_one].check_fee();
            break;
        default:
            cout << "Nothing to do." << endl;
            break;
        };
        Sleep(1000);

        option = rdnumber(1, 5);
        which_one = rdnumber(0, hmm-1);
        switch (option)
        {
        case 1:
            vec_of_magazines[which_one].get();
            break;
        case 2:
            vec_of_magazines[which_one].giveback();
            break;
        case 3:
            vec_of_magazines[which_one].order();
            break;
        case 4:
            vec_of_magazines[which_one].check_fee();
            break;
        default:
            cout << "Nothing to do." << endl;
            break;
            };
        Sleep(1000);
    }
}

test_for_library::~test_for_library()
{
    vec_of_readers.clear();
    vec_of_librarians.clear();
    vec_of_books.clear();
    vec_of_magazines.clear();
}

long test_for_library::rdnumber(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    long number =  dist( gen );
    return number;
}
