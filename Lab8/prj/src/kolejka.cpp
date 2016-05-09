#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Kolejka.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy Kolejka.
 * Plik ten zawiera definicje funkcji oraz metod
 * dla obiektow klasy Kolejka. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy Kolejka.
 * Ustawia wskazniki kolejki na NULL;
 */
Kolejka:: Kolejka()
{
  przod=NULL;
  tyl=NULL;
}

/*!
 *\brief Konstruktor parametryczny dla obiektow klasy Kolejka
 * Tworzy kafelek i sprawia, ze oba wskazniki klasy Kolejka wskazuja na niego.
 * \param[in] elem - slowo, ktore ma zostac wpisane do kafelka.
 */
Kolejka::Kolejka(string elem)
{
  Ele* Kaf= new Ele;
  Kaf->wartosc=elem;
  Kaf->prev=NULL;
  Kaf->next=NULL;
  przod=Kaf;
  tyl=Kaf;
}

/*!
 *\brief Metoda empty dla obiektow klasy Kolejka
 * Metoda sprawdza, czy wskazniki klasy Kolejka nastawione sa na NULL.
 * Gdy tak- kolejka pusta, gdy nie-w kolejce znajduja sie elementy.
 * \return Zwraca true, gdy kolejka pusta w przeciwnym razie false.
 */
bool Kolejka:: empty()
{
  if(przod==NULL && tyl==NULL)
    return true;
  else
    return false;
}  

/*!
 *\brief Metoda push dla obiektow klasy Kolejka
 * Wpisuje ona nowy element na koniec kolejki.
 * Jezeli kolejka jest pusta, zostaja podjete dzialania analogiczne do tych
 * konstruktorze parametrycznym.
 * Jezeli w kolejce znajduje sie element wskaznik next nowego elementu
 * zaczyna wskazywac na ten same element na ktory wskazywal tyl, 
 * nastepnie wskaznik prev dotychczasowego ostatniego elementu zaczyna
 * wskazywac na nowy element. Przesuwam wskaznik tyl na nowy element,
 * wpisuje slowo w pole wartosc.
 * \param[in] element - Slowo, ktore ma zostac wpisane w nowy element.
 */
void Kolejka:: push(string element)
{
  Ele* Kaf= new Ele;
  Kaf->wartosc=element;
  if(empty())
    {
      Kaf->prev=NULL;
      Kaf->next=NULL;
      przod=Kaf;
    }
  else
    {
      tyl->prev=Kaf;
      Kaf->next=tyl;
      Kaf->prev=NULL;
    }
  tyl=Kaf;
}
  
/*!
 *\brief Metoda pop dla obiektow klasy Kolejka
 * Sciaga ona element z kolejki.
 * Jezeli kolejka jest pusta, wyswietlany jest odpowiedni komunikat.
 * Jezeli w kolejce znajduje sie element wprowadzam zmienna pomocnicza tmp
 * nastepnie sciagam wartosc kafelka do zmienneja.
 * Jezeli element jest jedyny w kolejce, wtedy
 * nastawiajac przod i tyl na NULL, potem kasuje tmp.
 * Jezeli nie jest to jedyny element na liscie, to przesuwam przod na poprzedni 
 * element, nastepnie kasuje tmp.
 * \return a - Slowo, ktore znajdowalo sie na sciagnietym elemencie.
 */
string Kolejka:: pop()
{
  Ele* tmp;
  string wart="0";
  if(empty())
    {
      cerr <<"Nie ma czego usuwac" << endl;
      return wart;
    }
  else if(przod->next==NULL && przod->prev==NULL) // jezeli jeden element w kolejce
    {
      tmp=przod;
      przod=NULL;
      tyl=NULL;
      wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
  else
    {
      tmp=przod;
      przod=przod->prev;
      przod->next->prev=NULL;
      przod->next=NULL;
      wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
}

/*!
 *\brief Metoda front dla obiektow klasy Kolejka
 * Metoda zwraca wartosc slowa znajdujacego sie z przodu kolejki,
 * bez usuwania go.
 * \return Zwraca wartosc elementu, ktory znajduje sie na przodzie kolejki.
 */
string Kolejka:: front()
{
  if(!empty())
    return przod->wartosc;
  else
    return "0";
}

/*!
 *\brief Metoda end dla obiektow klasy Kolejka
 * Metoda zwraca wartosc slowa znajdujacego sie z tylu kolejki,
 * bez usuwania go.
 * \return Zwraca wartosc elementu, ktory znajduje sie z tylu kolejki.
 */
string Kolejka:: end()
{
  if(!empty())
    return tyl->wartosc;
  else
    return "0";
}

/*!
 *\brief Metoda size dla obiektow klasy Kolejka
 * Metoda tworzy zmienna pomocnicza buf, ktora wskazuje na to samo
 * miejsce co poczatek kolejki a nastepnie poprzez wskaznik na poprzedni
 * element przesuwa sie az do konca kolejki, przy okazji zwiekszajac
 * n. Gdy napotka NULL oznacza to, ze zmienna dotarla do konca kolejki.
 * \return n - Zwraca rozmiar kolejki.
 */
int Kolejka:: size()
{
  Ele* buf;
  int n=0;
  buf=przod;
  while(buf!=NULL)
    {
      n++;
      buf=buf->prev;
    }
  delete buf;
  return n;
}

/*!
 * \brief Destruktor elementow klasy Kolejka.
 * Usuwa obiekty klasy Kolejka po zakonczeniu pracy programu/funkcji.
 * Przechodzi po kazdym z elementow kolejki i kasuje je.
 * Gdy ilosc elementow jest rowna jeden, kasuje go a nastepnie nastawiam
 * wszystkie wskazniki na NULL.
 */
Kolejka::~Kolejka()
{
  if(!empty())
    {
      Ele* tmp;
      while(przod!=tyl)
	{
	  tmp=przod;
	  przod=przod->prev;
	  tmp->next=NULL;
	  tmp->prev=NULL;
	  delete tmp;
	}
      tmp=przod;
      przod=NULL;
      tyl=NULL;
      delete tmp;
    }
}
