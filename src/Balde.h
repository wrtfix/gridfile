#ifndef BALDE_H_
#define BALDE_H_

#include <iostream>
#include <vector>

/* segun la catedra
 * Este numero debe ser mayor o igual a 10.
 */
#define CAPACIDAD_BALDE 25

using namespace std;

class Balde {
	private:
		struct regBalde {
			short int accion;
			short int forma;
			float int precio;
			int valor; //posicion en el archivo.
		};
		
		//Estaria bueno que este ordenado numero, no?
		vector<regBalde> elementos;
		
	public:
		Balde();
		~Balde();
		bool add(int);
		int size();
		bool full();
		
		void setAccion(int, short int);
		void setForma(int, short int);
		void setPrecio(int, float);
		void setPos(int,int);
		
		int getAccion(int);
		int getForma(int);
		int getPrecio(int);
		int getPos(int);
				
		void imprimir();
		
};

#endif /* BALDE_H_ */
