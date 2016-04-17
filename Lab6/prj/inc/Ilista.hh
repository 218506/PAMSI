
class Ilista
{
public:
  //Sprawdzanie, czy lista jest pusta.
  virtual bool empty()=0;  
  
  //Wrzucanie elementu na poczatek listy
  virtual void push_front(string element)=0;
  
  //Wrzucanie elementu na koniec listy
  virtual void push_back(string element)=0;
  
  //Wrzucanie elementu na odpowiednie miejsce na liscie
  virtual void push_ind(string element,int indeks)=0;
  
  //Usuwanie jednego elementu z przodu listy,zwraca jeg wartosc.
  virtual string pop_front()=0;
  
  //Usuwanie jednego elementu z tylu listy,zwraca jeg wartosc.
  virtual string pop_back()=0;
  
  //Zwraca wartosc z przodu listy, nie usuwajac elementu.
  virtual string get()=0;

  //Zwraca wartosc z tylu listy, nie usuwajac elementu.
  virtual string get_back()=0;
  
  //Zwraca ilosc elementow na liscie.
  virtual int size()=0;
};
