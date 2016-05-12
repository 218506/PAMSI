#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "test_graph.hh"

#define VER_NUM 10000000

int main()
{
  test_graph ttt;

  ttt.prepare(VER_NUM,VER_NUM*0.3);  //(Ver,RandEdg)
  ttt.run();

  return 1;
}
