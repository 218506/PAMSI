#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Tasoc.hh"

TabAsoc::TabAsoc()
{
  s=0;
  MainTab=new Lista[1];
}

void TabAsoc::set_size(int siz)
{
  s=siz;
  MainTab=new Lista[siz];
}

Lista& TabAsoc::operator[](int in)
{
  if(in < this->s)
    return MainTab[in];
  else
    {
      cerr << "Zle indeksowanie tablicy asocjacyjnej."<< endl;
      return MainTab[0];
    }
}

TabAsoc::~TabAsoc()
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
