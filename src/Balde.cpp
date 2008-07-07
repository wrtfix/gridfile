/*
 *      Balde.cpp
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

#include "Balde.h"

Balde::Balde() {
	
}

Balde::~Balde() {	
}

bool Balde::add(regBalde a) {
	
	if (!this->full()) {
		this->elementos.push_back(a);
		return true;
	}
	else
		return false;
}

bool Balde::add(short int accion, short int forma, float precio, int filepos) {
	
	regBalde r;
	r.accion = accion;
	r.forma = forma;
	r.precio = precio;
	r.valor = filepos;
	
	return this->add(r);	
}

//Devuelve un registro.
regBalde Balde::get(int pos) {
	
	return this->elementos[pos];
	
}

/* Devuelve un registro y lo quita del balde.
 * Alpha
 */
regBalde Balde::getReg(int pos) {
	
	vector<regBalde>::iterator it = this->elementos.begin();
	it+= pos;
	regBalde ret = this->get(pos);
	this->elementos.erase(it);
	
	return ret;
	
}
		
int Balde::size() {
	return this->elementos.size();
}

bool Balde::full() {
	
	return (this->size() >= CAPACIDAD_BALDE);
	
}
	
void Balde::setAccion(int pos, short int accion) {
	
	this->elementos[pos].accion = accion;
	
}

void Balde::setForma(int pos, short int forma) {
	
	this->elementos[pos].forma = forma;
	
}

void Balde::setPrecio(int pos, float precio) {
	
	this->elementos[pos].precio = precio;
	
}

void Balde::setValor(int pos, int valor) {
	
	this->elementos[pos].valor = valor;
	
}

short int Balde::getAccion(int pos) {
	
	return this->elementos[pos].accion;
	
}

short int Balde::getForma(int pos) {
	
	return this->elementos[pos].forma;
}

float Balde::getPrecio(int pos) {
	
	return this->elementos[pos].precio;
	
}
	
int Balde::getValor(int pos) {
		
	return this->elementos[pos].valor;
		
}

//Mueve los elementos de b1 en b2, respecto a la variable "accion"
//alpha
void Balde::divAccion(Balde *destino,short int accion) {
	
	for(int i=0;i<this->size();i++)
	{
		short int accionb1 = this->getAccion(i);
		if (accionb1 > accion)
		{
			regBalde reg = this->getReg(i);
			destino->add(reg);
			i--;
		}
	}	
}

void Balde::divPrecio(Balde *destino,float precio) {

	for(int i=0;i<this->size();i++)
	{
		float miPrecio = this->getPrecio(i);
		if (miPrecio > precio)
		{
			regBalde reg = this->getReg(i);
			destino->add(reg);
			i--;
		}
	}
}
//auxiliar
void Balde::imprimir() {
	
	int size = this->size();
	cout << "size: " << size << endl;
	if (size == 0)
		cout << "Balde VACIO" << endl;
	else
		for (int i=0;i<size;i++)
			cout << "balde[" << i << "]: v=" << this->getValor(i) << " a="<< this->getAccion(i) << " f=" << this->getForma(i) << " p=" << this->getPrecio(i) <<endl;	

}
