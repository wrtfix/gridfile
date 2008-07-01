gridfile: main.o Balde.o Gridfile.o
	g++ main.o Balde.o Gridfile.o -o gridfile 
	
Balde.o: Balde.h Balde.cpp
	g++ -c Balde.cpp -o Balde.o

Gridfile.o: Gridfile.h Gridfile.cpp
	g++ -c Gridfile.cpp -o Gridfile.o

main.o: main.cpp Balde.h Gridfile.h
	g++ -c main.cpp -o main.o
