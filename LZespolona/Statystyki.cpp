#include "Statystyki.h"

float Statystyki::ZwrocWynik()
{
    if(_wszystkie==0)return 0;
    return (100*_dobre/_wszystkie);
}
void Statystyki::Zeruj()
{
_dobre=0;
_wszystkie=0;
}
void Statystyki::DodajDobra()
{
    _dobre++;
}

void Statystyki::DodajWszystkie()
{
    _wszystkie++;
}

void Statystyki::WyswietlWynik()
{
    std::cout<<"Twoj wynik wynosi: "<<ZwrocWynik()<<"%\n";
}