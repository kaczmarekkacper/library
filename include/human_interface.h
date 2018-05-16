#ifndef HUMAN_INTERFACE_H
#define HUMAN_INTERFACE_H

class human;
class publication;

class human_interface
{
protected:
    virtual bool order( publication *work, human *assistant )=0;
    virtual bool get( publication *work, human *assistant )=0;
    virtual bool giveback( publication *work, human *assistant )=0;
    virtual double check_fee( publication *work, human *assistant )=0;
    virtual void change_fee ( double extra_fee )=0;
};
#endif // HUMAN_INTERFACE_H
