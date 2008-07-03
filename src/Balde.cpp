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
	
	//vector<regBalde>::iterator it = this->elementos.begin();
	//it += pos;
	return this->elementos[pos];
	
}

/* Devuelve un registro y lo quita del balde.
 * Alpha
 */
regBalde Balde::getReg(int pos) {
	
	vector<regBalde>::iterator it = this->elementos.begin();
	
	//it+= pos;
	for (int i=0;i<pos;i++)
		it++;
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


int Balde::getAccion(int pos) {
	
	return this->elementos[pos].accion;
	
}

int Balde::getForma(int pos) {
	
	return this->elementos[pos].forma;
}

int Balde::getPrecio(int pos) {
	
	return this->elementos[pos].precio;
	
}
	
int Balde::getValor(int pos) {
		
	return this->elementos[pos].valor;
		
}


//auxiliar
void Balde::imprimir() {
	
	for (int i=0;i<this->size();i++)
		cout << "valor de balde[" << i << "] = " << this->getValor(i) << endl;	

}
