#include "Gridfile.h"

Gridfile::Gridfile() {
	
	Balde* b = new Balde;
	for (int i=0;i<MAX_X;i++)
		for (int j=0;j<MAX_Y;j++)
			for (int k=0;k<MAX_Z;k++)
				this->grid[i][j][k] = b;	

}

Gridfile::~Gridfile() {
	// TODO Auto-generated destructor stub
}

void Gridfile::cargarBIN(){
	//for cada reg del archivo.
	//this.add();
		
}

//retorna el puntero a Balde en (x,y,z) del grid.
//beta
Balde* Gridfile::get(int x,int y,int z){
	
	return this->grid[x][y][z];
	
	}
	
//agrega resultados al grid.
//alpha. Todavia no tiene en cuenta Zonas.
void Gridfile::add(short int accion,short int forma,float precio,int valor){
	
	int accion2 = (int) accion;
	int forma2 = (int) forma;
	int precio2 = (int) precio;

			cout << "Gridfile.cpp: accion2: " << accion2 << endl;
			cout << "Gridfile.cpp: forma2: " << forma2 << endl;
			cout << "Gridfile.cpp: precio2: " << precio2 << endl;

	Balde *b = this->get(accion2, forma2, precio2);
	
	if (!b->full())
		b->add(valor);
	/*
	* else
	* 	DIVIDIR
	*/
};
