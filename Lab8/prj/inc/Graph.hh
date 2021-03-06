#include "Igraph.hh"

class Graph: public Igraph
{
  int E;
  int V;
  Lista* AdList;
public:
  Graph();
  Graph(int edges,int vertices);
  bool isEmpty(int ind);
  virtual void addVertex(int x);
  virtual void addEdge(int A,int B, int weight); 
  virtual void removeVertex(int x);
  virtual void displayEdges();
  void DFS(int start);
  void BFS(int start); 
};
