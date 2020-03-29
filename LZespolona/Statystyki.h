#ifndef LZESPOLONA_STATYSTYKI_H
#define LZESPOLONA_STATYSTYKI_H

#include <iostream>


class Statystyki{
private:

    int _dobre;
    int _wszystkie;

    float ZwrocWynik();

public:

void Zeruj();
void DodajDobra();
void DodajWszystkie();
void WyswietlWynik();

};


#endif