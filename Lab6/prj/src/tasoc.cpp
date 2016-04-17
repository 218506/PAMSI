#include <cstdio>
#include <unistd.h>
#include <string.h>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>


using namespace std;

#include "Tasoc.hh"

TabAsoc:: TabAsoc(int size)
{
  tab.set_size(size);
}

Lista& TabAsoc::operator[](string Key)
{
  return tab[Key];
}

int TabAsoc:: search(string Key, string sear_word)
{
  return tab.search(Key,sear_word);
}

TabAsoc::~TabAsoc()
{
}
