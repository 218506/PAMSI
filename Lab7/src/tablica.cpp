#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "tablica.hh"

Tablica::Tablica()
{
  Tab=new int [1];
  n=1; 
}

Tablica::Tablica(int a)
{
  Tab=new int [a];
  for(int i=0; i<a; i++)
    {
      Tab[i]=0;
    }
  n=a; 
}

void Tablica:: dopisz(int in, int x)
{
  if(in>=n)
    {
      int* Tab1=new int [n]; 
      for(int i=0; i<n;i++) //przepisuje
	{
	  Tab1[i]=Tab[i];
	}
      
      Tab= new int[n+1];  //tworze nowa powiekszona o 1
      
      for(int i=0; i<n;i++)
	{
	  Tab[i]=Tab1[i];
	}
      
      Tab[n]=x;
      delete[] Tab1;
      Tab1=NULL;
      n++;
    }
  else
    {
      Tab[in]=x;
    }
}

void Tablica:: dopiszx2(int in, int x)
{
  if(in>=n)
    {
      int* Tab1=new int [n]; 
      for(int i=0; i<n;i++) //przepisuje tablice
	{
	  Tab1[i]=Tab[i];
	}
      
      Tab= new int[n*2];  //tworze nowa powiekszona o 1
      
      for(int i=0; i<n;i++)
	{
	  Tab[i]=Tab1[i];
	}
      
      Tab[n]=x;
      delete[] Tab1;
      Tab1=NULL;
      n=n*2;
    }
  else
    {
      Tab[in]=x;
    }
}

void Tablica:: dotnij(int in) //metoda docina rozmiar tablicy do n
{
  int* Tab1=new int [in]; 
  for(int i=0; i<in;i++) //przepisuje tablice
    {
      Tab1[i]=Tab[i];
    }
  
  Tab= new int[in];  //tworze nowa powiekszona o 1
  
  for(int i=0; i<in;i++)
    {
      Tab[i]=Tab1[i];
    }
  n=in;
}


void Tablica:: wyswietl()
{
  for (int i=0;i<n;i++)
    {
      cout << Tab[i] << "  ";
    }
  cout << endl;
}

int& Tablica:: operator[](int i)
{
  return Tab[i];
}

Tablica::~Tablica()
{
  if(Tab!=NULL)
    {
      delete [] Tab;
      Tab=NULL;
    }
}
