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
//alpha.
void Gridfile::add(short int accion,short int forma,float precio,int valor){
	
	//Obtenemos las posiciones en las respectivas escalas.
	int x = getPosAccion(accion);
	int y = getPosForma(forma);
	int z = getPosPrecio(precio);

	//Obtenemos el Balde donde tengo que agregar el valor.
	Balde *b = this->get(x,y,z);

	//regBalde a agregar al Balde.
	regBalde reg;
	reg.precio = accion;
	reg.forma = forma;
	reg.precio = precio;
	reg.valor = valor;

	//El Balde está lleno?
	if (!b->full())
		b->add(reg);
	 else
	 {
        //obtengo la Zona correspondiente al punto.
        Zona *original = this->getZona(x,y,z);

        //divido la Zona y obtengo la nueva.
        Zona *nueva = original->divAccion();
        
        //obtengo los Baldes de cada Zona.
        Balde *origen = original->getBalde();
        Balde *destino = nueva->getBalde();
        
        //divido los elementos del 
        origen->divAccion(destino,accion);
        asigBalde(nueva,destino);

        //recursion
        this->add(accion,forma,precio,valor);                          
     }
	 	
//   DIVIDIR Zona (primero obtenerla a partir de )
	/* 	DIVIDIR Baldes
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

int Gridfile::getPosForma(short int forma) {
	
	for(int i=0;i<CAPACIDAD && this->escalaForma[i]<forma;i++)
	return i;
}

int Gridfile::getPosPrecio(float precio) {
	
	for(int i=0;i<CAPACIDAD && this->escalaPrecio[i]<precio;i++)
	return i;
}

void Gridfile::addZona(Zona* z){
     
     this->mascara.push_back(z);
}
     
Zona* Gridfile::getZona(int i) {
      
      return this->mascara[i];
}

/* A partir de una coordenada, retorna la Zona a la que pertenece.
 * alpha 
 * 
 * Las variables se llaman (x,y,z) por que son (int,int,int)
 * Las que son (a,f,p) son (short int,short int,float)
 */  
Zona* Gridfile::getZona(int x, int y, int z)
{
	for(int i=0 ; i<this->mascara.size() && !(this->getZona(i)->pertenece(x,y,z)); i++)
		return this->mascara[i];
}

//Asigna ese balde a todas las celdas que pertenecen a la Zona.
void Gridfile::asigBalde(Zona *z,Balde *b) {
    
    for(int i = z->get_x1();i<z->get_x2();i++)
        for(int j = z->get_y1();j<z->get_y2();j++)
            for(int k = z->get_z1();k<z->get_z2();k++)
                this->grid[i][j][k];
}
