/*!
 *\file
 *\brief Definicja klasy Kolejka, ktora implementuje interfejs Ikolejka.
 *
 * Plik ten zawiera definicje klasy Kolejka,
 * ktorej obiekty implementuja interfejs Ikolejka, oraz definicje klasy Ele,
 * ktora tworzy poszczegolne elementy kolejki.
 * Obiekty klasy Kolejka skladaja sie z dwoch wskaznikow 
 * typu Ele, ktore wskazuja na poczatek i koniec kolejki. Kolejka
 * ta zaimplementowana jest na liscie dwukierunkowej, aby ulatwic
 * dostep do pierwszego i ostatniego elementu, oraz nawigacje po
 * odpowiednich elementach kolejki(przesuwanie wskaznika przod/tyl).
 */

#include "Ikolejka.hh"

class Ele
{
  Ele* prev;
  Ele* next;
  string wartosc;
  friend class Kolejka;
};

class Kolejka: public Ikolejka
{
protected:
  Ele* przod;
  Ele* tyl;
public:

  /*!
   *\brief Konstruktor bezparametryczny dla obiektow klasy Kolejka.
   */
  Kolejka();

  /*!
   *\brief Konstruktor parametryczny dla obiektow klasy Kolejka.
   */
  Kolejka(string elem);

  /*!
   *\brief Metoda empty dla obiekyw klasy Kolejka.
   * Sprawdza czy w kolejce znajduja sie jakies elementy.
   */
  virtual bool empty();  

  /*!
   *\brief Metoda push dla obiektow klasy Kolejka.
   * Dodaje element na koniec kolejki. 
   */
  virtual void push(string element);

  /*!
   *\brief Metoda pop dla obiektow klasy Kolejka.
   * Usuwana jeden element z przodu kolejki,zwraca jeg wartosc. 
   */
  virtual string pop();

  /*!
   *\brief Metoda front dla obiektow klasy Kolejka.
   * Zwraca wartosc elementu z przodu kolejki, nie usuwajac elementu. 
   */
  virtual string front();

  /*!
   *\brief Metoda end dla obiektow klasy Kolejka.
   * Zwraca wartosc elementu z tylu kolejki, nie usuwajac elementu. 
   */
  virtual string end();

  /*!
   *\brief Metoda size dla obiektow klasy Kolejka.
   * Zwraca ilosc elementow w kolejce. 
   */
  virtual int size();

  /*!
   *\brief Destruktor dla obiektow klasy Kolejka.
   */
  ~Kolejka();
};
