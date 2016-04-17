FLAGS=-g -Iinc -pedantic -Wall -std=c++0x

Lab6: obj obj/main.o obj/lista.o obj/thash.o obj/tasoc.o obj/test_tabasoc.o
	g++ -pedantic -Wall -std=c++0x -o Lab6 obj/main.o obj/lista.o obj/thash.o obj/tasoc.o obj/test_tabasoc.o


obj:
	mkdir obj

obj/main.o: src/main.cpp inc/Lista.hh inc/Thash.hh inc/test_tabasoc.hh
	g++ -c ${FLAGS} -o obj/main.o src/main.cpp

obj/lista.o: src/lista.cpp inc/Ilista.hh
	g++ -c ${FLAGS} -o obj/lista.o src/lista.cpp

obj/thash.o: src/thash.cpp inc/Thash.hh inc/Tasoc.hh
	g++ -c ${FLAGS} -o obj/thash.o src/thash.cpp

obj/tasoc.o: src/tasoc.cpp inc/Tasoc.hh inc/Lista.hh
	g++ -c ${FLAGS} -o obj/tasoc.o src/tasoc.cpp

obj/test_tabasoc.o: src/test_TabAsoc.cpp inc/test_tabasoc.hh
	g++ -c ${FLAGS} -o obj/test_tabasoc.o src/test_TabAsoc.cpp

make clear:
	rm -r obj/*
	rm Lab6
