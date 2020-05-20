#ifndef FARMACIE_H_INCLUDED
#define FARMACIE_H_INCLUDED
#include <iostream>
using namespace std;

class Farmacie{
    private:
        string numeFarmacie;
        int nr;
        virtual void afis(ostream &out, Farmacie &f);
    public:
        Farmacie();
        Farmacie(string numeFarmacie,int nr); // contructor parametrizat
        Farmacie(const Farmacie &f); //copy constructor
        Farmacie& operator= (const Farmacie &f) ; //supraincarcarea operatorului
        virtual ~Farmacie(); //destructor
        friend ostream& operator <<( ostream& out, const Farmacie& f);
        friend istream& operator >>( istream& in, Farmacie& f);

};


#endif // FARMACIE_H_INCLUDED
