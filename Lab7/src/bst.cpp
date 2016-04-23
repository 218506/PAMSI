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
  tree=NULL;
}


void BST:: insert(int v1)
{
  Kaf* nowa=new Kaf;
  nowa->wartosc=v1;
  
  if(tree==NULL) //jezeli drzewo puste - root
    tree=nowa;
  else //jezeli juz cos jest na drzewie
    {
      Kaf* tmp = tree; //zeby nie zgubic wsk na pierwszy element
      while(1)
	{
	  if(v1 < tree->wartosc) //1. jezeli v1 mniejsza - idzie w lewo
	    {
	      if(tree->ls!=NULL)
		tree=tree->ls;
	      else
		{
		  tree->ls=nowa;
		  nowa->parent=tree;
		  break;
		}
	    }
	  else if(tree->wartosc==v1) //2. jezeli v1 rowna - koniec
	    break;
	  else  //3. jezel v1 wieksza - idzie w prawo
	    {
	      if(tree->ps!=NULL)
		tree=tree->ps;
	      else
		{
		  tree->ps=nowa;
		  nowa->parent=tree;
		  break;
		}	    
	    }
	}
      tree=tmp;
    }
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
