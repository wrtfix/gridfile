#include "Gridfile.h"

Gridfile::Gridfile() {

	Balde* b = new Balde;
	for (int i=0;i<CAPACIDAD;i++)
		for (int j=0;j<CAPACIDAD;j++)
			for (int k=0;k<CAPACIDAD;k++)
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


void Gridfile::guardarEscalas(short int a[CAPACIDAD],short int f[CAPACIDAD], float p[CAPACIDAD]){
	for (int i = 0; i<CAPACIDAD;i++)
	{
		this->escalaAccion[i] = a[i];
		this->escalaForma[i] = f[i];
		this->escalaPrecio[i] = p[i];
	}
}

	
//agrega resultados al grid.
//alpha. Todavia no tiene en cuenta Zonas.
void Gridfile::add(short int accion,short int forma,float precio,int valor){
	

	regBalde reg;
	
	//Estos ints hay que calcularlos con los valores de entradas y las escalas.
	int accion2 = (int) accion;
	int forma2 = (int) forma;
	int precio2 = (int) precio;

	Balde *b = this->get(accion2, forma2, precio2);
	
	reg.precio = accion;
	reg.forma = forma;
	reg.precio = precio;
	reg.valor = valor;

	if (!b->full())
		b->add(reg);
	/*
	* else
	* 	DIVIDIR Zona (primero obtenerla a partir de )
	* 	DIVIDIR Baldes
	* 	Dividir punteros del grid
	*/
}


//Mueve los elementos de b1 en b2, respecto a la variable "accion"
//alpha
void Gridfile::divBaldeAccion(Balde *b1,Balde *b2,short int accion) {
	
	for(int i=0;i<b1->size();i++)
	{
		short int accionb1 = b1->getAccion(i);
		if (accionb1 > accion)
		{
			regBalde reg = b1->getReg(i);
			b2->add(reg);
			i--;
		}
	}	
}

int Gridfile::getPosAccion(short int accion) {
	
	for(int i=0;i<CAPACIDAD && this->escalaAccion[i]<accion;i++)
	return i;
}
