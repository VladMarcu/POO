#include <iostream>
#include <utility>

#include "Fizica.h"

using namespace std;

farmacieFizica::farmacieFizica(string numeFarmacie, int nr,int valoare ): Farmacie(move(numeFarmacie),nr){
    this -> profitLunar.resize(12);
    for (unsigned int i = 0; i < 12; i++)
        this -> profitLunar[i] = valoare;
}

farmacieFizica::farmacieFizica(const farmacieFizica &f): Farmacie(f){
    this-> profitLunar.resize(12);
    for(unsigned int i = 0; i < 12; i++)
        this -> profitLunar[i] = f.profitLunar[i];
}

farmacieFizica& farmacieFizica::operator = (const farmacieFizica &f){
    if (this == &f) return *this;
    Farmacie::operator=(f);
    this ->profitLunar.resize(12);
    for(unsigned int i = 0; i < 12; i++)
        this -> profitLunar[i] = f.profitLunar[i];
    return *this;
}

farmacieFizica::~farmacieFizica()(){
    this -> profit.clear();
}

void farmacieFizica::citire(istream &in){
    Farmacie::citire(in);
    for(unsigned int i = 0; i < 12; i++)
        in>>profitLunar[i];
}

void farmacieFizica::afisare(){
    cout<<"Nume farmacie : "<< this -> numeFarmacie <<endl;
    cout<<"Numar angajati : "<< this -> nr <<endl;
    cout<<"Profituri pe fiecare luna : "<<endl;
    for(unsigned int i = 0; i < 12; i++)
    cout<< this -> profitLunar[i] <<"% ";
    cout<<endl;
}
