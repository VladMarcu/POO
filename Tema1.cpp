#include <iostream>
#include <cmath>
using namespace std;

class polynomial
{
//definim membrii privati
private:
   double *coef;  // vectori de coeficienti
   int deg;        // gradul

public:
   polynomial(int degree,bool read = true); // constructor de initializare
   polynomial(polynomial const &coef2); // constructor de copiere
   ~polynomial(); // destructor

    friend double calculpunct(const polynomial &coef1, double punct); // calcul in punct

    friend polynomial operator+(polynomial const &coef1, polynomial const &coef2); // suma

    friend polynomial operator-(const polynomial &coef1, const polynomial &coef2); // scaderea

    friend polynomial operator*(const polynomial &coef1, const polynomial &coef2); // inmultirea

    void print(ostream &o) const {
    o << "P = ";
    o << coef[0];
    for(int i = 1; i<= deg - 1; i++)
        o<<" + "<< coef[i] << "X^"<< i;
    } // afisarea polinoamelor

    friend ostream &operator<< (ostream &o, const polynomial &polynomial);
};

polynomial::polynomial(int degree,bool read){
    int i;
    deg = degree;
    coef = new double[degree];
    if (read)
        for (i = 0; i < degree; i++)
            cin >> coef[i];
    else
        for (i = 0; i < degree; i++)
            coef[i]=0;
}

polynomial::polynomial(polynomial const &coef2){
int i;
deg = coef2.deg;
coef = new double[deg];
for(i = 0;i < coef2.deg; i++)
    coef[i] = coef2.coef[i];
}

polynomial::~polynomial(){
delete[] coef;
}

double calculpunct(const polynomial &coef1, double punct) {

    double suma = 0;
    for (int i = coef1.deg - 1; i >= 0; i--)
        suma = suma + (pow(punct, i) * coef1.coef[i]);
    return suma;
}

polynomial operator+(polynomial const &coef1, polynomial const &coef2) {
    polynomial rez(max(coef1.deg, coef2.deg), false);
    polynomial const &p = coef1.deg > coef2.deg ? coef1 : coef2;
    for (int i = 0; i < min(coef1.deg, coef2.deg); i++)
        rez.coef[i] = coef1.coef[i] + coef2.coef[i];
    for (int j = min(coef1.deg, coef2.deg); j < rez.deg; ++j)
        rez.coef[j] = p.coef[j];
    return rez;
}

polynomial operator-(const polynomial &coef1, const polynomial &coef2) {

    polynomial rez(max(coef1.deg, coef2.deg), false);
    polynomial const &p = coef1.deg > coef2.deg ? coef1 : coef2;

    for (int i = 0; i <= min(coef1.deg, coef2.deg) - 1; i++)
        rez.coef[i] = coef1.coef[i] - coef2.coef[i];
    for (int j = min(coef1.deg, coef2.deg); j < rez.deg; ++j)
        rez.coef[j] = p.coef[j];
    return rez;
	}


	polynomial operator*(const polynomial &coef1, const polynomial &coef2) {

    polynomial rez((coef1.deg * coef2.deg), false);

    for (int i = 0; i <= coef1.deg - 1; i++)
        for (int j = 0; j <= coef2.deg - 1; j++) {
            rez.coef[i + j] = rez.coef[i + j] + coef1.coef[i] * coef2.coef[j];
        }
    return rez;
	}

ostream &operator<<(ostream &o, const polynomial &polynomial) {
    polynomial.print(o);
    return o;
}


int main() {
    int m, n;
    int x;
    cin >> n >> m >> x; // n - gradul primului polinom m - gradul celui de-al doilea
                        // x - punctul de calcul
    polynomial coef1(n);
    polynomial coef2(m);
    polynomial coef3 = coef1 + coef2;
    polynomial coef4 = coef1 - coef2;
    polynomial coef5 = coef1 * coef2;
    double suma = calculpunct(coef1, x);
    cout << "Suma=" << suma << endl;
    cout << coef1 << endl;
    cout << coef2 << endl;
    cout << coef3 << endl;
    cout << coef4 << endl;
    cout << coef5;
    return 0;
}
