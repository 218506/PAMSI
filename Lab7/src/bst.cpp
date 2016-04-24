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
	  cerr << "STEP:  " <<tree->wartosc << endl;
	  if(v1 < tree->wartosc) //1. jezeli v1 mniejsza - idzie w lewo
	    {
	      if(tree->ls!=NULL)
		tree=tree->ls;
	      else
		{
		  cerr << "NA LEWO ";
		  tree->ls=nowa;
		  nowa->parent=tree;
		  break;
		}
	    }
	  else if(tree->wartosc==v1) //2. jezeli v1 rowna - koniec
	    {
	      delete nowa;
	      break;
	    }
	  else  //3. jezel v1 wieksza - idzie w prawo
	    {
	      if(tree->ps!=NULL)
		tree=tree->ps;
	      else
		{
		  cerr << "NA PRAWO ";
		  tree->ps=nowa;
		  nowa->parent=tree;
		  break;
		}	    
	    }
	}

      if(tree->wartosc!=v1) //2. jezeli v1 rowna - koniec
	{
	  cerr << "WSTAWIAM:  " << nowa->wartosc << endl;
	  cerr << "RODZIC: " << nowa->parent->wartosc << endl;
	}
      tree=tmp;
    }

}

void BST:: balance()
{
  //Algorytm DSW
  //1. rotate right

  if(tree->ls!=NULL) //Jezeli A ma prawego syna B
    {
      tree=tree->ls; //przesuwam wskaznik tree na B
      if(tree->ps!=NULL) //jezeli B ma prawego syna
	{
	  tree->parent->ls=tree->ps; //Lewy syn A wskazuje na prawego B
	  tree->parent->ls->parent=tree->parent; //Lewy syn A wskazuje na rodzica A czyli B 
	}

      tree->ps=tree->parent; //A staje sie prawym synem B
     
      if(tree->ps->parent!=NULL) //Jezeli A nie byl rootem
	{
	  tree->parent->parent->ps=tree; 
	  tree->parent=tree->parent->parent;
	  tree->ps->parent=tree;
	}
      else //Jezeli a byl rootem
	{
	  tree->parent->parent=tree; // B staje sie rodzicem A
	  tree->parent=NULL; //B staje sie korzeniem
	} 
    }
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
