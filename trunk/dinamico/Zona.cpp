#include "Zona.h"

Zona::Zona()
{
    //ctor
}

Zona::~Zona()
{
    //dtor
}

int Zona::getXinicial(){
    return xini;
}
int Zona::getYinicial(){
    return yini;
}

int Zona::getXfinal(){
    return xfin;
}

int Zona::getYfinal(){
    return yfin;
}

Balde * Zona::getBalde(){
    return mibalde;
}
void Zona::setBalde(Balde* b){
    mibalde = b;
}

void Zona::setXinicial(int xinicial){
    xini = xinicial;
}
void Zona::setYinicial(int yinicial){
    yini = yinicial;
}

void Zona::setXfinal(int xfinal){
    xfin = xfinal;
}

void Zona::setYfinal(int yfinal){
    yfin = yfinal;
}

bool Zona::iguales(Zona *acomp){
    if( (xini == acomp->getXinicial()) && (yini == acomp->getYinicial()) && (xfin == acomp->getXfinal()) && (yfin == acomp->getYfinal()))
        return true;
    else
        return false;
    return false;
}

void Zona::setPosicion(int xi, int yi,int xf,int yf){
    xini = xi;
    yini = yi;
    xfin = xf;
    yfin = yf;
}

bool Zona::pertenece(int x,int y){
    if(xini<=x && x <= xfin){
        if(yini <= y && y<= yfin)
            return true;
    }
    return false;
}
void Zona::mostrar(){
    cout << "xi: "<< xini << "yi: "<< yini<<endl;
    cout << "xf: "<< xfin << "yf: "<< yfin<<endl;

}
