#include "Balde.h"
#include <iostream>

Balde::Balde() {

	// TODO Auto-generated constructor stub
}

Balde::~Balde() {
	// TODO Auto-generated destructor stub
}

bool Balde::add(int a) {
	
	if (this->elementos.size() < CAPACIDAD_BALDE)
	{
		this->elementos.push_back(a);
		return true;
	}
	else
		return false;
}

bool Balde::get(int i) {
	return 0;
}


