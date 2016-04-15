#include "Lista.hh"

class TabAsoc
{
  Lista* MainTab;
  int s;
public:

  TabAsoc();

  void set_size(int siz);

  Lista& operator[](int in); 

  ~TabAsoc();

};
