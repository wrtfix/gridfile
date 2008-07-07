#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include <iostream>
#include <vector>
#include <math.h>

#include "Zona.h"

#define XMAX 16
#define YMAX 8
#define ZMAX 64

using namespace std;


class Gridfile {
	private:
		Balde* grid[XMAX][YMAX][ZMAX];

		vector<Zona *> mascara;

		/* getters & setters? para las escalas?
		 */
		short int escalaAccion[XMAX];
		short int escalaForma[YMAX];
		float escalaPrecio[ZMAX];

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

		short int getAccion(int);
		float getPrecio(int);

		// para inicializar las escalas
		void guardarEscalas(short int a[XMAX],short int f[YMAX], float p[ZMAX]);

		void addZona(Zona*);
		Zona* getZona(int);
		void eliminarZona(Zona*);
		void asigBalde(Zona*);
		void imprimir();

};

#endif /* GRIDFILE_H_ */
