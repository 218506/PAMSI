#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"
#include "tablica.hh"
#include "Graph.hh"

Graph::Graph()
{
  this->V=0;
  this->E=0;
  this->AdList=NULL;
}

Graph::Graph(int edges,int vertices) //pamietac o odpowiedniej liczbie krawedzi (Ee<V;V!>)
{
  this->V=vertices;
  this->E=edges;
  this->AdList=new Lista[V];
  cerr << "V=" << V <<endl;
  cerr << "E=" << E <<endl;
}

void Graph::addVertex(int x)
{
  if(this->V==0) //jezeli graf nie ma wierzcholkow
    {
      V++;
      this->AdList=new Lista[V];
    }
  else
    {
      V++;
      Lista* tmp=AdList;
      AdList= new Lista[V];
      for(int i=0;i<V;i++)
	AdList[i]=tmp[i];
      delete [] tmp;
    }
}

void Graph::addEdge(int A,int B, int weight)
{
 
  if(A >= V) //zle indeksowanie tablicy list
    {
      cerr << "Wierzcholek o numerze " << A << " nie istnieje." <<endl;
      return;
    }
  else
    AdList[A].push_front(to_string(B));

  while(!AdList[A].empty())
    cerr << AdList[A].pop_front() << endl;
}
 
void Graph::removeVertex(int x)
{
  
}

void Graph::removeEdge(int x,int y)
{
  
}

Tablica Graph::getNeighbours(int x)
{
  Tablica tab;
  return tab;
}
