#ifndef LZESPOLONA_STATYSTYKI_H
#define LZESPOLONA_STATYSTYKI_H

#include <iostream>


class Statystyki{
private:

    int dobre;
    int wszystkie;

    float ZwrocWynik()
    {
        return (100*dobre/wszystkie);
    }

public:

void Zeruj()
    {
        dobre=0;
        wszystkie=0;
    }
void DodajDobra()
    {
        dobre++;
    }

void DodajWszystkie()
    {
        wszystkie++;
    }

void WyswietlWynik()
    {
        std::cout<<"Twoj wynik wynosi: "<<ZwrocWynik()<<"%\n";
    }


};


#endif