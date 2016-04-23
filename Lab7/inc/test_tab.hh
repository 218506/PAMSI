#include "Istoper.hh"
#include "Irunnable.hh"
#include "tablica.hh"

#define ILOSC_OKRAZEN 10

//Klasa implementuje interfejsy Irunnable, Istoper
//oraz dziedziczy po klasie 
class test_tab: public Irunnable, public Tablica,public Istoper //test_tab=sedzia ?
{
protected:
  int size; //rozmiar problemu
  clock_t sta;
  clock_t end;
  int lap;
  float Tab_Wyn[ILOSC_OKRAZEN];
public:
  //Konstruktor ustawia wszystkie flagi na 0.
  test_tab();

  /**Irunnable**/
  //Gdy dobiegnie zwraca true
  virtual bool run(int dystans,int laps);

  /**Istoper**/
  virtual void start();

  virtual void stop();

  virtual long get_time();
  
  void wyswietl_wynik();
};
