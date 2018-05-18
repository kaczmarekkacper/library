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
        cout << "reader vector" << endl;
    }

    for ( int i= 0; i < hml ; i++ )
    {
        vec_of_librarians.push_back( librarian() );
        cout << "librarian vector" << endl;
    }

    for ( int i= 0; i < (hmb+hmm) ; i++ )
    {
        vec_of_publications.push_back( book() );
        vec_of_publications.push_back( magazine() );
        cout << "publication vector" << endl;
    }

    for (int i = 0 ; i < hmloops ; i++)
    {
        for (int j = 0 ; j < hmloops/2 ; j++)
        {
            if ( rdnumber(0, 1) ) // reader's operations ( rd is 1)
            {
                long option = rdnumber(1, 4);
                int which_one_reader = rdnumber( 0, vec_of_readers.size()-1);
                int which_one_publication = rdnumber( 0, vec_of_publications.size()-1);
                int librarian = rdnumber ( 0, vec_of_librarians.size()-1);
                switch ( option )
                {
                case 1:
                    vec_of_readers[which_one_reader].order( &vec_of_publications[which_one_publication]);
                    cout << "order reader" << endl;
                    break;
                case 2:
                    vec_of_readers[which_one_reader].get( &vec_of_publications[which_one_publication]);
                    cout << "get reader" << endl;
                    break;
                case 3:
                    vec_of_readers[which_one_reader].giveback( &vec_of_publications[which_one_publication]);
                    cout << "giveback reader" << endl;
                    break;
                case 4:
                    vec_of_readers[which_one_reader].check_fee();
                    cout << "check fee reader" << endl;
                    break;
                default:
                    cout << "Reader nr " << which_one_reader << " does nothing." << endl;
                break;
                };
            Sleep(1000);
            }
            else
            {
                long option = rdnumber(1, 4);
                int which_one_librarian = rdnumber( 0, vec_of_librarians.size()-1);
                int which_one_publication = rdnumber( 0, vec_of_publications.size()-1);
                int librarian = rdnumber ( 0, vec_of_librarians.size()-1);
                switch ( option )
                {
                case 1:
                    vec_of_librarians[which_one_librarian].order( &vec_of_publications[which_one_publication]);
                    cout << "order librarian" << endl;
                    break;
                case 2:
                    vec_of_librarians[which_one_librarian].get( &vec_of_publications[which_one_publication]);
                    break;
                case 3:
                    vec_of_librarians[which_one_librarian].giveback( &vec_of_publications[which_one_publication]);
                    break;
                case 4:
                    vec_of_librarians[which_one_librarian].check_fee();
                    break;
                default:
                    cout << "Librarian nr " << which_one_librarian << " does nothing." << endl;
                break;
                };
            Sleep(1000);
            }
            }

        /*
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
        */
    }
}

test_for_library::~test_for_library()
{
    vec_of_readers.clear();
    vec_of_librarians.clear();
    vec_of_publications.clear();
}

long test_for_library::rdnumber(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a, b);
    long number =  dist( gen );
    return number;
}
