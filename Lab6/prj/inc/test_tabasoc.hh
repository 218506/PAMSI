#include "Tasoc.hh"
#include "Irunnable.hh"
#include "Istoper.hh"

class test_tabasoc: public Irunnable, public Istoper 
{
protected:
  timeval tim;
  double t1;
  double t2;
  int wynik;
public:
  test_tabasoc();
  virtual void start();
  virtual void stop();
  virtual long get_time();   
  virtual bool run(int Argc,char* Argv[]);
  void wyswietl_wynik();
};
