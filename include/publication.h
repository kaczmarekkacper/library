#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication
{
protected:
    int position;
    static const int time;
    int how_many;
    bool active;
    double fee;
public:
    virtual bool order();
    virtual bool get();
    virtual bool giveback();
    virtual double check_fee();

};

#endif // PUBLICATION_H_INCLUDED
