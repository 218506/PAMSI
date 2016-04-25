/*!
 *\file
 *\brief Definicja klasy Lista, ktora implementuje interfejs Ilista.
 *
 * Plik ten zawiera definicje klasy Lista,
 * ktorej obiekty implementuja interfejs Ilista, oraz klasy Kaf,
 * ktora tworzy poszczegolne elementy listy.
 * Obiekty klasy typu Lista sklada sie z dwoch wskaznikow 
 * typu Kaf, ktore wskazuja na poczatek i koniec listy,
 * oraz z pola nr, ktore zawiera w sobie informacje o rozmiarze tablicy.
 */

#include "Ilista.hh"

class Kaf // Kafelka twrzaca liste
{
  Kaf* prev;
  Kaf* next;
  string wartosc;
  friend class Lista;
  friend class test_lista;
};

class Lista: public Ilista
{
protected:
  Kaf* przod;
  Kaf* tyl;
  int nr=0; //element dodany po to, by dac liscie swiadomosc swojego rozmiaru
public:

  /*!
   *\brief Konstruktor bezparametryczny dla obiektow klasy Lista.
   */
  Lista();
  
  /*!
   *\brief Konstruktor parametryczny dla obiektow klasy Lista.
   */
  Lista(string elem);

  /*!
   *\brief Metoda empty dla obiekyw klasy Lista.
   * Sprawdza czy na liscie znajduja sie jakies elementy.
   */
  virtual bool empty();  

  /*!
   *\brief Metoda get dla obiektow klasy Lista.
   * Zwraca wartosc z przodu listy, nie usuwajac elementu. 
   */
  virtual string get();

 /*!
   *\brief Metoda get dla obiektow klasy Lista.
   * Zwraca wartosc z tylu listy, nie usuwajac elementu. 
   */
  virtual string get_back();

  /*!
   *\brief Metoda size dla obiektow klasy Lista.
   * Zwraca ilosc elementow na liscie. 
   */
  virtual int size();

  /*!
   *\brief Metoda push_front dla obiektow klasy Lista.
   * Dodaje element na poczatek listy. 
   */
  virtual void push_front(string element);

  /*!
   *\brief Metoda push_back dla obiektow klasy Lista.
   * Dodaje element na koniec listy. 
   */
  virtual void push_back(string element);

  /*!
   *\brief Metoda push_ind dla obiektow klasy Lista.
   * Dodaje element we wskazane miejsce na liscie. 
   */
  virtual void push_ind(string element,int indeks);

  /*!
   *\brief Metoda pop_front dla obiektow klasy Lista.
   * Usuwana jeden element z przodu listy,zwraca jeg wartosc. 
   */
  virtual string pop_front();

  /*!
   *\brief Metoda pop_front dla obiektow klasy Lista.
   * Usuwana jeden element z tylu listy,zwraca jeg wartosc. 
   */
  virtual string pop_back();

  //Przeciazenie operatora = dla obiektow typu lista
  void operator=(string wo);

  /*!
   *\brief Destruktor dla obiektow klasy Lista.
   */
  ~Lista();

};
