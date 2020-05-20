#ifndef FIZICA_H_INCLUDED
#define FIZICA_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

class farmacieFizica : public Farmacie{
    private:
        vector<int> profitLunar;
    public:
        farmacieFizica(string numeFarmacie="", int nr = 0);
        farmacieFizica(const farmacieFizica &f);
        farmacieFizica& operator= (const farmacieFizica &f);
        virtual ~farmacieFizica() ;

        virtual void citire()(istream &in);
        virtual void afisare();
};

#endif // FIZICA_H_INCLUDED
