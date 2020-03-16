#ifndef LZESPOLONA_STATYSTYKI_H
#define LZESPOLONA_STATYSTYKI_H


class Statystyki{
private:
    int dobre;
    int wszystkie;

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

float ZwrocWynik()
    {
        return (100*dobre/wszystkie);
    }


};


#endif