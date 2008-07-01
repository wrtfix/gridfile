gridfile: main.o Balde.o Gridfile.o Zona.o
	g++  -o gridfile main.o Balde.o Gridfile.o
	
Balde.o: Balde.h Balde.cpp
	g++ -o Balde.o -c Balde.cpp

Gridfile.o: Gridfile.h Gridfile.cpp
	g++ -o Gridfile.o -c Gridfile.cpp
	
Zona.o: Zona.h Zona.cpp
	g++ -o Zona.o -c Zona.cpp 

main.o: main.cpp Balde.h Gridfile.h
	g++ -o main.o -c main.cpp
