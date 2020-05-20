#include <iostream>
#include <fstream>

#include "Fizica.h"
#include "Online.h"
#include "Gestionare_Farmacii.h"

using namespace std;

istream &operator>>(istream &in, Farmacie &ob)
{
    ob.citire(in);
    return in;
}

int main()
{
    ifstream fin("Farmacie.txt");
    gestionareFarmacii<farmacieOnline> FO;
    gestionareFarmacii<farmacieFizica> FF;
    farmacieOnline a;
    farmacieFizica b;
    int nrff, nrfo, i;
    fin>>nrff;
    for(i = 0; i< nrff; i++)
   {
        fin >> b;
        FF += b;
    }
    fin >> nrfo;
    for (i = 0; i < nrfo; i++)
    {
        fin >> a;
        FO += a;
    }
    FF.afis();
    FO.afis();
    return 0;
}
