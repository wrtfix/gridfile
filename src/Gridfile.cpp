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
	
	cout << "add" << endl;

	//Obtenemos las posiciones en las respectivas escalas.
	int x = this->getPosAccion(accion);
	int y = this->getPosForma(forma);
	int z = this->getPosPrecio(precio);
	
    cout << "x: " << x << " y: " << y << " z: " << z << endl;

	//Obtenemos el Balde donde tengo que agregar el valor.
	Balde *b = this->get(x,y,z);


	b->imprimir();
	

	//El Balde esta lleno?
	if (!b->full())
	{
    	//regBalde a agregar al Balde.
    	regBalde reg;
	    reg.accion = accion;
    	reg.forma = forma;
    	reg.precio = precio;
    	reg.valor = valor;
    	cout << "Agrego en el balde" << endl;
		b->add(reg);
    }
	else
	{

		cout << "DIVISION" << endl;
        //obtengo la Zona correspondiente al punto.
        Zona *original = this->getZona(x,y,z);

		this->imprimir();

		cout << "antes de div: "<< endl;
        original->imprimir();

        //divido la Zona y obtengo la nueva.
        Zona *nueva = original->divAccion();

        //eliminar la zona anterior y agregar la dos nuevas;
        

 		this->addZona(nueva);


    	cout << "Original ";
        this->addZona(nueva);
		
		cout << "dsp de div: "<< endl;
		cout << "original ";
		original->imprimir();

		cout << "Nueva ";
		nueva->imprimir();       
  
        
        //obtengo los Baldes de cada Zona.
		cout << "nueva ";
		nueva->imprimir();
		
		//obtengo los Baldes de cada Zona.
        Balde *origen = original->getBalde();
        Balde *destino = nueva->getBalde();

        cout << "baldes a dividir: " << endl;
        origen->imprimir();
        destino->imprimir();
		system("pause");

		cout << "accion: "<< accion << endl;
        cout << "asi queda la cosa: " << endl;

        //divido los elementos del balde
        origen->divAccion(destino,accion);
        
        origen->imprimir();
        destino->imprimir();
		system("pause");
		
        //recursion
        this->add(accion,forma,precio,valor);
        
    }
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

void Gridfile::eliminarZona(Zona *z){

//  mascara[i]->erase();
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
	cout << " getZona " << endl;
    cout << "x: " << x << " y: " << y <<" z: " << z << endl;
	for(int i=0 ; i<this->mascara.size(); i++)
	{
		cout << "           getZona " << endl;
        if (this->getZona(i)->pertenece(x,y,z))
    		return this->mascara[i];
		this->mascara[i]->imprimir();
	}
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
