FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab8: obj obj/main.o obj/graph.o obj/lista.o obj/tablica.o
	g++ -pedantic -Wall -std=c++0x -o Lab8 obj/main.o obj/lista.o obj/graph.o obj/tablica.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Graph.hh inc/tablica.hh inc/Lista.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/lista.o: src/lista.cpp inc/Ilista.hh
	g++ -c ${FLAGS} -o obj/lista.o src/lista.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh inc/Itablica.hh
	g++ -c ${FLAGS} -o obj/tablica.o src/tablica.cpp

obj/graph.o: src/graph.cpp inc/Graph.hh inc/Igraph.hh inc/tablica.hh inc/Lista.hh
	g++ -c ${FLAGS} -o obj/graph.o src/graph.cpp

make clear:
	rm -r obj/*
	rm Lab8
