#ifndef PUB_INTERFACE_H
#define PUB_INTERFACE_H

class pub_interface
{
protected:
    virtual bool order( human *selected )=0;
    virtual bool get( human *selected )=0;
    virtual bool giveback( human *selected )=0;
    virtual double check_fee()=0;
    virtual void iter()=0;
    virtual bool isactive();
};
#endif // PUB_INTERFACE_H
