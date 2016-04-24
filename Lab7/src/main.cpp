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
  /*
  test.insert(10);
  test.insert(5);
  test.insert(15);
  test.insert(3);
  test.insert(7);
  test.insert(13);
  test.insert(17);
  test.insert(1);
  test.insert(4);
  test.insert(6);
  test.insert(9);
  test.insert(11);
  test.insert(14);
  test.insert(16);
  test.insert(18);
  */
  
  /*
  test.insert(7);
  test.insert(5);
  test.insert(9);
  test.insert(4);
  test.insert(6);
  test.insert(8);
  test.insert(10);
  */	
  /*	       
  test.insert(6);
  test.insert(5);
  test.insert(4);
  test.insert(3);
  test.insert(2); 
  test.insert(1); 
  */
  cerr << "TEST ROTACJ: " << endl;
  
  test.balance();

  test.insert(20);


  return 0;
}
