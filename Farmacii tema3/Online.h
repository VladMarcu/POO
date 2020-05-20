#ifndef ONLINE_H_INCLUDED
#define ONLINE_H_INCLUDED

#include <iostream>

#include "Farmacie.h"
using namespace std;

class farmacieOnline : public Farmacie{
private:
        int discount;
    public:
    farmacieOnline(string numeFarmacie = "",int nr = 0, int discount = 0);
    farmacieOnline(const farmacieOnline &f);
    farmacieOnline& operator = (const farmacieOnline &f);
    virtual ~farmacieOnline();
    int getNr();
    virtual void citire(istream &in);
    virtual void afisare() ;
};

#endif // ONLINE_H_INCLUDED
