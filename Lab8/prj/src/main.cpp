#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"
#include "tablica.hh"
#include "Graph.hh"

int main()
{
  Graph test(99,100);
  test.addEdge(2,1,0);

  return 1;
}
