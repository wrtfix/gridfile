#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include <iostream>
#include <vector>

#include "Zona.h"

#define CAPACIDAD 16

using namespace std;

class Gridfile {
	private:
		Balde* grid[CAPACIDAD][CAPACIDAD][CAPACIDAD];
		
		//getters & setters? para mascara?
		vector<Zona*> mascara;
		
		/* getters & setters? para las escalas?
		 */ 
		short int escalaAccion[CAPACIDAD];
		short int escalaForma[CAPACIDAD];
		float escalaPrecio[CAPACIDAD];
		
		void divBaldeAccion(Balde*,Balde*,short int);

	public:
		Gridfile();
		~Gridfile();
		void cargarBIN();	
		void add(short int,short int,float,int);
		Balde* get(int,int,int);
		void addZona(Zona*);
		Zona* getZona(int,int,int);
		int getPosAccion(short int);
		int getPosForma(short int);
		int getPosPrecio(float);
		void guardarEscalas(short int a[CAPACIDAD],short int f[CAPACIDAD], float p[CAPACIDAD]);
		
};

#endif /* GRIDFILE_H_ */
