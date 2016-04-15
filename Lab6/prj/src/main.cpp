#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Thash.hh"

int main()
{
  TabHash a;

  a["azaaa"]="x";
  a["azaaa"]="b";
  a["azaaa"]="c";

  cerr << a["azaaa"].get() << endl;
}
