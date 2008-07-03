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
		cout << "b" << i << ": valor: " << this->getValor(i) << endl;	

}
