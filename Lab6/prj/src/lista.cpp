#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy Lista.
 * Plik ten zawierqa definicje funkcji oraz metod
 * dla obiektow klasy Lista. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy Lista.
 * Ustawia wskazniki listy na NULL;
 */
Lista:: Lista()
{
  przod=NULL;
  tyl=NULL;
}

/*!
 *\brief Konstruktor parametryczny dla obiektow klasy Lista
 * Twrzy kafelek i sprawia, ze oba wskazniki klasy Lista wskazuja na niego.
 * \param[in] elem - slowo, ktore ma zostac wpisane do kafelka.
 */
Lista:: Lista(string elem)
{
  Kaf* kafelek=new Kaf(); //tworze nowy kafelek
  kafelek->next=NULL; //nastepny element to NULL
  kafelek->prev=NULL; //poprzedni element to NULL
  kafelek->wartosc=elem; //nadanie wartsci kafelka
  przod=kafelek;     //wskaznik przod klasy Lista wsakazuje na nowy kafelek
  tyl=kafelek;      //tyl rowniez
  nr++;
}

/*!
 *\brief Metoda empty dla obiektow klasy Lista
 * Metoda sprawdza, czy wskazniki klasy Lista nastawione sa na NULL.
 * Gdy tak- lista pusta, gdy nie-na liscie znajduje sie element.
 * \return Zwraca true, gdy lista pusta w przeciwnym razie false.
 */
bool Lista:: empty()
{
  if(przod==NULL && tyl==NULL)
    {
      return true;
    }
  else
    {
      return false;
    }
}

/*!
 *\brief Metoda get dla obiektow klasy Lista
 * Metoda sprawdza co znajduje sie w miejscu pola wartosc.
 * \return Zwraca wartosc elementu, ktory znajduje sie na przodie listy.
 */
string Lista:: get()
  {
    if(!empty())
      return przod->wartosc;
    else
      return "0";
  }

/*!
 *\brief Metoda size dla obiektow klasy Lista
 * Metoda tworzy zmienna pomocnicza bufo, ktora wskazuje na to samo
 * miejsce co poczatek listy a nastepnie poprzez wskaznik na poprzedni
 * element przesuwa sie az do konca listy, przy okazji zwiekszajac
 * n. Gdy napotka NULL oznacza to, ze zmienna dotarla do konca listy.
 * \return n - Zwraca rozmiar listy.
 */
int Lista:: size()
{
  int n=0;
  Kaf* bufo=przod;
  if(!empty())
    {
      while(bufo!=NULL)
	{
	  bufo=bufo->prev;
	  n++;
	}
    }
  delete bufo;
  return n;
}

/*!
 *\brief Metoda push_front dla obiektow klasy Lista
 * Wpisuje ona nowy element na przod listy.
 * Jezeli lista jest pusta, zostaja podjete dzialania analogiczne do tych
 * konstruktorze parametrycznym.
 * Jezeli na liscie znajduje sie element wskaznik prev nowego elementu
 * zaczyna wskazywac na ten same element na ktory wskazywal przod, 
 * nastepnie wskaznik next dotychczasowego pierwszego elementu zaczyna
 * wskazywac na nowy element. Przesuwam wskaznik przod na nowy element,
 * wpisuje slowo w pole wartosc
 * \param[in] element - Slowo, ktore ma zostac wpisane w nowy element.
 */
void Lista::push_front(string element)
{
  Kaf* kafelek2=new Kaf();
  kafelek2->next=NULL;
  kafelek2->wartosc=element;
  if(empty()) 
    { 
      kafelek2->prev=NULL; 
      przod=kafelek2;     
      tyl=kafelek2;
    }
  else
    {
      kafelek2->prev=przod;
      przod->next=kafelek2;
      przod=kafelek2;
    }
  nr++;  
}


/*!
 *\brief Metoda push_back dla obiektow klasy Lista
 * Wpisuje ona nowy element na tyl listy.
 * Jezeli lista jest pusta, zostaja podjete dzialania analogiczne do tych
 * przy konstruktorze parametrycznym.
 * Jezeli na liscie znajduje sie element wskaznik next nowego elementu
 * zaczyna wskazywac na ten same element na ktory wskazywal tyl, 
 * nastepnie wskaznik prev dotychczasowego ostatniego elementu zaczyna
 * wskazywac na nowy element. Przesuwam wskaznik tyl na nowy element,
 * wpisuje slowo w pole wartosc.
 * \param[in] element - Slowo, ktore ma zostac wpisane w nowy element.
 */
void Lista::push_back(string element)
{
  Kaf* kafelek2=new Kaf();
  kafelek2->prev=NULL;
  kafelek2->wartosc=element; 
  if(empty()) 
    {
      kafelek2->next=NULL; 
      przod=kafelek2;     
      tyl=kafelek2;
      nr++;  
    }
  else
    {
      kafelek2->next=tyl;
      tyl->prev=kafelek2;
      tyl=kafelek2;
    }
  nr++;
}

/*!
 *\brief Metoda push_ind dla obiektow klasy Lista
 * Wpisuje ona nowy element w dowolne miejsce na liscie.
 * Jezeli lista jest pusta, zostaja podjete dzialania analogiczne do tych
 * konstruktorze parametrycznym.
 * Jezeli indeks przewyzsza rozmiar tablicy(ktory jest zapisany w zmiennej nr)
 * wtedy podejmowane jest dzialanie analogiczne do tego w push_front
 * Jezeli indeks jest mniejszy niz rozmiar tablicy
 * cofam sie dzieki zmiennej pomocnicznej tmp do odpowiedniego miejscs
 * i zmieniam wartosc pola element.
 * Jezeli na liscie znajduje sie element wskaznik 
 * \param[in] element - Slowo, ktore ma zostac wpisane w nowy element.
 * \param[in] ind - Miejsce, w ktore ma zostac wpisany nowy element.
 */
void Lista::push_ind(string element,int indeks)
{
  Kaf* kafelek2=new Kaf();
  if(empty()) 
    {
      kafelek2->next=NULL; 
      kafelek2->prev=NULL; 
      kafelek2->wartosc=element;
      przod=kafelek2;     
      tyl=kafelek2;
      nr++;  
    }
  else
    {
      if(indeks >= nr)
      {
	przod->next=kafelek2;
	kafelek2->prev=przod;
	cout<<"Nr:  " <<nr<<endl;
	przod=kafelek2; 
	kafelek2->wartosc=element;
	nr++;
      }
      else //zmieniam wartosc zadanego kafelka
	{
	  if(nr==1)
	    przod->wartosc=element;
	  else
	    {
	      Kaf* tyl_tmp=tyl; //wsk na tylni element
	      for(int i=0; i<indeks;i++)
		{
		  tyl=tyl->next;
		}
	      tyl->wartosc=element; 
	      tyl=tyl_tmp;
	    }
	}
    }
}

/*!
 *\brief Metoda pop_front dla obiektow klasy Lista
 * Sciaga ona element z przodu listy.
 * Jezeli lista jest pusta, wyswietlany jest odpowiedni komunikat.
 * Jezeli na liscie znajduje sie element wprowadzam zmienna pomocnicza tmp
 * nastepnie sciagam wartosc kafelka do zmienneja.
 * Jezeli element jest jedyny na liscie, wtedy sprawiam, ze lista jest pusta,
 * nastawiajac przod i tyl na NULL, potem kasujac tmp.
 * Jezeli nie jest to jedyny element na liscie, to przesuwam przod na poprzedni 
 * element, nastepnie kasuje tmp.
 * Za kazdym razem zmniejszam wartosc nr, by nastawic odpowiedni rozmiar
 * listy.
 * \return a - Slowo, ktore znajdowalo sie na sciagnietym elemencie.
 */
string Lista:: pop_front()
{
  if(empty()) // Jezeli lista pusta
    {
      cerr <<"Nie ma czego usuwac." << endl;
      return "0";
    }
  else
    {
      Kaf* tmp= przod; //zmienna pomocnicza
      string a=tmp->wartosc; //pobranie wartosci
      if(przod->prev==NULL) //Jezeli jeden element na liscie
	{
	  przod=NULL;
	  tyl=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp;
	}
      else
	{
	  przod=przod->prev; //cofniecie wskaznika z pierwszego kaf na drugi kaf
	  przod->next=NULL; //"odciecie" polaczenia z popowanym kafelkiem
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp; //zwolnienie pamieci
	  nr--; //zmniejszenie rozmiaru listy 
	}
      return a;
    }
}

/*!
 *\brief Metoda pop_back dla obiektow klasy Lista
 * Sciaga ona element z tylu listy.
 * Jezeli lista jest pusta, wyswietlany jest odpowiedni komunikat.
 * Jezeli na liscie znajduje sie element wprowadzam zmienna pomocnicza tmp
 * nastepnie sciagam wartosc kafelka do zmienneja.
 * Jezeli element jest jedyny na liscie, wtedy sprawiam, ze lista jest pusta,
 * nastawiajac przod i tyl na NULL, potem kasujac tmp.
 * Jezeli nie jest to jedyny element na liscie, to przesuwam tyl na nastepny 
 * element, nastepnie kasuje tmp.
 * Za kazdym razem zmniejszam wartosc nr, by nastawic odpowiedni rozmiar
 * listy.
 * \return a - Slowo, ktore znajdowalo sie na sciagnietym elemencie.
 */  
string Lista:: pop_back()
{
  if(empty()) // Jezeli lista pusta
    {
      cerr << "Nie ma czego usuwac" <<endl;
      return "0";
    }
  else
    {
      Kaf* tmp=tyl;
      string a=tmp->wartosc;
      if(tyl->next==NULL)//jezeli jeden element na tablicy
	{
	  tyl=NULL;
	  przod=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp;
	}
      else //jezeli wiecej elementow na tablicy
	{
	  tyl=tyl->next;
	  tyl->prev=NULL;
	  tmp->next=NULL;
	  tmp->prev=NULL;
	  delete tmp;
	  nr--;
	}
      return a;
    }
}

//Przeciazenie operatora = dla obiektow typu lista
void Lista::operator=(string wo)
{
  this->push_front(wo);
}



/*!
 * \brief Destruktor elementow klasy lista.
 * Usuwa obiekty klasy Lista po zakonczeniu pracy programu/funkcji.
 * Przechodzi po kazdym z elementow listy i kasuje je.
 * Gdy ilosc elementow jest rowna jeden, kasuje go a nastepnie nastawiam
 * wszystkie wskazniki na NULL.
 */
Lista:: ~Lista()
{
  if(!empty())
    {
      while(przod!=tyl) //dopoki wskazniki nie wskazuja na to samo(jeden el na liscie)
	{
	  Kaf* tmp=przod;
	  przod=przod->prev;
	  przod->next=NULL;
	  tmp->next=NULL; 
	  tmp->prev=NULL;
	  delete tmp; //zwolnienie pamieci
	}
      Kaf* tmp=przod;
      tyl=NULL;
      przod=NULL;
      tmp->next=NULL; 
      tmp->prev=NULL;
      delete tmp;
      delete przod;
      delete tyl;
      nr=0;
    }
}
