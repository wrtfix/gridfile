#include "Gridfile.h"

Gridfile::Gridfile() {

	for (int i=0;i<CAPACIDAD;i++)
		for (int j=0;j<CAPACIDAD;j++)
			for (int k=0;k<CAPACIDAD;k++)
				this->grid[i][j][k] = NULL;
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
	int x = this->getPosAccion(accion);
	int y = this->getPosForma(forma);
	int z = this->getPosPrecio(precio);
	
	
	//Obtenemos el Balde donde tengo que agregar el valor.
	Balde *b = this->get(x,y,z);

	//El Balde esta lleno?

	if (!b->full())
	{
    	//regBalde a agregar al Balde.
    	regBalde reg;
	    reg.accion = accion;
    	reg.forma = forma;
    	reg.precio = precio;
    	reg.valor = valor;
		b->add(reg);
    }
	else
	{
        //obtengo la Zona correspondiente al punto.
        Zona *original = this->getZona(x,y,z);

		int zmitad = (int) ceil((original->get_z2() + original->get_z1())/2);
        
		//divido la Zona y obtengo la nueva.
	    Zona *nueva = original->divPrecio(zmitad);

		//creo un nuevo Balde
		Balde *bn = new Balde();

		//Asigno el nuevo balde a la nueva zona
		nueva->setBalde(bn);
		
		//agrego la nueva Zona a la mascara.        
        this->addZona(nueva);
       
		//obtengo el Balde de la Zona original (el que tiene todos los elem)
        Balde *origen = original->getBalde();

		//divido los elementos del balde
		short int mitadEscala = getPrecio(zmitad);
		
        origen->divPrecio(bn,mitadEscala);

   	    //recursion
        this->add(accion,forma,precio,valor);
    }
}

int Gridfile::getPosAccion(short int accion) {
	
	int i;
	for(i=0;i<CAPACIDAD && this->escalaAccion[i]<accion;i++);		
	return i;
}

int Gridfile::getPosForma(short int forma) {
	
	int i;
	for(i=0;i<CAPACIDAD && this->escalaForma[i]<forma;i++);
	return i;
}

int Gridfile::getPosPrecio(float precio) {
	
	int i;
	for(i=0;i<CAPACIDAD && this->escalaPrecio[i]<precio;i++);
	return i;
}


short int Gridfile::getAccion(int pos)
{
	return escalaAccion[pos];
}

float Gridfile::getPrecio(int pos)
{
	return escalaPrecio[pos];
}


//Agrega una Zona al Gridfile. Realiza la actualizacion de las celdas abarcadas diche Zona
void Gridfile::addZona(Zona* z){
     
     this->mascara.push_back(z);
     this->asigBalde(z);
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
	for(int i=0 ; i<this->mascara.size(); i++)
		if (this->getZona(i)->pertenece(x,y,z))
    		return this->mascara[i];
	return NULL;
}

//Asigna ese balde a todas las celdas que pertenecen a la Zona.
void Gridfile::asigBalde(Zona *z) {
    
	for(int i = z->get_x1();i<=z->get_x2();i++)
		for(int j = z->get_y1();j<=z->get_y2();j++)
			for(int k = z->get_z1();k<=z->get_z2();k++)
				this->grid[i][j][k] = z->getBalde();
}

void Gridfile::imprimir()
{
    for (int i=0;i<this->mascara.size();i++)
    {
		Zona *zona = this->getZona(i);
		zona->imprimir();
        Balde *balde = zona->getBalde();
        if (balde)
            balde->imprimir();
        cout << endl;
    }
}
