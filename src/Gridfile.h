#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include <iostream>
#include <vector>

#include "Balde.h"
#include "Zona.h"

#define CAPACIDAD 16

using namespace std;

class Gridfile {
	private:
		Balde* grid[CAPACIDAD][CAPACIDAD][CAPACIDAD];
		vector<Zona*> mascara;
		short int escalaAccion[CAPACIDAD];
		short int escalaForma[CAPACIDAD];
		float escalaPrecio[CAPACIDAD];
	public:
		Gridfile();
		~Gridfile();
		void cargarBIN();	
		void add(short int,short int,float,int);
		Balde* get(int,int,int);
		void addZona(Zona*);
		Zona* getZona(int,int,int);
		void guardarEscalas(short int a[CAPACIDAD],short int f[CAPACIDAD], float p[CAPACIDAD]);
		
};

#endif /* GRIDFILE_H_ */
