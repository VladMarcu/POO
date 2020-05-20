#include <iostream>
#include <utility>

#include "Online.h"
using namespace std;

farmacieOnline::farmacieOnline(string numeFarmacie, int nr, int discount): Farmacie(move(numeFarmacie), nr){
    this -> discount = discount;
}

farmacieOnline::farmacieOnline(const farmacieOnline &f): Farmacie(f){
    this -> discount = f.discount;
}

farmacieOnline& farmacieOnline::operator = (const  &f){
    if(this == &f) return *this;
    Farmacie::operator(f);
    this -> discount = f.discount;
    return *this;
}

formacieOnline:: ~farmacieOnline(){
    this -> discount = 0;
}

int farmacieOnline::getNr(){
    return this -> nr;
}

void farmacieOnline::citire(istream &in){
    Farmacie::citire(in);
    in >> discount;
}

void farmacieOnline::afisare(){
    cout<<"Adresa web : "<<this -> numeFarmacie <<endl;
    cout<<"Numarul de vizitatori : "<<this -> nr <<endl;
    cout<<"Discount-ul este : "<< this -> discount <<endl;
}
