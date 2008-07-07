/*
 *      Gridfile.h
 *
 *      Copyright 2008 	Jorge Carlos Mendiola <wrtfix@gmail.com> &
 * 						Manuel Alonso <manuel.alonso.d@gmail.com>
 *
 *
 * Este programa es de libre distribuci�n; puedes distribuirlo y/o modificarlo
 * bajo los t�rminos de la GNU General Public License como se public� por la
 * Free Software Foundation; bien la versi�n 2 de la licencia o,  bajo tu
 * criterio, cualquier versi�n posterior.
 *
 * Este programa se distribuye con la esperanza de que sea �til, pero
 * SIN NINGUNA GARANT�A; sin, incluso, ninguna garant�a implicada por
 * MERCANCIBILIDAD o POR ALG�N PROP�SITO PARTICULAR. Lee la
 * GNU General Public License para m�s informaci�n.
 *
 * Deber�as haber recibido una copia de la GNU General Public License
 * junto con este programa. Si no es as� escribe a Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */


#ifndef GRIDFILE_H_
#define GRIDFILE_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <set>

#include "Zona.h"

#define XMAX 16
#define YMAX 8
#define ZMAX 64

using namespace std;


class Gridfile {
	private:
		Balde* grid[XMAX][YMAX][ZMAX];

		vector<Zona *> mascara;

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

        Balde *getOriginal(short int, short int, float);

		short int getAccion(int);
		float getPrecio(int);

		// para inicializar las escalas
		void guardarEscalas(short int a[XMAX],short int f[YMAX], float p[ZMAX]);

		void addZona(Zona*);
		Zona* getZona(int);
		void eliminarZona(Zona*);
		void asigBalde(Zona*);
		
		vector<int> consulta3rangos(short int,short int,short int,short int,float,float);

		vector<int> consultaPrecio(float,float);

		vector<int> consultaAccForma(short int,short int,short int,short int);
		
		void imprimir();

};

#endif /* GRIDFILE_H_ */
