#include <iostream>

#include "Farmacie.h"
using namespace std;

Farmacie::Farmacie(){
    this -> numeFarmacie = "";
    this -> nr = 0;
}
Farmacie::Farmacie(string numeFarmacie, int nr){
    this -> numeFarmacie = numeFarmacie;
    this -> nr = nr;
}

Farmacie::Farmacie(const Farmacie &f){
    this -> numeFarmacie = f.numeFarmacie;
    this -> nr = f.nr ;
}

Farmacie& Farmacie::operator=(const Farmacie &f){

    this -> numeFarmacie = f.numeFarmacie;
    this -> nr = f.nr ;
    return *this;
}

Farmacie::~Farmacie(){
    this -> numeFarmacie = "";
    this -> nr=0;
}
void Farmacie::afis(ostream &out, Farmacie &f){
output << "Nume Farmacie: " << f.getName() << std::endl;
    output << "Nr de Angajati: " << f.getNr() << std::endl;
}
