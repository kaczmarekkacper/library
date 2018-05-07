

#include "publication.h"
#include <vector>

bool publication::order( human *selected, int loops )
{
    if ( !active )
    {
        get( selected );
    }
    else
    {
        if ( ordered = -1 )
            ordered = loops + 1;
        else
            ordered = ordered + loops;
        ordering.push_back( selected );
    }
}

