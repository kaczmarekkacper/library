
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
        vec_of_readers.push_back( librarian() );
    }
    for ( int i= 0; i < hmb ; i++ )
    {
        vec_of_books.push_back( book() );
    }
    for ( int i= 0; i < hmm ; i++ )
    {
        vec_of_magazines.push_back( magazine() );
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
