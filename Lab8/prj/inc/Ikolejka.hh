
class Ikolejka
{
public:
  //Sprawdzanie, czy kolejka jest pusta.
  virtual bool empty()=0;  
  
  //Wrzucanie elementu na koniec kolejki
  virtual void push(string element)=0;
  
  //Sciaganie elementu z poczatku kolejki.
  virtual string pop()=0;

  //Zwraca wartosc poczatkowa,bez jej usuwania.
  virtual string front()=0;

  //Zwraca wartosc statniego elemetu kolejki, bez jej usuwania.
  virtual string end()=0;
  
  //Zwraca ilosc elementow w kolejce.
  virtual int size()=0;
};
