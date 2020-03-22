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

std::ostream & operator << (std::ostream & strm, const LZespolona & lz)
{
    strm<<'('<<lz.re<<std::showpos<<lz.im<<std::noshowpos<<"i)";
    return strm;
}
std::istream & operator >> (std::istream & strm, LZespolona & lz)
{
    char znak;
    strm >> znak;
    if (znak != '(') strm.setstate(std::ios::failbit);
    strm >> lz.re;
    strm >> lz.im;
    strm >> znak;
    if (znak != 'i') strm.setstate(std::ios::failbit);
    strm >> znak;
    if (znak != ')') strm.setstate(std::ios::failbit);
    return strm;
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


