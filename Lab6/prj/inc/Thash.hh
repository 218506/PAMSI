#include "Lista.hh"

class TabHash
{
  Lista* MainTab;
  int s;
public:

  TabHash();

  void set_size(int siz);

  int Hash(string Key);

  //rwywolanie tab["klucz"]="x" jest
  //rownoznaczne z metoda insert(key,elem)
  Lista& operator[](string Key);

  //zwraca numer slowa szukanego sear_word
  //ktore znajduje sie na liscie o kluczu Key
  int search(string Key, string sear_word);

  ~TabHash();

};
