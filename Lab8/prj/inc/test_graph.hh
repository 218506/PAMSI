#include "Irunnable.hh"
#include "Istoper.hh"
#include "Lista.hh"
#include "Graph.hh"

class test_graph: public Irunnable, public Istoper 
{
protected:
  timeval tim;
  double t1;
  double t2;
  int wynik;
  Graph Test;
public:
  test_graph();
  virtual void start();
  virtual void stop();
  virtual long get_time();
  virtual bool prepare(int Ver,int Edg);   
  virtual bool run();
  void wyswietl_wynik();
};
