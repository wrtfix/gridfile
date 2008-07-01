#include "Gridfile.h"

Gridfile::Gridfile() {
	
	Balde* b = new Balde;
	for (int i=0;i<MAX_X;i++)
		for (int j=0;j<MAX_Y;j++)
			for (int k=0;k<MAX_Z;k++)
				this->grid[i][j][k];	

}

Gridfile::~Gridfile() {
	// TODO Auto-generated destructor stub
}

void Gridfile::cargarBIN(){
	//for cada reg del archivo.
	//this.add();
		
}

void Gridfile::add(short int accion,short int forma,float precio,int valor){
	
	return;
};
