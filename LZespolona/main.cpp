#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.h"

using namespace std;
/*
int main()
{
    LZespolona l1= Utworz(3,3);
    Wyswietl(l1);
    LZespolona l2=Utworz(3,3);
    Wyswietl(l2);
    LZespolona l3=l1 + l2;
    Wyswietl(l3);
    l3=l1 - l2;
    Wyswietl(l3);
    l3=l1 * l2;
    Wyswietl(l3);
    l3= l1 / l2;
    Wyswietl(l3);
    cout << (l1 == l2) << "  " << (l1 != l2) << endl;
    WyrazenieZesp WyrZ;
    WyrZ.Arg1=l1;
    WyrZ.Op=Op_Dodaj;
    WyrZ.Arg2=l2;
    Wyswietl(WyrZ);

}
*/

int main(int argc, char **argv)
{
    argv[1]="latwy";
    argc++;
    Statystyki Staty;
    Staty.Zeruj();
    Staty.DodajDobra();
    Staty.DodajDobra();
    Staty.DodajWszystkie();
    Staty.DodajWszystkie();
    Staty.DodajWszystkie();
    Staty.DodajWszystkie();
    cout<< Staty.ZwrocWynik()<< endl;


  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    Wyswietl(WyrZ_PytanieTestowe);
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}

