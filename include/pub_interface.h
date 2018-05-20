#ifndef PUB_INTERFACE_H
#define PUB_INTERFACE_H

class pub_interface
{
protected:
    virtual bool order( human *selected )=0;
    virtual bool get( human *selected )=0;
    virtual bool giveback( human *selected )=0;
    virtual double check_fee()=0;
    virtual int iter()=0;
    virtual bool isactive()=0;
    virtual bool check_owner(human *client)=0;
    virtual void status()=0;
    virtual bool statusqueue()=0;
    virtual void set_fee_as_zero()=0;
    virtual int get_position()=0;
};
#endif // PUB_INTERFACE_H
