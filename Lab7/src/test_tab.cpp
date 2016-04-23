#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "test_tab.hh"

test_tab::test_tab()
{
  size=0;
  sta=0;
  end=0;
  lap=0;
}


//Implementacja interfejsu IStoper

void test_tab::start()
{
  sta=clock();
}

void test_tab:: stop()
{
  end=clock();
}

long test_tab:: get_time()
{
  return 1000./CLOCKS_PER_SEC*(end-sta);
}




//implementacja interfejsu Irunnable

bool test_tab::run(int dystans,int laps)
{
  size=dystans;
  lap=laps;
  if (lap!=0)
    {
      Tablica tab(10);
      start();
      int i;
      for(i=0; i<dystans; i++)
	{
	  tab.dopiszx2(i,i+1);
	}
      tab.dotnij(i);
      stop();
      lap--;
      Tab_Wyn[lap]=get_time();
      run(dystans,lap);
      return true;
    }
  else
    return false;
}

void test_tab:: wyswietl_wynik()
{
  float srednio=0;
  cout << "Tablica z wynikami:" << endl;
  for (int i=0; i<10;i++)
    {
      cout << "[" << Tab_Wyn[i] << "] ";
      srednio=srednio+Tab_Wyn[i];
    }
  cout<< endl;
 
  cout<<"Sredni wynik: " << srednio/10 <<"[ms]"<< endl;



}
