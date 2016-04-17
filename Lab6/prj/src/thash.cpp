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

int TabHash:: Hash(string key) //sumuje ascii*waga (waga =1,2,3...)
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
      if(tmp.get_back()==sear_word)
	{
	  return i;
	}
      else
	{
	  i++;
	}
      tmp.pop_back();
    }
  cerr << "Nie znaleziono slowa." << endl;
  return 0;
}

TabHash::~TabHash()
{
  /*
  cerr <<"Dest thash" << endl;
  if(this->s!=1)
    {
      for(int i=0; i < s;i++)  //przejezdzam po kazdym elemencie MainTaba
	{
	  
	  cerr << "1i=  " << i << endl;
	  while(!MainTab[i].empty()) //dopoki nie empty- popuje elementy
	    {
	      cerr << "2i=  " << i << endl;
	      MainTab[i].pop_front();
	    }
	} 
      MainTab=NULL;
      cerr <<"P O Dest thash" << endl;
    } 
  */
}
