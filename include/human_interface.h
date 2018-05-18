#ifndef HUMAN_INTERFACE_H
#define HUMAN_INTERFACE_H

class human;
class publication;

class human_interface
{
protected:
    virtual bool order( publication *work )=0;
    virtual bool get( publication *work)=0;
    virtual bool giveback( publication *work )=0;
    virtual double check_fee(  )=0;
};
#endif // HUMAN_INTERFACE_H
