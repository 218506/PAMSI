#include "Igraph.hh"

class Graph: public Igraph
{
  int E;
  int V;
  Lista* AdList;
public:
  Graph(int edges,int vertices);
  virtual void addVertex(int x);
  virtual void addEdge(int x,int y, int weight); 
  virtual void removeVertex(int x);
  virtual void removeEdge(int x,int y);
  virtual Tablica getNeighbours(int x);
  
};
