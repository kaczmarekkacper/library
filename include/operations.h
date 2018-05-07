#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED


class operations
{
public:
    virtual bool order()=0;
    virtual bool get()=0;
    virtual bool giveback()=0;
    virtual double check_fee()=0;
    virtual void iter()=0;
};

#endif // OPERATIONS_H_INCLUDED
