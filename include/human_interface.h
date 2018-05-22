#ifndef HUMAN_INTERFACE_H
#define HUMAN_INTERFACE_H

#include <fstream>
class publication;

class human;

class human_interface
{
protected:
    virtual bool order( publication *work )=0;
    virtual bool get( publication *work)=0;
    virtual double giveback( publication *work )=0;
    virtual double check_fee(  )=0;
    virtual int get_number()=0;
    virtual void human_status ( std::fstream *file )=0;
    virtual bool check_ordering( publication *work )=0;
};
#endif // HUMAN_INTERFACE_H
