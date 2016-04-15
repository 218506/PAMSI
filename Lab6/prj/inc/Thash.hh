
#include "Tasoc.hh"
#include "Ithash.hh"

class TabHash: public Ithash
{ 
TabAsoc tab;
public:

TabHash();

virtual int Hash(string key);

virtual Lista& operator [](string Key);

};
