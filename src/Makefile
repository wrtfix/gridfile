gridfile: main.o Balde.o Gridfile.o Zona.o
	g++  -o gridfile main.o Balde.o Gridfile.o
	
main.o: main.cpp Gridfile.o
	g++ -o main.o -c main.cpp
	
Gridfile.o: Gridfile.h Gridfile.cpp Zona.o
	g++ -o Gridfile.o -c Gridfile.cpp

Zona.o: Zona.h Zona.cpp Balde.o
	g++ -o Zona.o -c Zona.cpp
	
Balde.o: Balde.h Balde.cpp
	g++ -o Balde.o -c Balde.cpp


