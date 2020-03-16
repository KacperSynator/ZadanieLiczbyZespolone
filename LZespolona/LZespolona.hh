#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
    double   re;    /*! Pole repezentuje czesc rzeczywista. */
    double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona l1, LZespolona l2);
LZespolona operator * (LZespolona l1, LZespolona l2);
LZespolona operator / (LZespolona l1, LZespolona l2);
bool operator  == (LZespolona l1,LZespolona l2);
bool operator  != (LZespolona l1,LZespolona l2);
LZespolona DzielenieRrzeczywiste(LZespolona lz, double lr);
LZespolona Utworz(double re, double im);
void Wyswietl(LZespolona lz);
bool Wczytaj(LZespolona *lz);
void Sprzezenie(LZespolona *lz);
double Modul(LZespolona lz);


#endif
