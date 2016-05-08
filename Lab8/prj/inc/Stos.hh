/*!
 *\file
 *\brief Definicja klasy Stos, ktora implementuje interfejs Istos.
 *
 * Plik ten zawiera definicje klasy Stos,
 * ktorej obiekty implementuja interfejs Istos, oraz definicje klasy Elem,
 * ktora tworzy poszczegolne elementy stosu.
 * Obiekty klasy Stos skladaja sie z wskaznika 
 * typu Elem, ktory wskazuje na szczyt stosu. Stos ten
 * zaimplementowany jest na liscie jednokierunkowej, poniewaz
 * w pelni wystarcza ona do optymalnej nawigacji po
 * odpowiednich elementach stosu(pop/push wymagaja dostepu jedynie
 * do szczytowego elemwentu).
 */

#include "Istos.hh"

class Elem
{
  Elem* prev;
  string wartosc;
  friend class Stos;
};

class Stos: public Istos
{
protected:
  Elem* przod;
public:
  /*!
   *\brief Konstruktor bezparametryczny dla obiektow klasy Stos.
   */
  Stos();

  /*!
   *\brief Konstruktor parametryczny dla obiektow klasy Stos.
   */
  Stos(string element);

  /*!
   *\brief Metoda empty dla obiektow klasy Stos.
   * Sprawdza czy na stosie znajduja sie jakies elementy.
   */
  virtual bool empty();

  /*!
   *\brief Metoda push dla obiektow klasy Stos.
   * Dodaje element na szczyt stosu. 
   */
  virtual void push(string element);

  /*!
   *\brief Metoda pop dla obiektow klasy Stos.
   * Usuwana element ze szczytu stosu,zwraca jeg wartosc. 
   */
  virtual string pop();

  /*!
   *\brief Metoda erase dla obiektow klasy Stos.
   * Usuwana wybrana ilosc elementow ze szczytu stosu, wartosci ich sa tracone. 
   */
  virtual void erase(int end);

  /*!
   *\brief Metoda top dla obiektow klasy Stos.
   * Zwraca wartosc elementu ze szczytu stosu, nie usuwajac przy tym elementu. 
   */
  virtual string top();

  /*!
   *\brief Metoda size dla obiektow klasy Stos.
   * Zwraca ilosc elementow na stosie. 
   */
  virtual int size();

  /*!
   *\brief Destruktor dla obiektow klasy Stos.
   */
  ~Stos();
};
