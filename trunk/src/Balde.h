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
		void imprimir();
		
};

#endif /* BALDE_H_ */
