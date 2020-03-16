#include "WyrazenieZesp.hh"


void Wyswietl(WyrazenieZesp  WyrZ)
{
    std::cout<< '(' << WyrZ.Arg1.re << std::showpos << WyrZ.Arg1.im << std::noshowpos << ')' << (char)WyrZ.Op <<'(' << WyrZ.Arg2.re << std::showpos << WyrZ.Arg2.im << std::noshowpos << ")\n";
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