#include "tablica.hh"
#include "IBST.hh"

class Kaf
{
  Kaf* ls=NULL;
  Kaf* ps=NULL;
  Kaf* parent=NULL;
  int wartosc=0;
  friend class BST;
};


class BST: IBST
{
  Kaf* tree;
public:

  BST();

  virtual void insert(int v1);

  Kaf* rotate_left();

  Kaf* rotate_right();
  
  virtual void balance();
  
  virtual void remove(int index);
  
  virtual int search(int v1);

  ~BST();
};
  
