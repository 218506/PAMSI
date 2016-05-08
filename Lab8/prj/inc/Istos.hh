
class Istos
{
public:
  //Sprawdzanie, czy stos jest pusty.
  virtual bool empty()=0;  
  
  //Wrzucanie elementu na stos
  virtual void push(string element)=0;
  
  //Sciaganie elementu ze stosu
  virtual string pop()=0;
    
  //Usuwanie elementow od szczytu stosu do end, przy traceniu ich wartosci
  virtual void erase(int end)=0;

  //Zwraca wartosc ze szczytu stosu, bez jej usuwania.
  virtual string top()=0;
  
  //Zwraca ilosc elementow na stosie.
  virtual int size()=0;
};
