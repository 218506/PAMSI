#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "test_bst.hh"
int main(int Argc,char* Argv[])
{ 
  BST test; 
  /*Drzewo testowe 1
  test.insert(7);
  test.insert(5);
  test.insert(9);
  test.insert(4);
  test.insert(6);
  test.insert(8);
  test.insert(10);
  test.insert(12);
  test.insert(13);
  test.insert(1);
  test.insert(14);
  test.insert(3);
  test.insert(21);
  test.insert(1);
  
  test.insert(31);
  test.insert(55);
  test.insert(47);
  test.insert(32);
  test.insert(33);
  
  test.balance();
 
  test.search(32);*/

  test_bst Test;

  Test.run(Argc,Argv);

  return 0;
}
