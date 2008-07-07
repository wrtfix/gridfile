/*
 *      Balde.h
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


#ifndef BALDE_H_
#define BALDE_H_

#include <iostream>
#include <vector>

/* segun la catedra
 * Este numero debe ser mayor o igual a 10.
 */
#define CAPACIDAD_BALDE 25

typedef	struct regBalde {
			short int accion;
			short int forma;
			float precio;
			int valor; //posicion en el archivo.
		};

using namespace std;

class Balde {
	private:
		//Estaria bueno que este ordenado por "regBalde.valor", no?
		vector<regBalde> elementos;
		
	public:
		Balde();
		~Balde();
		bool add(regBalde);
		bool add(short int, short int, float, int);
		regBalde get(int);
		regBalde getReg(int);
		int size();
		bool full();
		
		void setAccion(int, short int);
		void setForma(int, short int);
		void setPrecio(int, float);
		void setValor(int,int);
		
		short int getAccion(int);
		short int getForma(int);
		float getPrecio(int);
		int getValor(int);
		void divAccion(Balde*,short int);
		void divPrecio(Balde*,float);
		void imprimir();
};

#endif /* BALDE_H_ */
