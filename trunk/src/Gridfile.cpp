#include "Gridfile.h"

Gridfile::Gridfile() {

	for (int i=0;i<XMAX;i++)
		for (int j=0;j<YMAX;j++)
			for (int k=0;k<ZMAX;k++)
				this->grid[i][j][k] = NULL;

	//Zonas iniciales. (2 divisiones por dimension);
	Zona *z0 = new Zona(0,0,0,7,3,31);
	Zona *z1 = new Zona(0,0,32,7,3,63);
	Zona *z2 = new Zona(0,4,0,7,7,31);
	Zona *z3 = new Zona(0,4,32,7,7,63);
	Zona *z4 = new Zona(8,0,0,15,3,31);
	Zona *z5 = new Zona(8,0,32,15,3,63);			
	Zona *z6 = new Zona(8,4,0,15,7,31);
	Zona *z7 = new Zona(8,4,32,15,7,63);

	//Baldes iniciales (1 por Zona)	
	Balde* baldex0 = new Balde();
	Balde* baldex1 = new Balde();
   	Balde* baldex2 = new Balde();
	Balde* baldex3 = new Balde();
	Balde* baldex4 = new Balde();
	Balde* baldex5 = new Balde();
	Balde* baldex6 = new Balde();
	Balde* baldex7 = new Balde();

	//Asignar baldes a las zonas
    z0->setBalde(baldex0);
    z1->setBalde(baldex1);
    z2->setBalde(baldex2);
    z3->setBalde(baldex3);
    z4->setBalde(baldex4);
    z5->setBalde(baldex5);
    z6->setBalde(baldex6);
    z7->setBalde(baldex7);

	//Agregar las Zonas al Gridfile
    this->addZona(z0);
	this->addZona(z1);
	this->addZona(z2);
	this->addZona(z3);
	this->addZona(z4);
	this->addZona(z5);
	this->addZona(z6);
	this->addZona(z7);
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


Balde* Gridfile::getOriginal(short int a, short int f, float p){
    return (this->get(this->getPosAccion(a),this->getPosForma(f),this->getPosPrecio(p)));
}


void Gridfile::guardarEscalas(short int a[XMAX],short int f[YMAX], float p[ZMAX]){
	for (int i = 0; i<XMAX;i++)
		this->escalaAccion[i] = a[i];
	for (int i = 0; i<YMAX;i++)
		this->escalaForma[i] = f[i];
	for (int i = 0; i<ZMAX;i++)
		this->escalaPrecio[i] = p[i];

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
		float mitadEscala = getPrecio(zmitad);

        origen->divPrecio(bn,mitadEscala);

   	    //recursion
        this->add(accion,forma,precio,valor);
    }
}

int Gridfile::getPosAccion(short int accion) {

	int i;
	for(i=0;i<XMAX-1 && (this->escalaAccion[i]<accion);i++);
    return i;

}

int Gridfile::getPosForma(short int forma) {

	int i;
	for(i=0;i<YMAX-1 && (this->escalaForma[i]<forma);i++);
    return i;
}

int Gridfile::getPosPrecio(float precio) {

	int i;
	for(i=0;(i<ZMAX-1)&&(this->escalaPrecio[i]<precio);i++);
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
void Gridfile::asigBalde(Zona *zona) {

	for(int i = zona->get_x1();i<=zona->get_x2();i++)
		for(int j = zona->get_y1();j<=zona->get_y2();j++)
			for(int k = zona->get_z1();k<=zona->get_z2();k++)
				this->grid[i][j][k] = zona->getBalde();
}

vector<int> Gridfile::consulta3rangos(short int a1, short int a2, short int f1, short int f2, float p1,float p2)
{
		vector<int> ret;
		int x1,x2,y1,y2,z1,z2;

		if (a1 == -1)
			x1 = 0;
		else
			x1 = this->getPosAccion(a1);
		
		if (a2 == -1)
			x2 = XMAX-1;
		else
		    x2 = this->getPosAccion(a2);
		
		if (f1 == -1)
			y1 = 0;
		else
			y1 = this->getPosForma(f1);
			
		if (f2 == -1)
			y2 = YMAX-1;
		else
		    y2 = this->getPosForma(f2);
		
		if (p1 == -1)
			z1 = 0;
		else
			z1 = this->getPosPrecio(p1);
			
		if (p2 == -1)
			z2 = ZMAX-1;
		else
			z2 = this->getPosPrecio(p2);

        set<Balde*> conjunto;

		for(int i=x1; i<=x2 ;i++)
			for(int j = y1; j<=y2 ;j++)
				for(int k = z1; k<=z2 ;k++)
					conjunto.insert(this->get(i,j,k));
		
		set<Balde *>::iterator it = conjunto.begin();
		set<Balde *>::iterator it2 = conjunto.end();

		//Quito de los baldes los elementos que no corresponden
		while (it != it2)
        {
			for(int i=0; i<(*it)->size();i++)
				if(a1==-1 || (((*it)->getAccion(i) >= a1) && ((*it)->getAccion(i) <= a2)))
					if(f1==-1 || (((*it)->getForma(i) >= f1) && ((*it)->getForma(i) <= f2)))
						if(p1==-1 || (((*it)->getPrecio(i) >= p1) && ((*it)->getPrecio(i) <= p2)))
							ret.push_back((*it)->getValor(i));
			it++;
		}
		return ret;

}

vector<int> Gridfile::consultaPrecio(float p1,float p2)
{
		vector<int> ret;
		int z1,z2;
		z1 = this->getPosPrecio(p1);
		z2 = this->getPosPrecio(p2);

        set<Balde*> conjunto;

		for(int i=0; i<XMAX ;i++)
			for(int j = 0; j<YMAX ;j++)
				for(int k = z1; k<=z2 ;k++)
					conjunto.insert(this->get(i,j,k));
		
		set<Balde *>::iterator it = conjunto.begin();
		set<Balde *>::iterator it2 = conjunto.end();

		//Quito de los baldes los elementos que no corresponden
		while (it != it2)
        {
			for(int i=0; i<(*it)->size();i++)
				if(((*it)->getPrecio(i) >= p1) && ((*it)->getPrecio(i) <= p2))
					ret.push_back((*it)->getValor(i));
			it++;
		}
		return ret;
	
}

vector<int> Gridfile::consultaAccForma(short int,short int,short int,short int)
{
	
}

void Gridfile::imprimir()
{
    for (int i=0;i<this->mascara.size();i++)
    {
		cout << "Z: "<< i << " "; 
		Zona *zona = this->getZona(i);
		zona->imprimir();
        Balde *balde = zona->getBalde();
        if (balde)
            balde->imprimir();
        cout << endl;
    }
}
