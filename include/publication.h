#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication
{
protected:
    int position;
    bool active;
    int iterations;
public:
    publication();
    ~publication();
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();
};

#endif // PUBLICATION_H_INCLUDED
