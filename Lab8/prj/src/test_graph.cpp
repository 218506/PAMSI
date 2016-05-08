#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sys/time.h>
#include <random>

using namespace std;


#include "test_graph.hh"

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
test_graph::test_graph()
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
void test_graph:: start()
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
void test_graph:: stop()
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
long test_graph:: get_time()
{
  return (t2-t1)*1000;
}

/*!
 *\brief Metoda wyswietl_wynik dla obiektow klasy test_lista.
 * Metoda ta wyswietla pole get_time na standardowym wyjsciu.
 */
void test_graph::wyswietl_wynik()
{
  cout << get_time() << endl;
}

bool test_graph:: prepare(int Ver, int Edg)
{
  
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> uni(0,Ver-1);

  this->Test=Graph(Edg,Ver);

  //1.Tworzenie szkieletu (gwarantuje graf spojny)

  for(int i=0; i< Ver-1;i++)
    {
      Test.addEdge(i,i+1,1);
      Test.addEdge(i+1,i,1);
    }
  
  //2. Dolosowuje kilka losowych polaczen (zwykle 30% wszystkich krawedzi)
  
  for(int i=0;i<Edg;i++)
    {
      int a=uni(rng);
      int b=uni(rng);
      if(a==b) //self loop
	Test.addEdge(a,b,1);
      else 
	{
	  Test.addEdge(a,b,1);
	  Test.addEdge(b,a,1);
	}
    }


  /*
  //Graf testowy
  Test.addEdge(3,0,1);
  Test.addEdge(0,1,1);
  Test.addEdge(1,0,1);
  Test.addEdge(1,4,1);
  Test.addEdge(4,1,1);
  Test.addEdge(4,6,1);
  Test.addEdge(6,4,1);
  Test.addEdge(6,0,1);
  Test.addEdge(0,6,1);
  Test.addEdge(0,3,1);
  Test.addEdge(1,5,1);
  Test.addEdge(5,1,1);
  Test.addEdge(3,5,1);
  Test.addEdge(5,3,1);
  Test.addEdge(5,2,1);
  Test.addEdge(2,5,1);
  Test.addEdge(7,2,1);
  Test.addEdge(2,7,1);
  */

  Test.DFS(0);

  return true;
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
bool test_graph:: run()
{
  start();
  stop();
  get_time();
  cerr<< "Czas zapisu: ";
  wyswietl_wynik();
  
  //Pomiar czasu wyszukiwania
  start();
  stop();
  get_time();
  wyswietl_wynik();
  return true;
}

