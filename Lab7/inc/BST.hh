#include "tablica.hh"
#include "IBST.hh"

class BST: IBST
{
  Tablica tree; 
  int end; //indeks konca drzewa w tablicy
public:

  BST();

  BST(int size);
  
  virtual void insert(int v1);
  
  virtual void balance();
  
  virtual void remove(int index);
  
  virtual int search(int v1);

  ~BST();
};
  
