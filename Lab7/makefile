FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab7: obj obj/main.o obj/tablica.o obj/bst.o  obj/test_bst.o
	g++ -pedantic -Wall -std=c++0x -o Lab7 obj/main.o obj/tablica.o obj/bst.o obj/test_bst.o

obj:
	mkdir obj

obj/main.o: src/main.cpp inc/tablica.hh inc/BST.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/tablica.o: src/tablica.cpp inc/tablica.hh inc/Itablica.hh
	g++ -c ${FLAGS} -o obj/tablica.o src/tablica.cpp

obj/bst.o: src/bst.cpp inc/BST.hh inc/IBST.hh
	g++ -c ${FLAGS} -o obj/bst.o src/bst.cpp

obj/test_bst.o: src/test_bst.cpp inc/BST.hh inc/test_bst.hh
	g++ -c ${FLAGS} -o obj/test_bst.o src/test_bst.cpp

make clear:
	rm -r obj/*
	rm Lab7
