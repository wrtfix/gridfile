#include "Balde.h"

Balde::Balde() {
	
}

Balde::~Balde() {	
}

bool Balde::add(int a) {
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
	
void setAccion(int valor, short int accion) {
	
	this->elementos[valor].accion = accion;
	
}

void setForma(int, short int) {
	
	this->elementos[valor].forma = forma;
	
}

void setPrecio(int, float precio) {
	
	this->elementos[valor].precio 
}

int getAccion(int);
int getForma(int);
int getPrecio(int);	
	
void Balde::imprimir() {
	
	for (int i=0;i<this->size();i++)
		cout << "b" << i << ": " << this->get(i) << endl;

	}
