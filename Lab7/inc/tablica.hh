
#include "Itablica.hh"

class Tablica : public ITablica //klasa Tablica implementuje
{                                  //interfejs Itablica
private:
  int *Tab=NULL;
  int n=0;
public:
  //Kontruktor tworzy pusta tablice 1 elementowa.
  Tablica();
  //Knstruktor tworzy tablice a-elementowa wypelniona 0.
  Tablica(int a);

  //Metoda dopisuje do tablicy na miejsce "in" wyraz "x", wykorzystuje algorytm
  //dodawania po jednym wyrazie do tablicy.
  void dopisz(int in, int x);

  //Metoda dopisuje do tablicy na miejsce "in" wyraz "x", wykorzystuje algorytm
  //dodawania podwajania istniejacej tablicy. 
  void dopiszx2(int in, int x);

  //Metoda docina tablice do podanego indeksu "in".
  void dotnij(int in);

  //Metoda wyswietla tablice na standardowym wyjsciu
  virtual void wyswietl();

  //Przeciazenie operatora [] dla obiektu typu tablica.
  int& operator [](int i);

  //Destruktor klasy, usuwa tablice i zwalnia pamiec.
  ~Tablica();
};
