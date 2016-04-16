#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

#define ROZMIAR_TABLICY_ASOC 2048383//- do zmiany, zalezy od ilosci uzytych liter
using namespace std;

#include "Tasoc.hh"

TabAsoc:: TabAsoc()
{
  tab.set_size(ROZMIAR_TABLICY_ASOC);
}

Lista& TabAsoc::operator[](string Key)
{
  return tab[Key];
}


TabAsoc::~TabAsoc()
{
}
