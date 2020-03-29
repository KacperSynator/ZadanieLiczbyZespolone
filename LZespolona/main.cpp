#include <iostream>
#include "BazaTestu.hh"
#include "Statystyki.h"
#include <fstream>

#define DUZO 10000

using namespace std;

int main(int argc, char **argv) {
    argv[1] = "trudny";
    argc++;
    Statystyki Staty;
    Staty.Zeruj();

    if (argc < 2) {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }
// Z pliku
    std::fstream strm_plik;
    if(!InicjalizujTestPlik(argv[1],strm_plik))
    {
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }
    std::istream & strm=strm_plik;
    WyrazenieZesp Pytanie;
    LZespolona Odp;
    while(PobierzNastpnePytaniePlik(strm,&Pytanie))
    {
        int n=0;
        cout << "Napisz wynik ponizszego dzialania"<<endl;
        cout << Pytanie << endl;
        cout << "Twoja odpowiedz: ";
        cin >> Odp;
        cout<< endl;
        while(n<2 && !(cin.good()))
        {
            cin.clear();
            cin.ignore(DUZO,'\n');
            cout << "Niepoprawny format liczby zespolonej" << endl;
            cout << "Sprobuj ponownie" << endl;
            cout << "Twoja odpowiedz: ";
            cin >> Odp;
            cout << endl;
            n++;
        }
        if(n>=2 && !(cin.good()))
        {
            cin.clear();
            cin.ignore(DUZO,'\n');
            cout << "Blad wczytania po raz trzeci" << endl;
            cout << "Pobieranie kolejnego pytania" << endl;
            Staty.DodajWszystkie();
        }
        else
        {
            if (Odp == Oblicz(Pytanie))
            {
                cout<<"To jest dobra odpowiedz "<< " ;) "<< endl;
                Staty.DodajDobra();
                Staty.DodajWszystkie();
            }
            else
            {
                cout<<"To jest zła odpowiedz "<<" :( "<< endl;
                cout<<"Dobra odpowiedź to:"<< Oblicz(Pytanie) <<endl;
                Staty.DodajWszystkie();
            }
        }
    }
    strm_plik.close();

    cout << endl;
    cout << " Koniec testu" << endl;
    Staty.WyswietlWynik();
    cout << endl;
  /********************* z BazyTestu *********************************
    BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp;


  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
  {
      int n=0;
      cout << "Napisz wynik ponizszego dzialania"<<endl;
      cout << WyrZ_PytanieTestowe << endl;
      cout << "Twoja odpowiedz: ";
      cin >> Odp;
      cout<< endl;
      while(n<2 && !(cin.good()))
      {
          cin.clear();
          cout << "Niepoprawny format liczby zespolonej" << endl;
          cout << "Sprobuj ponownie" << endl;
          cout << "Twoja odpowiedz: ";
          cin >> Odp;
          cout << endl;
          n++;
      }
      if(n>=2 && !(cin.good()))
      {
          cin.clear();
          cout << "Blad wczytania po raz trzeci" << endl;
          cout << "Pobieranie kolejnego pytania" << endl;
          Staty.DodajWszystkie();
      }
      else
      {
          if (Odp == Oblicz(WyrZ_PytanieTestowe))
          {
              cout<<"To jest dobra odpowiedz "<< " ;) "<< endl;
              Staty.DodajDobra();
              Staty.DodajWszystkie();
          }
          else
          {
              cout<<"To jest zła odpowiedz "<<" :( "<< endl;
              Staty.DodajWszystkie();
          }
      }
  }

  cout << endl;
  cout << " Koniec testu" << endl;
  Staty.WyswietlWynik();
  cout << endl;

}
*/
}