#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
#include "BST.hh"


BST::BST()
{
  this->tree[0]=0;
  this->end=0;
}

BST::BST(int size)
{
  int i;
  for(i=0; i < size; i++)
    this->tree.dopiszx2(i,i);
  this->tree.dotnij(i);
  this->end=i;  
}


void BST:: insert(int v1)
{  
  if(end==0) //dla zapelniania pierwszego elementu
    {
      this->tree.dopisz(0,v1);
      end++;
    }
  else
    {
      this->tree.dopisz(++end,v1);
    }
  tree.dotnij(end);

  for(int i=0;i<end;i++)
    cerr << tree[i]<< "  ";
  cerr << endl; 

}

  
void BST:: balance()
{

}
  
void BST:: remove(int index)
{
  
}
  
int BST:: search(int v1) //implementacja binary search
{
  return -1;
}


BST::~BST()
{
  
}
