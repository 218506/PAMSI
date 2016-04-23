#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "BST.hh"

int main()
{ 
  BST test;  

  for(int i=0;i<10000;i++)
    test.insert(i+1);

  return 0;
}
