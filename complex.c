#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

class complex
{ 
    double re,im;    // partie réelle et imaginaire du nombre complexe
    public:
        complex(double,double );  // constructeur

        // Manipulation des complexes
        double real();
        double imag();
        complex conj();
        double norme();
        double arg();

        // Créer un objet complexe en donnant des coordonnées polaires
        complex polar(double,double);

        // Fonctions d'opérations binaires
        complex operator+(complex);
        friend complex operator+(double,complex);
        friend complex operator+(complex,double);

        complex operator-(complex);
        friend complex operator-(double,complex);
        friend complex operator-(complex,double);

        complex operator*(complex);
        friend complex operator*(double,complex);
        friend complex operator*(complex,double);

        complex operator/(complex);
        friend complex operator/(double,complex);
        friend complex operator/(complex,double);

        complex operator=(complex);
        int operator==(complex);
        int operator!=(complex);
        complex operator-();  // opposé du vecteur

        friend ostream& operator<<(ostream& os, const complex& z);
        friend istream& operator>>(istream& is, complex& z);
};

complex::complex(double reel = 0.0, double imaginaire = 0.0)
{
    re = reel; im = imaginaire;
}
// Manipulation des complexes
double complex::real()
{
    return re;
}

double complex::imag()
{
    return im;
}

complex complex::conj()
{
    complex res;
    res.re = re;
    res.im = -im;
    return res;
}

double complex::norme()
{
    double res = re*re + im*im;
    return pow(res,0.5);
}

double complex::arg()
{
    double res = atan(im/re);
    return res;
}
// Créer un objet complexe en donnant des coordonnées polaires
complex complex::polar(double mag, double angle=0)
{
    complex res;
    res.re = mag*cos(angle);
    res.im = mag*sin(angle);
    return res; 
}

// Fonctions d'opérations binaires
complex complex::operator+(complex z)
{
    complex res;
    res.re = re + z.re;
    res.im = im + z.im;
    return res;
}

complex operator+(double k, complex z)
{
    complex res;
    res.re = z.re + k;
    res.im = z.im;
    return res;
}
complex operator+(complex z,double k)
{
    complex res;
    res.re = z.re + k;
    res.im = z.im;
    return res;
}

complex complex::operator-(complex z)
{
    complex res;
    res.re = re - z.re;
    res.im = im - z.im;
    return res;
}
complex operator-(double k, complex z)
{
    complex res;
    res.re = k - z.re;
    res.im = z.im;
    return res;
}
complex operator-(complex z, double k)
{
    complex res;
    res.re = z.re - k;
    res.im = z.im;
    return res;
}

complex complex::operator*(complex z)
{
    complex res;
    res.re = re*z.re - im*z.im;
    res.im = re*z.im + im*z.re;
    return res;
}
complex operator*(double k,complex z)
{
    complex res;
    res.re = k*z.re;
    res.im = k*z.im;
    return res;
}
complex operator*(complex z,double k)
{
    complex res;
    res.re = k*z.re;
    res.im = k*z.im;
    return res;
}

complex complex::operator/(complex z)
{
    complex res;
    double mod = z.norme();
    res.re = (re*z.re + im*z.im)/pow(mod,2);
    res.im = (z.re*im - re*z.im)/pow(mod,2);
    return res;
}
complex operator/(double k, complex z)
{
    complex res;
    res.re = z.re/k;
    res.im = z.im/k;
    return res;
}
complex operator/(complex z,double k)
{
    complex res;
    res.re = z.re/k;
    res.im = z.im/k;
    return res;
}

complex complex::operator=(complex z)
{
    complex res;
    res.re = z.re;
    res.im = z.im;
    return res;
}

int complex::operator==(complex z)
{
    if(this->re == z.re && this->im == z.im) return 1;
    else return 0;
}
int complex::operator!=(complex z)
{
    if(this->re != z.re || this->im != z.im) return 1;
    else return 0;
}
complex complex::operator-()
{
    complex res;
    res.re = -re;
    res.im = -im;
    return res;
}

// Redéfinition de l'opérateur <<
ostream& operator<<(ostream& os, const complex& z) {
    os << z.re;
    if (z.im >= 0)
        os << " + " << z.im << "i";
    else
        os << " - " << -z.im << "i";
    return os;
}

// Redéfinition de l'opérateur >>
istream& operator>>(istream& is, complex& z) {
    cout << "Entrez la partie réelle : ";
    is >> z.re;
    cout << "Entrez la partie imaginaire : ";
    is >> z.im;
    return is;
}

int main()
{
    // Test des opérations
    complex z1,z2;
    cin >> z1;
    cin >> z2;
    cout << "********** Manipulation des complexes ******************** \n";
    cout << "La partie réelle de z1 est : " << z1.real() << endl;
    cout << "La partie imaginaire de z2 est : " << z2.imag() << endl;
    cout << "Le conjugué de z1 est : " << z1.conj() << endl;
    cout << "La norme de z2 est : " << z2.norme() << endl;
    cout << "L'argument de z1 est : " << z1.arg() <<" rad" << endl;
    cout << "**************************************************************\n";
    cout << "*** Créer un objet complexe en donnant des coordonnées polaires ***\n";
    complex z;
    double module,angle;
    cout << "Entrer le module du nombre complexe : ";
    cin >> module;
    cout << "Entrer son argument en radian : ";
    cin >> angle;
    z.polar(module,angle);
    cout << "Le complexe créé est : " << z << endl;
    cout << "***************************************************************\n";
    cout << "************** Fonctions d'opérations binaires ****************\n";
    cout << "*** Addition\n";
    cout << "z1 + z2 donne : " << z1 + z2 << endl;
    cout << "z1 + 5 donne : " << z1 + 5 << endl;
    cout << "10 + z2 donne : " << 10 + z2 << endl;
    cout << "*** Soustraction\n";
    cout << "z1 - z2 donne : " << z1 - z2 << endl;
    cout << "z1 - 5 donne : " << z1 - 5 << endl;
    cout << "10 - z2 donne : " << 10 - z2 << endl;
    cout << "*** Multiplication\n";
    cout << "z1 * z2 donne : " << z1 * z2 << endl;
    cout << "z1 * 5 donne : " << z1 * 5 << endl;
    cout << "10 * z2 donne : " << 10 * z2 << endl;
    cout << "*** Division\n";
    cout << "z1 / z2 donne : " << z1 / z2 << endl;
    cout << "z1 / 5 donne : " << z1 / 5 << endl;
    cout << "10 / z2 donne : " << 10 / z2 << endl;
    cout << "*** Comparaison\n";
    if(z1 == z2) cout << "z1 et z2 sont égaux!\n";
    else cout << "z1 et z2 sont différents!\n";

    if(z1 != z2) cout << "z1 et z2 ne sont pas égaux!\n";
    else cout << "z1 et z2 ne sont pas différents!\n";
    cout << "*** Opposé du vecteur\n";
    cout << "z1 = "<< z1 << " son opposé est : " << -z1 << endl;


    return 0;
}
