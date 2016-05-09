FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab8: obj obj/main.o obj/graph.o obj/lista.o obj/stos.o obj/test_graph.o obj/kolejka.o
	g++ -pedantic -Wall -std=c++0x -o Lab8 obj/main.o obj/lista.o obj/graph.o obj/test_graph.o obj/stos.o obj/kolejka.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Graph.hh inc/test_graph.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/lista.o: src/lista.cpp inc/Ilista.hh
	g++ -c ${FLAGS} -o obj/lista.o src/lista.cpp

obj/stos.o: src/stos.cpp inc/Stos.hh inc/Istos.hh
	g++ -c ${FLAGS} -o obj/stos.o src/stos.cpp

obj/graph.o: src/graph.cpp inc/Graph.hh inc/Igraph.hh inc/Lista.hh inc/Stos.hh inc/Kolejka.hh
	g++ -c ${FLAGS} -o obj/graph.o src/graph.cpp

obj/kolejka.o: src/kolejka.cpp inc/Kolejka.hh inc/Ikolejka.hh
	g++ -c ${FLAGS} -o obj/kolejka.o src/kolejka.cpp

obj/test_graph.o: src/test_graph.cpp inc/Graph.hh inc/test_graph.hh
	g++ -c ${FLAGS} -o obj/test_graph.o src/test_graph.cpp

make clear:
	rm -r obj/*
	rm Lab8
