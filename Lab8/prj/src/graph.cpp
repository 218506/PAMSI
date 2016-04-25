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

Graph::Graph(int edges,int vertices)
{
  V=vertices;
  E=edges;
  AdList=new Lista[E];
}

void Graph::addVertex(int x)
{
  
}

void Graph::addEdge(int x,int y, int weight)
{
  
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
