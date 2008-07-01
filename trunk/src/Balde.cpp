#include "Balde.h"
#include <iostream>

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
