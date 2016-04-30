#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sys/time.h>

using namespace std;

#include "test_bst.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy test_lista.
 * Plik ten zawierqa definicje funkcji oraz metod
 * dla obiektow klasy test_lista. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy test_lista.
 * Ustawia wszystkie pola klasy na 0;
 */
test_bst::test_bst()
{
  t1=0;
  t2=0;
}

/*!
 *\brief Metoda start.
 * Jest to jedna z metod, ktora implementuje metode czysto wirtualna
 * interfejsu Istoper. Uruchamia zegar i zapisuje wynik do 
 * pola listy sta.
 */
void test_bst:: start()
{
  gettimeofday(&tim, NULL);
  t1=tim.tv_sec+(tim.tv_usec/1000000.0);
}

/*!
 *\brief Metoda stop.
 * Jest to jedna z metod, ktora implementuje metode czysto wirtualna
 * interfejsu Istoper. Uruchamia zegar i zapisuje wynik do 
 * pola listy end.
 */
void test_bst:: stop()
{
  gettimeofday(&tim, NULL);
  t2=tim.tv_sec+(tim.tv_usec/1000000.0);
}

/*!
 *\brief Metoda stop.
 * Jest to jedna z funkcji dziedziczacych po metodzie czysto wirtualnej
 * interfejsu Istoper. Liczy czas, ktory uplynal pomiedzy
 * uruchomieniem i zatrzymaniem stopera.
 * \return Zwraca czas, ktory uplynal pomiedzy wywolaniem metoda start i stop.
 */
long test_bst:: get_time()
{
  return (t2-t1)*1000;
}

/*!
 *\brief Metoda wyswietl_wynik dla obiektow klasy test_lista.
 * Metoda ta wyswietla pole get_time na standardowym wyjsciu.
 */
void test_bst::wyswietl_wynik()
{
  cout << get_time() << endl;
}

/*!
 *\brief Metoda run.
 * Jest to jedna z metod implementujaca metode czysto wirtualna
 * interfejsu Irunnable. 
 * Jezeli podano odpowiednia ilosc plikow na wejscie, otwieramny
 * jest strumien plikowy i elementy z tego strumienia wpisywane sa
 * na liste. Nastepnie zamykany jest uchwyt do pliku i uruchomione
 * metody szukaj oraz losuj_slowo.
 * \param[in] - Argc jest to ilosc komend wpisanych w terminalu.
 * \param[in] - Argv[] - jest to tablica nazw komend wpisanych w terminalu.
 * \return -Zwraca true, gdy operacja zakonczona powodzeniem, w przeciwny wypadku false.
 */
bool test_bst:: run(int Argc,char* Argv[])
{
  if(Argc!=2)
    {
      cerr << "Niewlasciwa ilosc plikow na wejsciu."<< endl;
      return false;
    }
  else
    {
      //***************Obsluga pliku***************//
      //Wczytywanie wartosci do drzewa
      fstream plik; //zmienna pozwalajaca otworzyc strumien plikowy
      BST test;
      int tmp;
      //Pomiar czasu zapisu do drzewa
      start();
      plik.open(Argv[1],ios::in); //otwarcie strumienia plikowego
      if(plik.good()) //jezeli udalo sie otworzyc plik
	{
	  while(!plik.eof())
	    {
	      plik >> tmp;
	      test.insert(tmp);
	    }
	}
      plik.close(); //zamkniecie strumienia plikowego
      test.balance();
      stop();
      get_time();
      cerr<< "Czas zapisu: ";
      wyswietl_wynik();

      //Pomiar czasu wyszukiwania
      start();
      test.search(91232199); //wysukiwanie elementu, ktorego nei ma na drzewie
      stop();
      get_time();
      cerr<< "Czas wyszukiwania: ";
      wyswietl_wynik();
    }

  return true;
  //*********************************//
}

