#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <math.h>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;
#include "BST.hh"


BST::BST()
{
  tree=NULL;
  W=0;
}


void BST:: insert(int v1)
{
  Kaf* nowa=new Kaf;
  nowa->wartosc=v1;
  
  if(tree==NULL) //jezeli drzewo puste - root
    {
      tree=nowa;
      this -> W++;
    }
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
		  this -> W++;
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
		  tree->ps=nowa;
		  nowa->parent=tree;
		  this -> W++;
		  break;
		}	    
	    }
	}
      tree=tmp;
    }
}

Kaf* BST::rotate_left()
{
  if(tree->ps!=NULL) //Jezeli A ma lewego syna B
    {
      tree=tree->ps; //przesuwam wskaznik tree na B
      if(tree->ls!=NULL) //jezeli B ma lewego syna
	{
	  tree->parent->ps=tree->ls; //Lewy syn A wskazuje na prawego B
	  tree->parent->ps->parent=tree->parent; //Lewy syn A wskazuje na rodzica A czyli B 
	}
      else
	{
	  tree->parent->ps=NULL; //Lewy syn A wskazuje na NULL
	}
      
      tree->ls=tree->parent; //A staje sie prawym synem B
      
      if(tree->ls->parent!=NULL) //Jezeli A nie byl rootem
	{
	  if(tree->parent->parent->ps==tree->parent)
	    tree->parent->parent->ps=tree;
	  else
	    tree->parent->parent->ls=tree;
	  tree->parent=tree->parent->parent;
	  tree->ls->parent=tree;
	}
      else //Jezeli a byl rootem
	{
	  tree->parent->parent=tree; // B staje sie rodzicem A
	  tree->parent=NULL; //B staje sie korzeniem
	}       
    }
  return tree; 
}


Kaf* BST::rotate_right()
{
  if(tree->ls!=NULL) //Jezeli A ma prawego syna B
    {
      tree=tree->ls; //przesuwam wskaznik tree na B
      if(tree->ps!=NULL) //jezeli B ma prawego syna
	{
	  tree->parent->ls=tree->ps; //Lewy syn A wskazuje na prawego B
	  tree->parent->ls->parent=tree->parent; //Lewy syn A wskazuje na rodzica A czyli B 
	}
      else
	{
	  tree->parent->ls=NULL; //Lewy syn A wskazuje na NULL
	}
      
      tree->ps=tree->parent; //A staje sie prawym synem B
      
      if(tree->ps->parent!=NULL) //Jezeli A nie byl rootem
	{
	  if(tree->parent->parent->ls==tree->parent)
	    tree->parent->parent->ls=tree;
	  else
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
  return tree;
}

void BST:: balance()
{
  //Algorytm DSW - zlozonosc obliczeniowa O(n)
  if(tree!=NULL)
    {
      //1. rotate right
      /* ROBIENIE LISTY Z DRZEWA */
      while(tree->ls!=NULL)
	{
	  rotate_right();
	}
      
      Kaf* tmp=rotate_right(); //zapamietuje wartosc nowego korzenia - minimmum  ze zbioru
      
      while(tree->ps!=NULL)
	{
	  while(tree->ls!=NULL)
	    {
	      rotate_right();
	    }
	   tree=tree->ps;
	}
      tree=tmp;

      /*Obliczanie liczby potrzebnej do algorytmu DSW*/
      
      // int m=pow(2,floor(log2(W+1)))-1;
      //2. rotate left 
      
      tmp=rotate_left();
      while(tree->ps!=NULL) //przejście po raz pierwszy - pierwsze zgiecia
	{
      	  tree=tree->ps;
	  rotate_left();
	}
      
      int licznik=0;
      tree=tmp;
      rotate_left();
      while(1) // po raz drugi - zginanie drzewa w co drugim punkcie
	{
	  if(tree->ps!=NULL) 
	    {
	      if(licznik==0)
		tmp=rotate_left(); //zapamietanie korzenia
	      else
		rotate_left();
	      if(tree->ps->ps!=NULL)
		tree=tree->ps->ps;
	      else
		break;
	      licznik++;
	    }
	  else
	    break;
	}
      tree=tmp;
    }
  else
    cerr << "Nie ma czego balansowac." << endl;
}
  
void BST:: remove(int index)
{
  
}
  
int BST:: search(int v1) //implementacja binary search
{
  if(tree==NULL) //jezeli drzewo puste - root
    {
      cerr << "Na drzewie nie ma elementow" << endl;
    }
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
		  cerr << "Nie znaleziono elementu" << endl;
		  return -1;
		}
	    }
	  else if(tree->wartosc==v1) //2. jezeli v1 rowna - koniec
	    {
	      cerr << "Znalezion element" << endl;
	      break;
	    }
	  else  //3. jezel v1 wieksza - idzie w prawo
	    {
	      if(tree->ps!=NULL)
		tree=tree->ps;
	      else
		{
		  cerr <<"Nie znaleziomo elementu" << endl;
		  return -1;
		}	    
	    }
	}
      tree=tmp;
    }
  return 1;
}


BST::~BST()
{
  
}
