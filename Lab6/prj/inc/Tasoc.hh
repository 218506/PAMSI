#include "Thash.hh"

class TabAsoc
{ 
  TabHash tab;
public:
  
  TabAsoc();

  int Hash(string key);
  
  Lista& operator [](string Key);
  
  ~TabAsoc();
};
