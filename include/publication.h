#ifndef PUBLICATION_H_INCLUDED
#define PUBLICATION_H_INCLUDED


class publication
{
    char *title;
    int position;
    int amount;
    int time;
    bool active;
public:
    bool order();
    bool get();
    bool giveback();
    double check_fee();

};

#endif // PUBLICATION_H_INCLUDED
