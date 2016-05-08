#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"
#include "Stos.hh"
#include "Graph.hh"

Graph::Graph()
{
  this->V=0;
  this->E=0;
  this->AdList=NULL;
}

Graph::Graph(int edges,int vertices) //pamietac o odpowiedniej liczbie krawedzi (Ee<V;V*(V-1)>)
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

bool Graph::isEmpty(int ind)
{
  if(!AdList[ind].empty())
    return false;
  else 
    return true;
}

void Graph::addEdge(int A,int B, int weight)
{
 
  if(A > V-1 || B > V-1) //zle indeksowanie tablicy list
    {
      cerr << "Wierzcholek o numerze " << A << " nie istnieje." <<endl;
      return;
    }
  else
    AdList[A].push_back(to_string(B));
}
 
void Graph::removeVertex(int x)
{
  if(x > V-1) //zle indeksowanie tablicy list
    {
      cerr << "Wierzcholek o numerze " << x << " nie istnieje." <<endl;
      return;
    }
  else
    {
      while(!AdList[x].empty())
	AdList[x].pop_front();
      return;
    }
}

void Graph::removeEdge(int x,int y)
{
  for(int i=0;i<V;i++)
    {  
      cerr << i <<".  " ;
      while(!AdList[i].empty())
	cerr  << AdList[i].pop_front() << ", "; 
      cerr << endl;
    }
}



void Graph::DFS(int start)
{

  int *odwiedzone= new int[V];
  for(int i=0;i<V;i++)
    odwiedzone[i]=0;

  Stos stack;
  stack.push(to_string(start)); //pushuje do stosu poczatkowy wezel
  odwiedzone[start]=1; //koloruje go

  while(!stack.empty())
    {
      start = stoi(stack.pop()); //sciagam ze stosu element
      cerr << start << " ";


      Lista tmp= AdList[start];
      while(!tmp.empty()) //przeszukuje wszystkich sasiadow starta
      {     
	string sasiad=tmp.pop_front(); //sciagam sasiada
	if (odwiedzone[stoi(sasiad)]!=1) //sprawdzam czy odwiedzony
	  {
	    odwiedzone[stoi(sasiad)] = 1; //jezeli nie, koloruje
	    stack.push(sasiad); //i pushuje na stos
	  }
      }
    }
  cerr << endl;
  delete odwiedzone;
}

void Graph::BFS()
{



}


