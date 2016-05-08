#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Stos.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy Stos.
 * Plik ten zawiera definicje funkcji oraz metod
 * dla obiektow klasy Stos. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy Stos.
 * Ustawia wskaznik przodu stosu na NULL;
 */
Stos::Stos()
{
  przod=NULL;
}

/*!
 *\brief Konstruktor parametryczny dla obiektow klasy Stos
 * Tworzy kafelek i sprawia, ze wskaznik klasy stos wskazuja na niego.
 * \param[in] elem - slowo, ktore ma zostac wpisane do kafelka.
 */
Stos::Stos(string element)
{
  Elem* Kaf=new Elem;
  Kaf->wartosc=element;
  Kaf->prev=NULL;
  przod=Kaf;
}

/*!
 *\brief Metoda empty dla obiektow klasy Stos
 * Metoda sprawdza, czy wskaznik klasy Stos nastawione sa na NULL.
 * Gdy tak- stos pusty, gdy nie-na stosie znajduja sie elementy.
 * \return Zwraca true, gdy stos pusty w przeciwnym razie false.
 */
bool Stos::empty()
{
  if(przod==NULL)
    return true; //1
  else
    return false; //0
}

/*!
 *\brief Metoda push dla obiektow klasy Stos
 * Wpisuje ona nowy element na szczyt stosu.
 * Jezeli stos jest pusty, zostaja podjete dzialania analogiczne do tych
 * konstruktorze parametrycznym.
 * Jezeli na stosie znajduja sie elementy wskaznik prev nowego elementu
 * zaczyna wskazywac na ten sam element na ktory wskazywal przod, 
 * Nastepnie przesuwam wskaznik przod na nowy element,
 * wpisuje slowo w pole wartosc.
 * \param[in] element - Slowo, ktore ma zostac wpisane w nowy element.
 */
void Stos::push(string element)
{
  Elem* Kaf=new Elem;
  Kaf->wartosc=element;
  if(empty()) //pushowanie na pusty stos, jak w konstruktorze
    {
      Kaf->prev=NULL;
    }
  else //pushowanie na stos z elementami
    {
      Kaf->prev=przod;
    }  
  przod=Kaf;
}

/*!
 *\brief Metoda pop dla obiektow klasy Stos
 * Sciaga ona element ze stosu.
 * Jezeli stos jest pusty, wyswietlany jest odpowiedni komunikat i zwracane jest 0.
 * Jezeli na stosie znajduje sie element wprowadzam zmienna pomocnicza tmp,
 * ktora zaczyna wskazywac na to, na co wskazywal przod,
 * nastepnie sciagam wartosc kafelka do zmiennej wart, przesuwam przod 
 * na poprzedni element, nastepnie kasuje tmp.
 * \return wart - Slowo, ktore znajdowalo sie na sciagnietym elemencie lub 0
 * w przypadku braku elementu na stosie.
 */
string Stos::pop()
{
  if(empty())
    {
      cerr << "Stos pusty."<< endl;
      return "0";
    }
  else
    {
      Elem* tmp= przod;
      przod=przod->prev;
      tmp->prev=NULL;
      string wart=tmp->wartosc;
      delete tmp;
      return wart;
    }
}

/*!
 *\brief Metoda erase dla obiektow klasy Stos
 * Sciaga ona wybrana ilosc element ze stosu, przy traceniu ich wartosci.
 * Reazlizowana jest po prostu poprzez wywołanie metody pop zadana ilosc razy.
 */
void Stos::erase(int end)
{
  for(int i=0; i<end;i++)
    pop();
}

/*!
 *\brief Metoda top dla obiektow klasy Stos
 * Metoda zwraca wartosc slowa znajdujacego sie na szczycie stosu,
 * bez usuwania go.
 * \return Zwraca wartosc elementu, ktory znajduje sie na szczycie stosu. Jezeli stos 
 * jest pusty zwraca 0.
 */
string Stos::top()
{
  if(!empty())
    return przod->wartosc;
  else
    return "0";
}

/*!
 *\brief Metoda size dla obiektow klasy Stos
 * Metoda tworzy zmienna pomocnicza buf, ktora wskazuje na to samo
 * miejsce co wskaznik przod a nastepnie poprzez wskaznik na poprzedni
 * element (prev) przesuwa sie az do konca stosu, przy okazji zwiekszajac
 * n. Gdy napotka NULL oznacza to, ze buf dotarl do konca stosu.
 * \return n - Zwraca rozmiar stosu.
 */
int Stos::size()
{
  Elem* buf=przod;
  int siz=0;
  while(buf!=NULL)
    {
      siz++;
      buf=buf->prev;
    }
  delete buf;
  return siz;
}

/*!
 * \brief Destruktor elementow klasy Stos.
 * Usuwa obiekty klasy Stos po zakonczeniu pracy programu/funkcji.
 * Przechodzi po kazdym z elementow stosu i kasuje je.
 */
Stos::~Stos()
{
  if(!empty())
    {
      Elem* tmp;
      while(przod!=NULL)
	{
	  tmp=przod;
	  przod=przod->prev;
	  tmp->prev=NULL;
	  delete tmp;
	}
      delete przod;
    }
}
