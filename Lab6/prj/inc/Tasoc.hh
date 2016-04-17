#include "Thash.hh"

class TabAsoc
{ 
  TabHash tab;
public:
  
  TabAsoc(int size);

  int Hash(string key);
  
  Lista& operator [](string Key);
  
  //zwraca numer slowa szukanego sear_word
  //ktore znajduje sie na liscie o kluczu Key
  int search(string Key, string sear_word);

  ~TabAsoc();
};
