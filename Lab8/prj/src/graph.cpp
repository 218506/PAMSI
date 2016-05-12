#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#include "Lista.hh"
#include "Stos.hh"
#include "Kolejka.hh"
#include "Graph.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy Graph.
 * Plik ten zawiera definicje funkcji oraz metod
 * dla obiektow klasy Graph. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc 
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy Graph.
 * Ustawia wskaznik AdList na NULL, oraz pola V i E na 0;
 */

Graph::Graph()
{
  this->V=0;
  this->E=0;
  this->AdList=NULL;
}

/*!
 *\brief Konstruktor parametryczny dla obiektow klasy Graph
 * Tworzy tablice dynamiczna list i inicjuje odpowiednio pola E i V.
 * \param[in] edges - ilosc krawedzi.
 * \param[in] vertices - ilosc wierzcholkow.
 */
Graph::Graph(int edges,int vertices) //pamietac o odpowiedniej liczbie krawedzi (Ee<V;V*(V-1)>)
{
  this->V=vertices;
  this->E=edges;
  this->AdList=new Lista[V];
  cerr << "V=" << V <<endl;
  cerr << "E=" << E <<endl;
}

/*!
 *\brief Metoda addVertex dla obiektow klasy Graph
 * Powieksza ona tablice dynamiczna list, zwieksza V 
 * \param[in] x - indeks dodawanego elementu.
 */
void Graph::addVertex(int x)
{
  if(this->V==0) //jezeli graf nie ma wierzcholkow
    {
      V++;
      this->AdList=new Lista[V];
    }
  else
    {
      V++;
      Lista* tmp=AdList;
      AdList= new Lista[V];
      for(int i=0;i<V;i++)
	AdList[i]=tmp[i];
      delete [] tmp;
    }
}


/*!
 *\brief Metoda isEmpty dla obiektow klasy Graph
 *  Metoda ta sprawdza, czy lista pod zadanym indeksem jest pusta.
 * \param[in] ind - indeks zadanej listy
 */
bool Graph::isEmpty(int ind)
{
  if(!AdList[ind].empty())
    return false;
  else 
    return true;
}

void Graph::addEdge(int A,int B, int weight)
{
 
  if(A > V-1 || B > V-1) //zle indeksowanie tablicy list
    {
      cerr << "Wierzcholek o numerze " << A << " nie istnieje." <<endl;
      return;
    }
  else
    AdList[A].push_back(to_string(B));
}
 
void Graph::removeVertex(int x)
{
  if(x > V-1) //zle indeksowanie tablicy list
    {
      cerr << "Wierzcholek o numerze " << x << " nie istnieje." <<endl;
      return;
    }
  else
    {
      while(!AdList[x].empty())
	AdList[x].pop_front();
      return;
    }
}

void Graph::displayEdges()
{
  for(int i=0;i<V;i++)
    {  
      cerr << i <<".  " ;
      while(!AdList[i].empty())
	cerr  << AdList[i].pop_front() << ", "; 
      cerr << endl;
    }
}



void Graph::DFS(int start)
{

  int *odwiedzone= new int[V];
  for(int i=0;i<V;i++)
    odwiedzone[i]=0;

  Stos stack;
  stack.push(to_string(start)); //pushuje do stosu poczatkowy wezel
  odwiedzone[start]=1; //koloruje go

  while(!stack.empty())
    {
      start = stoi(stack.pop()); //sciagam ze stosu element
      // cerr << start << " ";
      
      while(!AdList[start].empty()) //przeszukuje wszystkich sasiadow starta
	{     
	  string sasiad=AdList[start].pop_front(); //sciagam sasiada
	  if (odwiedzone[stoi(sasiad)]!=1) //sprawdzam czy odwiedzony
	    {
	      odwiedzone[stoi(sasiad)] = 1; //jezeli nie, koloruje
	      stack.push(sasiad); //i pushuje na stos
	    }
	}
    }
  // cerr << endl;
  delete odwiedzone;
}

void Graph::BFS(int start)
{
  int *odwiedzone= new int[V];
  for(int i=0;i<V;i++)
    odwiedzone[i]=0;

  Kolejka queue;
  queue.push(to_string(start)); //pushuje do stosu poczatkowy wezel
  odwiedzone[start]=1; //koloruje go

  while(!queue.empty())
    {
      start = stoi(queue.pop()); //sciagam z kolejki element
      // cerr << start << ", ";
      
      while(!AdList[start].empty()) //przeszukuje wszystkich sasiadow starta
	{     
	  string sasiad=AdList[start].pop_back(); //sciagam sasiada
	  if (odwiedzone[stoi(sasiad)]!=1) //sprawdzam czy odwiedzony
	    {
	      odwiedzone[stoi(sasiad)] = 1; //jezeli nie, koloruje
	      queue.push(sasiad); //i pushuje do kolejki
	    }
	}
    }
  //cerr << endl;
  delete odwiedzone;
}


