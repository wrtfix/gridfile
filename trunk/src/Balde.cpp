#include "Balde.h"

Balde::Balde() {
	
}

Balde::~Balde() {	
}

bool Balde::add(int a) {
	if (this->elementos.size() < CAPACIDAD_BALDE) {
		this->elementos.push_back(a);
		return true;
	}
	else
		return false;
}

int Balde::get(int i) {
	return this->elementos[i];	
}

int Balde::size() {
	return this->elementos.size();
}

void Balde::imprimir() {
	for (int i=0;i<this->size();i++)
		cout << "b" << i << ": " << this->get(i) << endl;

	}
