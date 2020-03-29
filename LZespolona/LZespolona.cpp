#include "LZespolona.hh"
#include <math.h>
#include <iostream>


void ZwrocWszystko(const char buf[],std::istream & strm)
{
    int i=0;
    while(buf[i]!='\0')
    {
        i++;
    }
    for(;i>=0;--i) strm.putback(buf[i]);
}

LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
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
   /* bool koniec=false;
    int m=2;
    char ln,pn,i;
    char buffor[256];
    while(!koniec)
    {
        switch(m)
        {
            case 0: //BLAD
                strm.setstate(std::ios::failbit);
                koniec=true;
                break;


            case 1: //OK
                koniec=true;
                break;


            case 2: // czy lewy nawias
            strm>>ln;
            std::cout<<ln;
            if(ln=='(') m=3;
            else{
                strm.putback(ln);
                m=10;
            }
            break;



            case 3: //czy liczba (z nawiasem)
                strm.getline(buffor,256,'\n');
                ZwrocWszystko(buffor,strm);
                if(!(strm>>lz.re)){  //NIE
                    strm.clear();
                    ZwrocWszystko(buffor,strm);
                    lz.re=0;
                    m=4;
                }
                else
                {
                    m=5;
                }
                break;

            case 4: // czy + - (z nawiasem)[bez liczby]{(-i)(+i)(i)
                 strm>>znak;
                if(znak=='+' || znak=='-')
                {
                    strm>>i;
                    if(i=='i' && znak=='+') {
                        lz.im=1;
                        m=8;
                    }
                    if(i=='i' && znak=='-' ){
                        lz.im=-1;
                        m=8;
                    }
                    if(i!='i') {
                        m=0;
                    }
                } else
                if(znak=='i')
                {
                    lz.im=1;
                    m=8;
                }
                else m=0;
                break;



            case 5: //czy (liczb liczba )
                strm.getline(buffor,256,'\n');
                ZwrocWszystko(buffor,strm);
                if(!(strm>>lz.im)){  //NIE
                    strm.clear();
                    ZwrocWszystko(buffor,strm);
                    m=6;
                }
                else
                {
                    m=7;
                }
                break;


            case 6: //(liczba i)
            break;


            case 7:  // czy i ()
                strm>>i;
                if(i=='i') m=8;
                else m=0;
                break;



            case 8: //czy prawy nawias )
            strm>>pn;
            if(pn==')') m=1;
            else m=0;
            break;

        }
    }
    return  strm; */
}
LZespolona Sprzezenie(LZespolona lz)
{
    lz.im=-lz.im;
    return lz;
}

double Modul(LZespolona lz)
{
    double mod = sqrt(lz.re*lz.re+ lz.im*lz.im);
    return mod;
}
LZespolona operator / (LZespolona lz, double lr)
{

    LZespolona Wynik;

    if(lr==0)
    {
        std::cerr<<"Dzielenie przez zero\n";
    }
    else
    {
        Wynik.re = lz.re / lr;
        Wynik.im = lz.im / lr;
        return Wynik;
    }
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
    LZespolona Sprz;

    Sprz=Sprzezenie(l2);

    Wynik=l1 * Sprz;
    Wynik= Wynik / (Modul(l2)*Modul(l2));
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


