#ifndef HUMAN_H_INCLUDED
#define HUMAN_H_INCLUDED

class human
{
public:
    ~human();
    virtual bool lend();
    virtual bool give_back();
    virtual bool order();
};
#endif // HUMAN_H_INCLUDED
