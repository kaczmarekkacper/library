#include <fstream>
#include <iostream>

#include "test_for_library.h"

using namespace std;

int main()
{
    int hmr, hml, hmb, hmm, hmloops;
    fstream file;
    file.open( "config.txt" );
    if ( file.good() )
    {
        try
        {
            file >> hmr;
            if ( file.fail() || file.eof() )
            {
                throw 1;
            }
            file >> hml;
            if ( file.fail() || file.eof() )
            {
                throw 2;
            }
            file >> hmb;
            if ( file.fail() || file.eof() )
            {
                throw 3;
            }
            file >> hmm;
            if ( file.fail() || file.eof() )
            {
                throw 4;
            }
            file >> hmloops;
            if ( file.fail())
            {
                throw 5;
            }
            cout << "Data from file" << endl;
            test_for_library  T( hmr, hml, hmb, hmm, hmloops);
            file.close();
        }
        catch (int i)
        {
            if ( i == 1 )
            {
                cout << "Something wrong with the readers parameter." << endl;
                cout << "Start with default parameters." << endl;
            }
            if ( i == 2 )
            {
                cout << "Something wrong with the librarians parameter." << endl;
                cout << "Start with default parameters." << endl;
            }
            if ( i == 3)
            {
                cout << "Something wrong with the books parameter." << endl;
                cout << "Start with default parameters." << endl;
            }
            if ( i == 4)
            {
                cout << "Something wrong with the magazines parameter." << endl;
                cout << "Start with default parameters." << endl;
            }
            if ( i == 5 )
            {
                cout << "Something wrong with the loops parameter." << endl;
                cout << "Start with default parameters." << endl;
            }
            file.close();
            test_for_library  T( 2, 3, 3, 3, 5);
        }
    }
    else
    {
        cout << "Default" << endl;
        test_for_library  T( 2, 3, 3, 3, 5);
    }

    return 0;
}
