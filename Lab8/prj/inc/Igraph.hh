class Igraph
{
  virtual void addVertex(int x)=0;
  virtual void addEdge(int A,int B, int weight)=0; 
  virtual void removeVertex(int x)=0;
  virtual void removeEdge(int x,int y)=0;
  virtual Tablica getNeighbours(int x)=0;
};
