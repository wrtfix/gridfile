#include "Balde.h"


Balde::Balde()
{
    elementos = new vector<regBalde>();
}

Balde::~Balde()
{
    //dtor
}

int Balde::getMaximo(){
    return elementos->size();
}

int Balde::getMes(int pos){
    return (*elementos)[pos].mes;
}

int Balde::getAnio(int pos){
    return (*elementos)[pos].anio;
}
int Balde::getCantidad(int pos){
    return (*elementos)[pos].cantidad;
}
void Balde::eliminarElemento(int pos){
        vector<regBalde>::iterator it = elementos->begin();
        int i=0;
        while ((i<elementos->size()) && ((*elementos)[i].pos!=pos))
                i++;
        elementos->erase(it+i);
}

int Balde::getPos(int pos){
    return (*elementos)[pos].pos;
}

int Balde::getId(int pos){
    return (*elementos)[pos].id_productor;
}
void Balde::actualizar(){
    int i =0;
    vector<regBalde>::iterator it = elementos->begin();
    while(i<elementos->size()){
        if((*elementos)[i].borrado == 1)
            elementos->erase(it+i);
        i++;
    }
}

bool Balde::igualesCantidad(int cant){
    int i =0;
    while(i<elementos->size())
    {
        if((*elementos)[i].cantidad != cant)
            return false;
        i++;
    }
    return true;
}
bool Balde::igualesFecha(int mes, int anio){
    int i =0;
    while(i<elementos->size()){
        if((*elementos)[i].anio != anio || (*elementos)[i].mes != mes)
            return false;
        i++;
    }
    return true;
}
void Balde::agregarBalde(int id, int posicion,int mes,int anio, int cantidad){
            regBalde aux;
            vector<regBalde>::iterator it = elementos->begin();
            int i=0;
            while(i<elementos->size() && (*elementos)[i].id_productor < id)
                i++;

            aux.id_productor=id;
            aux.pos=posicion;
            aux.anio=anio;
            aux.mes=mes;
            aux.cantidad = cantidad;
            aux.borrado = 0;
            elementos->insert(it+i,aux);
}

bool Balde::completo(){
    if(elementos->size() >= CAPACIDAD_BALDE)
        return true;
    else
        return false;

}

void Balde::mostrar(){
    for(int i = 0; i<elementos->size();i++){
            cout<<(*elementos)[i].id_productor<<endl;
        }
    }

int Balde::promedioCantidad(int cantidad){
    int suma =cantidad;
    for(int i=0; i< elementos->size();i++)
        suma+=(*elementos)[i].cantidad;

    int res = (suma / (int)(elementos->size()+1));
    return res;
}

void Balde::promedioFecha(int anio, int mes, int &anior, int &mesr){
    anior = anio;
    mesr = mes;
    for (int i=0; i<elementos->size();i++){
        anior += (*elementos)[i].anio;
        mesr += (*elementos)[i].mes;
        }
    anior = (anior / (elementos->size()+1));
    mesr = (mesr / (elementos->size()+1));
}

void Balde::divFecha(Balde *&nuevo, int mes, int anio){
    int i = 0;
    vector<int> pos;

    while(i<elementos->size()){
        if ((*elementos)[i].anio < anio){
            pos.push_back((*elementos)[i].pos);
            nuevo->agregarBalde((*elementos)[i].id_productor,(*elementos)[i].pos,(*elementos)[i].mes,(*elementos)[i].anio,(*elementos)[i].cantidad);
        }
        else
        {
            if ((*elementos)[i].anio == anio){
                if((*elementos)[i].mes <= mes){
                    pos.push_back((*elementos)[i].pos);
                    nuevo->agregarBalde((*elementos)[i].id_productor,(*elementos)[i].pos,(*elementos)[i].mes,(*elementos)[i].anio,(*elementos)[i].cantidad);
                }

        }}
        i++;
    }
    for (i=0; i<pos.size();i++)
        eliminarElemento(pos[i]);
}
vector<regBalde>* Balde::getElementos()
{
    return elementos;
}


void Balde::divCantidad(Balde *&nuevo,int cant){
    vector<int> elim;
    for(int i=0; i<elementos->size();i++)
    {
        if((*elementos)[i].cantidad<=cant)
        {
            elim.push_back((*elementos)[i].pos);
            nuevo->agregarBalde((*elementos)[i].id_productor,(*elementos)[i].pos,(*elementos)[i].mes,(*elementos)[i].anio,(*elementos)[i].cantidad);
        }
    }

    for(int i=0; i<elim.size();i++){
        eliminarElemento(elim[i]);
    }

}
void Balde::setBorrado(int pos){
    (*elementos)[pos].borrado = 1;
}
bool Balde::overflow(){
    if (elementos->size()+1>=CAPACIDAD_BALDE)
        return true;
    return false;
}

bool Balde::getBorrado(int pos){
    return ((*elementos)[pos].borrado == 1);
}
