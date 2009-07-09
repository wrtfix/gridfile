#include "Gridfile.h"

Gridfile::Gridfile()
{
    // la matriz se inicializa con dimension 2 x 2 apuntando a baldes vacios


    Zona* z1 = new Zona();
    Zona* z2 = new Zona();
    Zona* z3 = new Zona();
    Zona* z4 = new Zona();

    z1->setPosicion(0,0,1,1);
    z2->setPosicion(1,0,2,1);
    z3->setPosicion(0,1,1,2);
    z4->setPosicion(1,1,2,2);

    Balde* b1 = new Balde();
    Balde* b2 = new Balde();
    Balde* b3 = new Balde();
    Balde* b4 = new Balde();


    z1->setBalde(b1);
    z2->setBalde(b2);
    z3->setBalde(b3);
    z4->setBalde(b4);

    zonas.push_back(z1);
    zonas.push_back(z2);
    zonas.push_back(z3);
    zonas.push_back(z4);


    vector<Balde*> aux;
    aux.push_back(b1);
    aux.push_back(b2);
    matriz.push_back(aux);

    vector<Balde*> aux2;
    aux2.push_back(b3);
    aux2.push_back(b4);
    matriz.push_back(aux2);
}

Gridfile::~Gridfile()
{
    //dtor
}

void Gridfile::addFecha(int mes,int anio){
    regFecha aux;
    aux.mes = mes;
    aux.anio = anio;
    fecha.push_back(aux);
}

void Gridfile::addCantidad(int cant){
    cantidad.push_back(cant);
}

int Gridfile::getposFecha(int mes,int anio){
    int i =0;
    int max = fecha.size();

    while ((i < max)&& (fecha[i].anio < anio))
          i++;

    while ((i < max)&&(fecha[i].mes < mes )&& (fecha[i].anio == anio))
          i++;

    return i;
}

int Gridfile::getposCantidad(int cant){
    int i = 0;
    int max = cantidad.size();
    while ( i<max && cantidad[i] < cant)
        i++;
    return i;
}

Balde * Gridfile::getBalde(int x, int y){
    return matriz[y][x];
}
Zona * Gridfile::getZona(int x,int y){
    int max = zonas.size();
    for(int i = 0; i < max;i++){
        if(zonas[i]->pertenece(x,y))
            return zonas[i];
    }
    return NULL;
}

//Asigna ese balde a todas las celdas que pertenecen a la Zona.
void Gridfile::asignarBalde(Zona *nueva) {
        for(int j = nueva->getYinicial();j<nueva->getYfinal();j++)
            for(int i = nueva->getXinicial();i<nueva->getXfinal();i++)
                matriz[j][i] = nueva->getBalde();
}

void Gridfile::asignarZona(Zona *nueva){
    zonas.push_back(nueva);
    asignarBalde(nueva);
}

//aca agregamos nuevo valor a la escala
void Gridfile::addescFecha(int x)
{
    regFecha aux;

    if (x!=0){
        aux.anio = ceil((fecha[x].anio + fecha[x-1].anio) / 2);
        aux.mes = ceil((fecha[x].mes + fecha[x-1].mes)/2);
        vector<regFecha>:: iterator it = fecha.begin();
        fecha.insert(it+x,aux);
    }
    else{
            aux.anio = ceil((fecha[x].anio) / 2);
            aux.mes = ceil((fecha[x].mes)/2);
            vector<regFecha>:: iterator it = fecha.begin();
            fecha.insert(it,aux);
        }


}

void Gridfile::apuntarColumnas(int x){
    int i = 0;
    for(int y=0;y<(int)getsizeFila();y++){
        i = 0;
        while (i<(int)zonas.size() && !(zonas[i]->pertenece(x,y)))
            i++;

        if (i < (int)zonas.size() && !zonas[i]->pertenece(x,y))
            matriz[y][x-1] = zonas[i]->getBalde();
        else
            matriz[y][x-1] = matriz[y][x];

    }
}

//recursivo!!
void Gridfile::addElemento(int id,int pos, int mes, int anio, int cant){
    // obtenemos la posicion en las escalas correspondientes
    int x = getposFecha(mes,anio);
    int y = getposCantidad(cant);

    // obtengo el balde en donde tengo que agregar el valor
    Balde *b = matriz[y][x];

    // consulto si el balde no se encuentra completo
    if(!b->completo()){
        b->agregarBalde(id,pos,mes,anio,cant);
    }else{
        //Si esta lleno obtengo la zona correspondiente a el punto
        Zona *original = getZona(x,y);

        int distancia = (original->getXfinal()-original->getXinicial());
        //Esto quiere decir que solo hay un puntero apuntado a el balde
        if (distancia == 1)
        {
            agregarColumna(original->getXinicial());
            addescFecha(original->getXinicial());

            Zona * nz = new Zona();
            nz->setPosicion(original->getXinicial(),original->getYinicial(),original->getXfinal(),original->getYfinal());

            if(original->getXinicial() > 0 && original->getXfinal() < getsizeColumna())
            {
                for (int i = 0 ; i< zonas.size();i++){
                    if(original->getXfinal() >= zonas[i]->getXinicial()){
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);

                    }
                    if (original->getXfinal() == zonas[i]->getXfinal() && !zonas[i]->iguales(original))
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                    if (zonas[i]->iguales(original)){
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                    }
                }
            }
            else
            if(original->getXinicial() == 0)
            {
                for(int i = 0; i<zonas.size();i++){
                    if(zonas[i]->getXinicial() == 0 && !zonas[i]->iguales(original))
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                    if(zonas[i]->getXinicial() > 0){
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                        }
                    if (zonas[i]->iguales(original)){
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                    }
                }

            }
            else
            if (original->getXfinal() == getsizeColumna())
            {
                for(int i = 0; i<zonas.size();i++){
                    if(zonas[i]->getXfinal() == getsizeColumna() && !zonas[i]->iguales(original))
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                if (zonas[i]->iguales(original)){
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                    }
                }
            }

            // apunto la columna a sus baldes correspondientes
            apuntarColumnas(original->getXinicial());

            //estirarZonas(original);


            Balde * nuevo = new Balde();
            nz->setBalde(nuevo);

            asignarZona(nz);
            cout << endl;
            cout << "Las zonas son: " << endl;
            for(int i = 0; i<zonas.size();i++){
                zonas[i]->mostrar();
                cout << endl;
            }

            Balde *lleno = original->getBalde();

            lleno->divFecha(nuevo,fecha[original->getXinicial()-1].mes,fecha[original->getXinicial()-1].anio);
        }
        else{
            //debo dividir la zona y crear un nuevo balde
        }
        addElemento(id,pos,mes,anio,cant);
    }
}

void Gridfile::mostrar(int y,int x)

{
    matriz[y][x]->mostrar();
}

int Gridfile::getsizeColumna(){
    return matriz[0].size();
}

int Gridfile::getsizeFila(){
    return matriz.size();
}


void Gridfile::agregarColumna(int pos){
    vector<Balde*>::iterator it;
    for(int i = 0; i<getsizeFila(); i++){
        it = matriz[i].begin();
        matriz[i].insert(it+pos,NULL);
    }

}
void Gridfile::agregarFila(int pos){
    vector<Balde*> aux;
    vector<vector<Balde*> >::iterator it;
    it = matriz.begin();

    for(int i; i<getsizeColumna();i++)
        aux.push_back(NULL);

    matriz.insert(it+pos,aux);
}

