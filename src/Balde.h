/*
 *      Balde.h
 *
 *      Copyright 2008 	Jorge Carlos Mendiola <wrtfix@gmail.com> &
 * 						Manuel Alonso <manuel.alonso.d@gmail.com>
 *
 *
 * Este programa es de libre distribución; puedes distribuirlo y/o modificarlo
 * bajo los términos de la GNU General Public License como se publicó por la
 * Free Software Foundation; bien la versión 2 de la licencia o,  bajo tu
 * criterio, cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil, pero
 * SIN NINGUNA GARANTÏA; sin, incluso, ninguna garantía implicada por
 * MERCANCIBILIDAD o POR ALGÜN PROPÓSITO PARTICULAR. Lee la
 * GNU General Public License para más información.
 *
 * Deberías haber recibido una copia de la GNU General Public License
 * junto con este programa. Si no es así escribe a Free Software
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
