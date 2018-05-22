#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <fstream>

#include "test_for_library.h"

using namespace std;

test_for_library::test_for_library( int hmr, int hml, int hmb, int hmm, int hmloops)
{
    fstream file;
    file.open( "log.txt", ios::out | ios::trunc | ios::binary );
    try
    {
        if ( !file.good() )
            throw 1;
    }
    catch ( int i )
    {
        cout << "Something wrong with file." << endl;
        return;
    }
    cout << "Starting test function" << endl << endl;
    file << "Starting test function" << endl << endl;
    double fee;
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
        vec_of_publications.push_back( book() );
    }

    for ( int i= 0; i < hmm ; i++ )
    {
        vec_of_publications.push_back( magazine() );
    }

    for (int i = 0 ; i < hmloops ; i++)
    {
        for (int j = 0 ; j < hmloops/2 ; j++)
        {
            cout << "New loop." << endl;
            file << "New loop." << endl;
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
                        cout << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                        file << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " for reader " << vec_of_readers[wor].get_number() << endl;
                        file << " for reader " << vec_of_readers[wor].get_number() << endl;
                        Sleep(1000);
                        if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << vec_of_readers[wor].get_number() << " ordered a ";
                            file << "Reader number " << vec_of_readers[wor].get_number() << " ordered a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << endl;
                            file << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Error! Librarian ordered a book, but a reader doesn't." << endl;
                            file << "Error! Librarian ordered a book, but a reader doesn't." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "Reader number " << vec_of_readers[wor].get_number() << " cant order a ";
                        file << "Reader number " << vec_of_readers[wor].get_number() << " cant order a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout <<  "because it isn't active." << endl;
                        file <<  "because it isn't active." << endl;
                        Sleep(1000);
                        cout << "So reader " << vec_of_readers[wor].get_number() << " is going to borrow a ";
                        file << "So reader " << vec_of_readers[wor].get_number() << " is going to borrow a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << endl;
                        file << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                            file << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << "for reader " << vec_of_readers[wor].get_number() << endl;
                            file << "for reader " << vec_of_readers[wor].get_number() << endl;
                            Sleep(1000);
                            if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << vec_of_readers[wor].get_number() << " borrowed a ";
                                file << "Reader number " << vec_of_readers[wor].get_number() << " borrowed a ";
                                vec_of_publications[wop].whats_your_name( &file );
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Error! Librarian " << vec_of_librarians[wol].get_number() << " setted a ";
                                file << "Error! Librarian " << vec_of_librarians[wol].get_number() << " setted a ";
                                vec_of_publications[wop].whats_your_name( &file );
                                cout << "as borrowed, but reader " << vec_of_readers[wor].get_number() << " doesn't borrow it.";
                                file << "as borrowed, but reader " << vec_of_readers[wor].get_number() << " doesn't borrow it.";
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_readers[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                        file << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "for reader " << vec_of_readers[wor].get_number() << endl;
                        file << "for reader " << vec_of_readers[wor].get_number() << endl;
                        Sleep(1000);
                        if ( vec_of_readers[wor].get( &vec_of_publications[wop]) )
                        {
                            cout << "Reader number " << vec_of_readers[wor].get_number() << " borrowed a ";
                            file << "Reader number " << vec_of_readers[wor].get_number() << " borrowed a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << endl;
                            file << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Error! Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                            file << "Error! Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << " as borrowed, but reader " << vec_of_readers[wor].get_number() << " doesn't borrow it." << endl;
                            file << " as borrowed, but reader " << vec_of_readers[wor].get_number() << " doesn't borrow it." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "Reader number " << vec_of_readers[wor].get_number() << " can't borrow a ";
                        file << "Reader number " << vec_of_readers[wor].get_number() << " can't borrow a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "because it is active." << endl;
                        file << "because it is active." << endl;
                        Sleep(1000);
                        cout << "So reader " << vec_of_readers[wor].get_number() << " is going to order a ";
                        file << "So reader " << vec_of_readers[wor].get_number() << " is going to order a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << endl;
                        file << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_order( &vec_of_readers[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                            file << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << "for reader " << vec_of_readers[wor].get_number() << endl;
                            file << "for reader " << vec_of_readers[wor].get_number() << endl;
                            Sleep(1000);
                            if ( vec_of_readers[wor].order( &vec_of_publications[wop]) )
                            {
                                cout << "Reader number " << vec_of_readers[wor].get_number() << " ordered a ";
                                file << "Reader number " << vec_of_readers[wor].get_number() << " ordered a ";
                                vec_of_publications[wop].whats_your_name( &file);
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Librarian set a ";
                                file << "Librarian set a ";
                                vec_of_publications[wop].whats_your_name( &file);
                                cout << " as ordered, but reader number " << vec_of_readers[wor].get_number() << " didn't order it." << endl;
                                file << " as ordered, but reader number " << vec_of_readers[wor].get_number() << " didn't order it." << endl;
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 3:
                    cout << "Reader number " << vec_of_readers[wor].get_number() << " want to return a ";
                    file << "Reader number " << vec_of_readers[wor].get_number() << " want to return a ";
                    vec_of_publications[wop].whats_your_name( &file );
                    cout << endl;
                    file << endl;
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_readers[wor], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                        file << "Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " as givebacked." << endl;
                        file << " as givebacked." << endl;
                        Sleep(1000);

                    }
                    else
                    {
                            cout << "Librarian number " << vec_of_librarians[wol].get_number() << " cant set a ";
                            file << "Librarian number " << vec_of_librarians[wol].get_number() << " cant set a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << " as givebacked." << endl;
                            file << " as givebacked." << endl;
                    }
                    fee = vec_of_readers[wor].giveback( &vec_of_publications[wop]);
                    if ( fee = -2 )
                    {
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "isnt even active " << endl;
                        file << "isnt even active " << endl;
                        Sleep(1000);
                    }
                    else if ( fee = -1 )
                    {
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " isnt belong to this reader number " << vec_of_readers[wor].get_number() << "." << endl;
                        file << " isnt belong to this reader number " << vec_of_readers[wor].get_number() << "." << endl;
                        Sleep(1000);
                    }
                    else if ( fee = 0.0)
                    {
                        cout << "Reader number " << vec_of_readers[wor].get_number() << " doesnt need to pay a fee." << endl;
                        file << "Reader number " << vec_of_readers[wor].get_number() << " doesnt need to pay a fee." << endl;
                        Sleep(1000);
                    }
                    else
                    {
                        cout << "Reader " << vec_of_readers[wor].get_number() << " need to pay " << fee << endl;
                        file << "Reader " << vec_of_readers[wor].get_number() << " need to pay " << fee << endl;
                        Sleep(1000);
                    }
                    break;
                case 4:
                    cout << "Reader number " << vec_of_readers[wor].get_number() << " want to check his fee." << endl;
                    file << "Reader number " << vec_of_readers[wor].get_number() << " want to check his fee." << endl;
                    Sleep(1000);
                    cout << "Reader number " << vec_of_readers[wor].get_number() << " need to pay " << vec_of_readers[wor].check_fee() << " at all." << endl;
                    file << "Reader number " << vec_of_readers[wor].get_number() << " need to pay " << vec_of_readers[wor].check_fee() << " at all." << endl;
                    Sleep(1000);
                    break;
                default:
                    cout << "Reader nr " << vec_of_readers[wor].get_number() << " does nothing." << endl;
                    file << "Reader nr " << vec_of_readers[wor].get_number() << " does nothing." << endl;
                    Sleep(1000);
                break;
                };
            }
            else
            {
                long option = rdnumber(1, 5);
                int wor = rdnumber( 0, vec_of_librarians.size()-1);
                // wor - which one reader
                int wop = rdnumber( 0, vec_of_publications.size()-1);
                // wop - which one publication
                int wol = rdnumber ( 0, vec_of_librarians.size()-1);
                while (1)
                {
                    if ( wol != wor)
                        break;
                    wol = rdnumber ( 0, vec_of_librarians.size()-1);
                }
                // wol - which one librarian
                switch ( option )
                {
                case 1:
                    if ( vec_of_librarians[wol].lib_order( &vec_of_librarians[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                        file << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                        file << " for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wor].order( &vec_of_publications[wop]) )
                        {
                            cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " ordered a ";
                            file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " ordered a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << endl;
                            file << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Error! Librarian ordered a book, but a LibrarianReader doesn't." << endl;
                            file << "Error! Librarian ordered a book, but a LibrarianReader doesn't." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " cant order a ";
                        file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " cant order a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout <<  "because it isn't active." << endl;
                        file <<  "because it isn't active." << endl;
                        Sleep(1000);
                        cout << "So LibrarianReader " << vec_of_librarians[wor].get_number() << " is going to borrow a ";
                        file << "So LibrarianReader " << vec_of_librarians[wor].get_number() << " is going to borrow a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << endl;
                        file << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                            file << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                            file << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                            Sleep(1000);
                            if ( vec_of_librarians[wor].get( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " borrowed a ";
                                file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " borrowed a ";
                                vec_of_publications[wop].whats_your_name( &file );
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Error! Librarian " << vec_of_librarians[wol].get_number() << " setted a ";
                                file << "Error! Librarian " << vec_of_librarians[wol].get_number() << " setted a ";
                                vec_of_publications[wop].whats_your_name( &file );
                                cout << "as borrowed, but LibrarianReader " << vec_of_librarians[wor].get_number() << " doesn't borrow it.";
                                file << "as borrowed, but LibrarianReader " << vec_of_librarians[wor].get_number() << " doesn't borrow it.";
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 2:
                    if ( vec_of_librarians[wol].lib_get( &vec_of_librarians[wor], &vec_of_publications[wop]) )
                    {
                        cout << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                        file << "Librarian " << vec_of_librarians[wol].get_number() << " set as borrowed a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                        file << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wor].get( &vec_of_publications[wop]) )
                        {
                            cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " borrowed a ";
                            file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " borrowed a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << endl;
                            file << endl;
                            Sleep(1000);
                        }
                        else
                        {
                            cout << "Error! Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                            file << "Error! Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << " as borrowed, but LibrarianReader " << vec_of_librarians[wor].get_number() << " doesn't borrow it." << endl;
                            file << " as borrowed, but LibrarianReader " << vec_of_librarians[wor].get_number() << " doesn't borrow it." << endl;
                            Sleep(1000);
                        }
                    }
                    else
                    {
                        cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " can't borrow a ";
                        file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " can't borrow a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "because it is active." << endl;
                        file << "because it is active." << endl;
                        Sleep(1000);
                        cout << "So LibrarianReader " << vec_of_librarians[wor].get_number() << " is going to order a ";
                        file << "So LibrarianReader " << vec_of_librarians[wor].get_number() << " is going to order a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << endl;
                        file << endl;
                        Sleep(1000);
                        if ( vec_of_librarians[wol].lib_order( &vec_of_librarians[wor], &vec_of_publications[wop]) )
                        {
                            cout << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                            file << "Librarian " << vec_of_librarians[wol].get_number() << " ordered a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                            file << "for LibrarianReader " << vec_of_librarians[wor].get_number() << endl;
                            Sleep(1000);
                            if ( vec_of_librarians[wor].order( &vec_of_publications[wop]) )
                            {
                                cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " ordered a ";
                                file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " ordered a ";
                                vec_of_publications[wop].whats_your_name( &file);
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                            else
                            {
                                cout << "Librarian set a ";
                                file << "Librarian set a ";
                                vec_of_publications[wop].whats_your_name( &file);
                                cout << " as ordered, but LibrarianReader number " << vec_of_librarians[wor].get_number() << " didn't order it." << endl;
                                file << " as ordered, but LibrarianReader number " << vec_of_librarians[wor].get_number() << " didn't order it." << endl;
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                        }
                    }
                    break;
                case 3:
                    cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " want to return a ";
                    file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " want to return a ";
                    vec_of_publications[wop].whats_your_name( &file );
                    cout << endl;
                    file << endl;
                    if ( vec_of_librarians[wol].lib_giveback( &vec_of_librarians[wor], &vec_of_publications[wop] ) )
                    {
                        cout << "Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                        file << "Librarian number " << vec_of_librarians[wol].get_number() << " set a ";
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " as givebacked." << endl;
                        file << " as givebacked." << endl;
                        Sleep(1000);

                    }
                    else
                    {
                            cout << "Librarian number " << vec_of_librarians[wol].get_number() << " cant set a ";
                            file << "Librarian number " << vec_of_librarians[wol].get_number() << " cant set a ";
                            vec_of_publications[wop].whats_your_name( &file );
                            cout << " as givebacked." << endl;
                            file << " as givebacked." << endl;
                    }
                    fee = vec_of_librarians[wor].giveback( &vec_of_publications[wop]);
                    if ( fee = -2 )
                    {
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << "isnt even active " << endl;
                        file << "isnt even active " << endl;
                        Sleep(1000);
                    }
                    else if ( fee = -1 )
                    {
                        vec_of_publications[wop].whats_your_name( &file );
                        cout << " isnt belong to this reader number " << vec_of_librarians[wor].get_number() << "." << endl;
                        file << " isnt belong to this reader number " << vec_of_librarians[wor].get_number() << "." << endl;
                        Sleep(1000);
                    }
                    else if ( fee = 0.0)
                    {
                        cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " doesnt need to pay a fee." << endl;
                        file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " doesnt need to pay a fee." << endl;
                        Sleep(1000);
                    }
                    else
                    {
                        cout << "LibrarianReader " << vec_of_librarians[wor].get_number() << " need to pay " << fee << endl;
                        file << "LibrarianReader " << vec_of_librarians[wor].get_number() << " need to pay " << fee << endl;
                        Sleep(1000);
                    }
                    break;
                case 4:
                    cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " want to check his fee." << endl;
                    file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " want to check his fee." << endl;
                    Sleep(1000);
                    cout << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " need to pay " << vec_of_librarians[wor].check_fee() << " at all." << endl;
                    file << "LibrarianReader number " << vec_of_librarians[wor].get_number() << " need to pay " << vec_of_librarians[wor].check_fee() << " at all." << endl;
                    Sleep(1000);
                    break;
                default:
                    cout << "LibrarianReader nr " << vec_of_librarians[wor].get_number() << " does nothing." << endl;
                    file << "LibrarianReader nr " << vec_of_librarians[wor].get_number() << " does nothing." << endl;
                    Sleep(1000);
                break;
                };
            }
            for ( int i = 0; i < vec_of_publications.size()-1 ; i++ )
            {
                int option;
                if ( option = vec_of_publications[i].iter() )
                {
                    if ( option == 1 )
                    {
                        cout << endl;
                        file << endl;
                        for ( int j = 0 ; j < vec_of_readers.size()-1 ; j++ )
                        {
                            if ( vec_of_publications[i].check_owner( &vec_of_readers[j] ) )
                            {
                                cout << "Reader number " << vec_of_readers[j].get_number() << " should return a ";
                                file << "Reader number " << vec_of_readers[j].get_number() << " should return a ";
                                vec_of_publications[i].whats_your_name( &file);
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                            if ( vec_of_publications[i].check_owner( &vec_of_librarians[j] ) )
                            {
                                cout << "LibrarianReader number " << vec_of_librarians[j].get_number() << " should return a ";
                                file << "LibrarianReader number " << vec_of_librarians[j].get_number() << " should return a ";
                                vec_of_publications[i].whats_your_name( &file);
                                cout << endl;
                                file << endl;
                                Sleep(1000);
                            }
                        }
                    }
                }
            }
        cout << "End of loop" << endl << endl;
        file << "End of loop" << endl << endl;
        Sleep(1000);
        }
    }
    for ( int i = 0; i < vec_of_publications.size()-1; i++)
    {

        vec_of_publications[i].status( &file );
        cout << endl;
        file << endl;
        Sleep(1000);
    }

    for ( int i = 0; i < vec_of_readers.size()-1; i++)
    {

        vec_of_readers[i].human_status( &file );
        cout << endl;
        file << endl;
        Sleep(1000);
    }

    for ( int i = 0; i < vec_of_librarians.size()-1; i++)
    {

        vec_of_librarians[i].human_status( &file );
        cout << endl;
        file << endl;
        Sleep(1000);
    }

    file.close();
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
