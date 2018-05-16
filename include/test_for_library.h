#ifndef TEST_FOR_LIBRARY_H_INCLUDED
#define TEST_FOR_LIBRARY_H_INCLUDED

#include <random>
#include <iostream>

#include "publication.h"
#include "book.h"
#include "magazine.h"
#include "human.h"
#include "reader.h"
#include "librarian.h"

class test_for_library
{
    std::vector <reader> vec_of_readers;
    std::vector <librarian> vec_of_librarians;
    std::vector <publication> vec_of_publications;
public:
    // hmr - how many readers
    // hml - how many librarians
    // hmb - how many books
    // hmm - how many magazines
    // hml - how many loops
    test_for_library(int hmr, int hml, int hmb, int hmm, int hmloops );
    ~test_for_library();
    long rdnumber( int a, int b);
};

#endif // TEST_FOR_LIBRARY_H_INCLUDED
