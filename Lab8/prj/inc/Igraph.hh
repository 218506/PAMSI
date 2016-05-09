class Igraph
{
  virtual void addVertex(int x)=0;
  virtual void addEdge(int A,int B, int weight)=0; 
  virtual void removeVertex(int x)=0;
  virtual void displayEdges()=0;
};
