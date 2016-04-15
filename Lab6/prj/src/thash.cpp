#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

#define ROZMIAR_TABLICY_HASHUJACEJ 2048383//- do zmiany, zalezy od ilosci uzytych liter
using namespace std;

#include "Thash.hh"

TabHash:: TabHash()
{
  tab.set_size(ROZMIAR_TABLICY_HASHUJACEJ);
}


//wymagania:
//1. Latwo policzyc
//2. Rowny rozklad
//3. Malo kolizji 

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
  return tab[Hash(Key)];
}
