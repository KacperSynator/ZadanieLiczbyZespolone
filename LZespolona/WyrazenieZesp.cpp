#include "WyrazenieZesp.hh"
#include <iostream>


std::istream & operator >> (std::istream & strm, WyrazenieZesp & WyrZ)
{
    strm>>WyrZ.Arg1 >> WyrZ.Op >> WyrZ.Arg2;
    return strm;
}
std::istream & operator >> (std::istream & strm, Operator & op)
{
    char znak;
    strm>>znak;
    switch (znak)
    {
        case '+':
            op=Op_Dodaj;
            break;
        case '-':
            op=Op_Odejmij;
            break;
        case '*':
            op=Op_Mnoz;
            break;
        case '/':
            op=Op_Dziel;
            break;
    }
    return strm;
}
std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & Wz)
{
    strm<< Wz.Arg1 << Wz.Op << Wz.Arg2;
    return strm;
}
std::ostream & operator << (std::ostream & strm, const Operator & op)
{
    switch (op)
    {
        case Op_Dodaj:
            strm<<'+';
            break;
        case Op_Odejmij:
            strm<<'-';
            break;
        case Op_Mnoz:
            strm<<'*';
            break;
        case Op_Dziel:
            strm<<'/';
            break;
    }
    return strm;
}


LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    LZespolona Wynik;
    switch (WyrZ.Op)
    {
        case Op_Dodaj:
            Wynik = WyrZ.Arg1 + WyrZ.Arg2;
            break;

        case Op_Odejmij:
            Wynik = WyrZ.Arg1 - WyrZ.Arg2;
            break;

        case Op_Mnoz:
            Wynik = WyrZ.Arg1 * WyrZ.Arg2;
            break;

        case Op_Dziel:
            Wynik = WyrZ.Arg1 / WyrZ.Arg2;
            break;
    }
    return Wynik;
}