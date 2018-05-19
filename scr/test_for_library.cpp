#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <windows.h>

#include "test_for_library.h"

using namespace std;

test_for_library::test_for_library( int hmr, int hml, int hmb, int hmm, int hmloops)
{
    double fee;
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
                int wor = rdnumber( 0, vec_of_readers.size()-1);
                // wor - which one reader
                int wop = rdnumber( 0, vec_of_publications.size()-1);
                // wop - which one publication
                int wol = rdnumber ( 0, vec_of_librarians.size()-1);
                // wol - which one librarian
                switch ( option )
                {
                case 1:
                    if ( vec_of_librarians[wol].lib_order( &vec_of_readers[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol << " ordered a book for reader " << wor << endl;
                        if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << wor << " ordered a publication." << endl;
                        }
                        else
                        {
                            cout << "Something gone wrong very very very" << endl;
                        }
                    }
                    else
                    {
                        cout << "Reader number " << wor << " cant order a publication because it is active." << endl;
                        cout << "So reader " << wor << "is going to get a book." << endl;
                        if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol << " getted a book for reader " << wor << endl;
                            if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << wor << " getted a publication." << endl;
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant order an even get a publicatiin" << endl;
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol << " getted a book for reader " << wor << endl;
                        if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << wor << " getted a publication." << endl;
                        }
                        else
                        {
                            cout << "Something gone wrong very very very." << endl;
                        }
                    }
                    else
                    {
                        cout << "Reader number " << wor << " cant getted a publication because it is not active." << endl;
                        cout << "So reader " << wor << "is going to order a book." << endl;
                        if ( vec_of_librarians[wol].lib_order( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol << " ordered a book for reader " << wor << endl;
                            if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << wor << " ordered a publication." << endl;
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant get an even order a publicatiin" << endl;
                            }
                        }
                    }
                    break;
                case 3:
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_readers[wor], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << wol << " set publication as givebacked." << endl;
                        fee = vec_of_readers[wor].giveback( &vec_of_publications[wop]);
                        if ( fee = -2 )
                        {
                            cout << "Publication isnt even active " << endl;
                        }
                        else if ( fee = -1 )
                        {
                            cout << "Publication isnt belong to this reader number " << wor << "." << endl;
                        }
                        else if ( fee = 0.0)
                        {
                            cout << "Reader number " << wor << " doesnt need to pay a fee." << endl;
                        }
                        else
                        {
                            cout << "Reader " << wor << " need to pay " << fee << endl;
                        }
                    }
                    break;
                case 4:
                    cout << "Reader number " << wor << "want to check his fee." << endl;
                    cout << "Reader number " << wor << " need to pay " << vec_of_readers[wor].check_fee() << "at all.";
                    break;
                default:
                    cout << "Reader nr " << wor << " does nothing." << endl;
                break;
                };
            }
            else
            {
                long option = rdnumber(1, 4);
                int worl = rdnumber( 0, vec_of_readers.size()-1);
                // worl - which one reader but a librarian xd
                int wop = rdnumber( 0, vec_of_publications.size()-1);
                // wop - which one publication
                int wol = rdnumber ( 0, vec_of_librarians.size()-1);
                // wol - which one librarian
                switch ( option )
                {
                case 1:
                    if ( vec_of_librarians[wol].lib_order( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol << " ordered a book for librarianreader " << worl << endl;
                        if ( vec_of_librarians[worl].order( &vec_of_publications[wop]) )
                        {
                            cout << "Librarianreader number " << worl << " ordered a publication." << endl;
                        }
                        else
                        {
                            cout << "Something gone wrong very very very" << endl;
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << worl << " cant order a publication because it is active." << endl;
                        cout << "So Librarianreader " << worl << "is going to get a book." << endl;
                        if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol << " getted a book for librarianreader " << worl << endl;
                            if ( vec_of_librarians[worl].get( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << worl << " getted a publication." << endl;
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant order an even get a publicatiin" << endl;
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol << " getted a book for librarianreader " << worl << endl;
                        if ( vec_of_librarians[worl].get( &vec_of_publications[wop]) )
                        {
                            cout << "LibrarianReader number " << worl << " getted a publication." << endl;
                        }
                        else
                        {
                            cout << "Something gone wrong very very very." << endl;
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << worl << " cant getted a publication because it is not active." << endl;
                        cout << "So librarianreader " << worl << "is going to order a book." << endl;
                        if ( vec_of_librarians[wol].lib_order( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol << " ordered a book for librarianreader " << worl << endl;
                            if ( vec_of_librarians[worl].order( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << worl << " ordered a publication." << endl;
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant get an even order a publicatiin" << endl;
                            }
                        }
                    }
                    break;
                case 3:
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_librarians[worl], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << wol << " set publication as givebacked." << endl;
                        fee = vec_of_librarians[worl].giveback( &vec_of_publications[wop]);
                        if ( fee = -2 )
                        {
                            cout << "Publication isnt even active " << endl;
                        }
                        else if ( fee = -1 )
                        {
                            cout << "Publication isnt belong to this reader number " << worl << "." << endl;
                        }
                        else if ( fee = 0.0)
                        {
                            cout << "LibrarianReader number " << worl << " doesnt need to pay a fee." << endl;
                        }
                        else
                        {
                            cout << "LibrarianReader " << worl << " need to pay " << fee << endl;
                        }
                    }
                    break;
                case 4:
                    cout << "LibrarianReader number " << worl << "want to check his fee." << endl;
                    cout << "LibrarianReader number " << worl << " need to pay " << vec_of_librarians[worl].check_fee() << "at all.";
                    break;
                default:
                    cout << "LibrarianReader nr " << worl << " does nothing." << endl;
                break;
                };
            }
            cout << endl;
            Sleep(1000);
        }
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
