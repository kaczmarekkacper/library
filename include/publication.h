#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication
{
protected:
    char *title;
    int position;
    int amount;
    int time;
    bool active;
public:
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();

};

#endif // PUBLICATION_H_INCLUDED
