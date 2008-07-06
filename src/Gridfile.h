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
		
		vector<Zona *> mascara;
		
		/* getters & setters? para las escalas?
		 */ 
		short int escalaAccion[CAPACIDAD];
		short int escalaForma[CAPACIDAD];
		float escalaPrecio[CAPACIDAD];
		
	public:
		Gridfile();
		~Gridfile();
		void cargarBIN();	
		void add(short int,short int,float,int);
		Balde* get(int,int,int);
				
		// obtengo una zona a partir de una posicion especifica en
		Zona* getZona(int,int,int);

		int getPosAccion(short int);
		int getPosForma(short int);
		int getPosPrecio(float);
		
		short int getAccion(int pos);
		
		// para inicializar las escalas
		void guardarEscalas(short int a[CAPACIDAD],short int f[CAPACIDAD], float p[CAPACIDAD]);	

		void addZona(Zona*);
		Zona* getZona(int);
		void eliminarZona(Zona*);
		void asigBalde(Zona*);
		void imprimir();		
};

#endif /* GRIDFILE_H_ */
