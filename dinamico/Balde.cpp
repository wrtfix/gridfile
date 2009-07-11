#include "Balde.h"


Balde::Balde()
{

}

Balde::~Balde()
{
    //dtor
}

int Balde::getMaximo(){
    return CAPACIDAD_BALDE;
}

int Balde::getMes(int pos){
    return elementos[pos].mes;
}

int Balde::getAnio(int pos){
    return elementos[pos].anio;
}
int Balde::getCantidad(int pos){
    return elementos[pos].cantidad;
}
void Balde::eliminarElemento(int id){
        vector<regBalde>::iterator it = elementos.begin();
        int i=0;
        while ((i<(int)elementos.size()) && (elementos[i].id_productor!=id))
                i++;
        elementos.erase(it+i);
}

int Balde::getPos(int pos){
    return elementos[pos].pos;
}

int Balde::getId(int pos){
    return elementos[pos].id_productor;
}

void Balde::agregarBalde(int id, int posicion,int mes,int anio, int cantidad){
    if(elementos.size()< CAPACIDAD_BALDE){
        regBalde aux;
        aux.id_productor=id;
        aux.pos=posicion;
        aux.anio=anio;
        aux.mes=mes;
        aux.cantidad = cantidad;
        elementos.push_back(aux);
    }
}

bool Balde::completo(){
    if(elementos.size() == CAPACIDAD_BALDE)
        return true;
    else
        return false;

}

void Balde::mostrar(){
    for(int i = 0; i<(int)elementos.size();i++){
            cout<<elementos[i].id_productor<<endl;
        }
    }



void Balde::divFecha(Balde *&nuevo, int mes, int anio){
    int i = 0;
    vector<int> pos;

    while(i<elementos.size()){
        if (elementos[i].anio <= anio)
           if(elementos[i].mes <= mes){
                pos.push_back(elementos[i].id_productor);
                nuevo->agregarBalde(elementos[i].id_productor,elementos[i].pos,elementos[i].mes,elementos[i].anio,elementos[i].cantidad);
        }
        i++;
    }

    for (i=0; i<(int)pos.size();i++)
        eliminarElemento(pos[i]);

}
