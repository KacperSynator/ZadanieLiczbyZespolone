#include "LZespolona.hh"
#include <math.h>
#include <iostream>

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re + Skl2.re;
    Wynik.im = Skl1.im + Skl2.im;
    return Wynik;
}
LZespolona Utworz(double re, double im)
{
LZespolona lz;
lz.re=re;
lz.im=im;
return lz;
}

void Wyswietl(LZespolona lz)
{
    std::cout<<'('<< lz.re<< std::showpos<< lz.im <<std::noshowpos <<"i)\n";
}
bool Wczytaj(LZespolona *lz)
{
    char nawp,i,nawl;
    std::cin >> nawl >> lz->re >> lz->im >> i >> nawp;
    if(nawl != '(' || i != 'i' || nawp != ')' ) return false;
    else return true;
}
void Sprzezenie(LZespolona *lz)
{
    lz->im*=(-1);
}

double Modul(LZespolona lz)
{
    double mod = sqrt(lz.re*lz.re+ lz.im*lz.im);
    return mod;
}
LZespolona DzielenieRrzeczywiste(LZespolona lz, double lr)
{

    LZespolona Wynik;

    Wynik.re=lz.re/lr;
    Wynik.im=lz.im/lr;
    return Wynik;
}

LZespolona operator - (LZespolona l1, LZespolona l2)
{
    LZespolona Wynik;

    Wynik.re = l1.re - l2.re;
    Wynik.im = l1.im - l2.im;
    return Wynik;
}

LZespolona operator * (LZespolona l1, LZespolona l2)
{
    LZespolona Wynik;

    Wynik.re = l1.re*l2.re - l1.im*l2.im;
    Wynik.im = l1.re*l2.im + l1.im*l2.re;
    return Wynik;
}

LZespolona operator / (LZespolona l1, LZespolona l2)
{
    LZespolona Wynik;

    Sprzezenie(&l2);

    Wynik=l1 * l2;
    Wynik=DzielenieRrzeczywiste(Wynik ,Modul(l2)*Modul(l2));
    return Wynik;
}
bool operator  == (LZespolona l1,LZespolona l2)
{
    if(l1.re == l2.re && l1.im==l2.im) return true;
    return false;
}
bool operator != (LZespolona l1,LZespolona l2)
{
    if(l1==l2) return false;
    return  true;
}


