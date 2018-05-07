#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

#include <vector>

class human: public operations
{
protected:
    int number;
    double fee;
    std::vector<*publication> books_n_magazines; // field of books and magazines for humans
public:
    ~human();
    virtual bool order( publication work );
    virtual bool get( publication work );
    virtual bool giveback( publication work );
    virtual double check_fee( publication work );
};
#endif // HUMAN_H_INCLUDED
