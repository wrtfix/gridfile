#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include <iostream>
#include <vector>

#include "Balde.h"
#include "Zona.h"

#define MAX_X 16
#define MAX_Y 16
#define MAX_Z 16

using namespace std;

class Gridfile {
	private:
		Balde* grid[MAX_X][MAX_Y][MAX_Z];
		vector<Zona*> mascara;

	public:
		Gridfile();
		~Gridfile();
		void cargarBIN();	
		void add(short int,short int,float,int);
		Balde* get(int,int,int);
		void addZona(Zona*);
		Zona* getZona(int,int,int);
};

#endif /* GRIDFILE_H_ */
