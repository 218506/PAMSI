#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
#include "test_tabasoc.hh"

#define ROZMIAR_TABLICY_ASOC 87840//- do zmiany, zalezy od ilosci uzytych liter
                                 // dla 6 elementowego slowa jest to 122*6!


int main(int Argc, char* Argv[])
{
  test_tabasoc test;
  test.run(Argc,Argv);
}
