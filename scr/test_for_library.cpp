#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <windows.h>

#include "test_for_library.h"

using namespace std;

test_for_library::test_for_library( int hmr, int hml, int hmb, int hmm, int hmloops)
{
    cout << "Start test function" << endl;
    double fee;
    for ( int i= 0; i < hmr ; i++ )
    {
        vec_of_readers.push_back( reader() );
    }

    for ( int i= 0; i < hml ; i++ )
    {
        vec_of_librarians.push_back( librarian() );
    }

    for ( int i= 0; i < (hmb+hmm) ; i++ )
    {
        vec_of_publications.push_back( book() );
        vec_of_publications.push_back( magazine() );
    }

    for ( int i= 0; i < (hmb+hmm) ; i++ )
    {
        vec_of_publications[i].status();
        cout << endl;
    }

    for (int i = 0 ; i < hmloops ; i++)
    {
        for (int j = 0 ; j < hmloops/2 ; j++)
        {
            cout << "New loop." << endl;
            if ( rdnumber(0, 1) ) // reader's operations ( rd is 1)
            {
                long option = rdnumber(1, 5);
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
                        cout << "Librarian " << wol+1 << " ordered a book for reader " << wor << endl;
                        Sleep(1000);
                        if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << wor+1 << " ordered a publication." << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Something gone wrong very very very" << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "Reader number " << wor+1 << " cant order a publication because it isnt active." << endl;
                        Sleep(1000);
                        cout << "So reader " << wor+1 << " is going to get a book." << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol+1 << " getted a book for reader " << wor+1 << endl;
                            Sleep(1000);
                            if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << wor+1 << " getted a publication." << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant order an even get a publication" << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol+1 << " getted a book for reader " << wor+1 << endl;
                        Sleep(1000);
                        if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << wor+1 << " getted a publication." << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Something gone wrong very very very." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "Reader number " << wor+1 << " cant getted a publication because it is active." << endl;
                        Sleep(1000);
                        cout << "So reader " << wor+1 << " is going to order a book." << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_order( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol+1 << " ordered a book for reader " << wor+1 << endl;
                            Sleep(1000);
                            if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << wor+1 << " ordered a publication." << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant get an even order a publicatiin" << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 3:
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_readers[wor], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << wol+1 << " set publication as givebacked." << endl;
                        Sleep(1000);

                    }
                    else
                    {
                            cout << "Librarian number " << wol+1 << " cant set publication as givebacked." << endl;
                    }
                    fee = vec_of_readers[wor].giveback( &vec_of_publications[wop]);
                    if ( fee = -2 )
                    {
                        cout << "Publication isnt even active " << endl;
                        Sleep(1000);
                    }
                    else if ( fee = -1 )
                    {
                        cout << "Publication isnt belong to this reader number " << wor+1 << "." << endl;
                        Sleep(1000);
                    }
                    else if ( fee = 0.0)
                    {
                        cout << "Reader number " << wor+1 << " doesnt need to pay a fee." << endl;
                        Sleep(1000);
                    }
                    else
                    {
                        cout << "Reader " << wor+1 << " need to pay " << fee << endl;
                        Sleep(1000);
                    }
                    break;
                case 4:
                    cout << "Reader number " << wor+1 << " want to check his fee." << endl;
                    Sleep(1000);
                    cout << "Reader number " << wor+1 << " need to pay " << vec_of_readers[wor].check_fee() << " at all." << endl;
                    Sleep(1000);
                    break;
                default:
                    cout << "Reader nr " << wor+1 << " does nothing." << endl;
                    Sleep(1000);
                break;
                };
                for ( int i = 0; i < vec_of_publications.size()-1 ; i++ )
                {
                    int option;
                    if ( option = vec_of_publications[i].iter() )
                    {
                        if ( option == 1 )
                        {
                            for ( int j = 0 ; j < vec_of_readers.size()-1 ; j++ )
                            {
                                if ( vec_of_publications[i].check_owner( &vec_of_readers[j] ) )
                                {
                                    cout << "Reader number " << vec_of_readers[j].get_number() << " should return the publication number " << vec_of_publications[i].get_position() << endl;
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                }
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
                        cout << "Librarian " << wol+1 << " ordered a book for librarianreader " << worl+1 << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[worl].order( &vec_of_publications[wop]) )
                        {
                            cout << "Librarianreader number " << worl+1 << " ordered a publication." << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Something gone wrong very very very" << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << worl+1 << " cant order a publication because it isnt active." << endl;
                        Sleep(1000);
                        cout << "So Librarianreader " << worl+1 << " is going to get a book." << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol+1 << " getted a book for librarianreader " << worl+1 << endl;
                            Sleep(1000);
                            if ( vec_of_librarians[worl].get( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << worl+1 << " getted a publication." << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant order an even get a publicatiin" << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << wol+1 << " getted a book for librarianreader " << worl+1 << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[worl].get( &vec_of_publications[wop]) )
                        {
                            cout << "LibrarianReader number " << worl+1 << " getted a publication." << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Something gone wrong very very very." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << worl+1 << " cant getted a publication because it is active." << endl;
                        Sleep(1000);
                        cout << "So librarianreader " << worl+1 << " is going to order a book." << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_order( &vec_of_librarians[worl], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << wol+1 << " ordered a book for librarianreader " << worl+1 << endl;
                            Sleep(1000);
                            if ( vec_of_librarians[worl].order( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << worl+1 << " ordered a publication." << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Something gone wrong very very very he cant get an even order a publicatiin" << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 3:
                    cout << "Librarianreader number " << worl+1 << " want to return a book." << endl;
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_librarians[worl], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << wol+1 << " set publication as givebacked." << endl;
                        Sleep(1000);

                    }
                    else
                    {
                        cout << "Librarian number " << wol+1 << " cant set publication as givebacked." << endl;
                    }
                    fee = vec_of_librarians[worl].giveback( &vec_of_publications[wop]);
                    if ( fee = -2 )
                    {
                        cout << "Publication isnt even active." << endl;
                        Sleep(1000);
                    }
                    else if ( fee = -1 )
                    {
                        cout << "Publication isnt belong to this reader number " << worl+1 << "." << endl;
                        Sleep(1000);
                    }
                    else if ( fee = 0.0)
                    {
                        cout << "LibrarianReader number " << worl+1 << " doesnt need to pay a fee." << endl;
                        Sleep(1000);
                    }
                    else
                    {
                        cout << "LibrarianReader " << worl+1 << " need to pay " << fee << endl;
                        Sleep(1000);
                    }
                    break;
                case 4:
                    cout << "LibrarianReader number " << worl+1 << " want to check his fee." << endl;
                    Sleep(1000);
                    cout << "LibrarianReader number " << worl+1 << " need to pay " << vec_of_librarians[worl].check_fee() << " at all." << endl;
                    Sleep(1000);
                    break;
                default:
                    cout << "LibrarianReader nr " << worl+1 << " does nothing." << endl;
                    Sleep(1000);
                break;
                };
                for ( int i = 0; i < vec_of_publications.size()-1 ; i++ )
                {
                    int option;
                    if ( option = vec_of_publications[i].iter() )
                    {
                        if ( option == 1 )
                        {
                            for ( int j = 0 ; j < vec_of_librarians.size()-1 ; j++ )
                            {
                                if ( vec_of_publications[i].check_owner( &vec_of_librarians[j] ) )
                                {
                                    cout << "Librarian number " << vec_of_librarians[j].get_number() << " should return the publication number " << vec_of_publications[i].get_position() << endl;
                                    Sleep(1000);
                                }
                            }
                        }
                    }
                }
            }
            cout << "End of loop" << endl;
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
