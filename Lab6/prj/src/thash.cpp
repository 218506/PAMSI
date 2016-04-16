#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Thash.hh"

TabHash::TabHash()
{
  s=1;
  MainTab=new Lista[1];
}

void TabHash::set_size(int siz)
{
  s=siz;
  MainTab=new Lista[siz];
}

int TabHash:: Hash(string key)
{
  int ha=0;
  for(unsigned int i=0; i< key.size();i++)
    {
      ha=ha+key[i]*(i+1);       
    }
  return ha;
}

Lista& TabHash:: operator [](string Key)
{
  if(Hash(Key) < s)
    return MainTab[Hash(Key)];
  else
    {
      cerr << "Nieprawidlowe indeksowanie tablicy."<<endl;
      return MainTab[0];
    }

}

int TabHash:: search(string Key, string sear_word)
{
  Lista tmp=MainTab[Hash(Key)]; //znajduje element za pomoca funk. hashujacej
  int i=0;
  while(!tmp.empty())
    {
      tmp.pop_front();
      if(tmp.get()==sear_word)
	break;
      i++;
    }
  if(i==0)
    cerr << "Nie znaleziono slowa." << endl;
  return i;
}

TabHash::~TabHash()
{
  if(this->s!=0)
    {
      for(int i=0; i < s;i++)  //przejezdzam po kazdym elemencie MainTaba
	{
	  while(!MainTab[i].empty()) //dopoki nie empty- popuje elementy
	    {
	      MainTab[i].pop_front();
	    }
	}
      MainTab=NULL;
    }
}
