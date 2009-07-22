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
    while (i<max && cantidad[i]<cant)
        i++;
    return i;
}

Balde * Gridfile::getBalde(int x, int y){
    return matriz[y][x];
}
Zona * Gridfile::getZona(int x,int y){
    int max = zonas.size();
    for(int i = 0; i < max;i++){
        if(zonas[i]->getXinicial()<= x && x<zonas[i]->getXfinal() && zonas[i]->getYinicial()<=y && y<zonas[i]->getYfinal())
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
    matriz[nueva->getYinicial()][nueva->getXinicial()] = nueva->getBalde();
    //asignarBalde(nueva);
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
    for(int y=0;y<(int)getsizeFila()-1;y++){
        i = 0;
        while (i<(int)zonas.size() && (zonas[i]->getXinicial() != x) && (zonas[i]->getYinicial() != y) )
            i++;

         matriz[y][x-1] = zonas[i]->getBalde();
    }
}
void Gridfile::insertCantidad(int cant){
    vector<int>::iterator it = cantidad.begin();
    int i =0;
    while(i<cantidad.size() && cantidad[i]<cant)
        i++;
    cantidad.insert(it+i,cant);
}

void Gridfile::insertFecha(int mes, int anio){
    vector<regFecha>::iterator it = fecha.begin();
    int i =0;
    while(i<fecha.size() && fecha[i].anio<anio)
        i++;
    while(fecha[i].anio == anio && fecha[i].mes < mes)
        i++;
    regFecha aux;
    aux.anio = anio;
    aux.mes = mes;
    fecha.insert(it+i,aux);
}

void Gridfile::addxCantidad(int id,int pos, int mes, int anio, int cant){
    bool agregado = false;
    int x = getposFecha(mes,anio);
    int y = getposCantidad(cant);

    Zona * original = getZona(x,y);
    Balde * b = matriz[y][x];

    if(!b->completo()){
        b->agregarBalde(id,pos,mes,anio,cant);
    }
    else
    {

        int pro = b->promedioCantidad(cant);
        if( pro != cant)
        {
            Zona *original = getZona(x,y);
            int distancia = original->getYfinal() - original->getYinicial();

            if( distancia == 1)
            {
                insertCantidad(pro);
                agregarFila(original->getYinicial());

                Zona * nz = new Zona();
                int xi = original->getXinicial();
                int yi = original->getYinicial();
                int xf = original->getXfinal();
                int yf = original->getYfinal();
                nz->setPosicion(xi,yi,xf,yf);

                for(int i =0; i<zonas.size();i++)
                {
                    if(zonas[i]->getYfinal() >= nz->getYfinal() && zonas[i]->getYinicial()<= nz->getYinicial() && !zonas[i]->iguales(nz))
                        zonas[i]->setYfinal(zonas[i]->getYfinal()+1);
                    else
                    if(zonas[i]->getYinicial() >= nz->getYfinal()){
                        zonas[i]->setYfinal(zonas[i]->getYfinal()+1);
                        zonas[i]->setYinicial(zonas[i]->getYinicial()+1);
                    }
                    else
                    if(zonas[i]->iguales(nz)){
                        zonas[i]->setYfinal(zonas[i]->getYfinal()+1);
                        zonas[i]->setYinicial(zonas[i]->getYinicial()+1);
                    }
                }

                Balde *nb = new Balde();

                b->divCantidad(nb,pro);

                nz->setBalde(nb);

                zonas.push_back(nz);

                int tos = 0;

                while(tos<zonas.size())
                {
                    for(int p=zonas[tos]->getXinicial();p<zonas[tos]->getXfinal();p++)
                        for(int a=zonas[tos]->getYinicial();a<zonas[tos]->getYfinal();a++){
                            matriz[a][p] = zonas[tos]->getBalde();
                    }
                    tos++;
                }

                }
                else
                {

                    Balde *nb = new Balde();

                    Zona *nz = new Zona();

                    int i = 0;
                    while(i<cantidad.size() && cantidad[i-1]<=pro)
                        i++;

                    b->divCantidad(nb,cantidad[i-1]);

                    int xi = original->getXinicial();
                    int yi = original->getYinicial();
                    int xf = original->getXfinal();
                    int yf = i;

                    nz->setPosicion(xi,yi,xf,yf);

                    original->setYinicial(i);

                    nz->setBalde(nb);

                    zonas.push_back(nz);

                    int tos = 0;

                    while(tos<zonas.size())
                    {
                        for(int p=zonas[tos]->getXinicial();p<zonas[tos]->getXfinal();p++)
                            for(int a=zonas[tos]->getYinicial();a<zonas[tos]->getYfinal();a++){
                                matriz[a][p] = zonas[tos]->getBalde();
                        }
                           tos++;
                        }

                }

            }
        else{
                addElemento(id,pos,mes,anio,cant);
                agregado = true;
        }
        if(!agregado){
            addxCantidad(id,pos, mes, anio, cant);
        }
    }
}
//recursivo!!
void Gridfile::addElemento(int id,int pos, int mes, int anio, int cant){
    int x = getposFecha(mes,anio);
    int y = getposCantidad(cant);

    Zona * original = getZona(x,y);
    Balde * b = matriz[y][x];

    if(!b->completo()){
        b->agregarBalde(id,pos,mes,anio,cant);
    }
    else
    {
        int prom;
        int proa;
        b->promedioFecha(anio,mes,proa,prom);
        if(proa != anio)
        {

            int distancia = original->getXfinal() - original->getXinicial();

            if( distancia == 1)
            {
                cout << "Flash!!!!!!!!!!"<<endl;
                cin.get();
                insertFecha(prom,proa);
                agregarColumna(original->getXinicial());

                Zona * nz = new Zona();
                int xi = original->getXinicial();
                int yi = original->getYinicial();
                int xf = original->getXfinal();
                int yf = original->getYfinal();

                nz->setPosicion(xi,yi,xf,yf);

                for(int i =0; i<zonas.size();i++)
                {
                    if(zonas[i]->getXfinal() >= nz->getXfinal() && zonas[i]->getXinicial()<= nz->getXinicial() && !zonas[i]->iguales(nz))
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                    else
                    if(zonas[i]->getXinicial() >= nz->getXfinal()){
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                    }
                    else
                    if(zonas[i]->iguales(nz)){
                        zonas[i]->setXfinal(zonas[i]->getXfinal()+1);
                        zonas[i]->setXinicial(zonas[i]->getXinicial()+1);
                    }
                }

                Balde *nb = new Balde();
                cout << prom<<"  "<<proa<<endl;
                b->divFecha(nb,prom,proa);

                b->mostrar();
                cin.get();
                nz->setBalde(nb);

                zonas.push_back(nz);

                int tos = 0;

                while(tos<zonas.size())
                {
                    for(int p=zonas[tos]->getXinicial();p<zonas[tos]->getXfinal();p++)
                        for(int a=zonas[tos]->getYinicial();a<zonas[tos]->getYfinal();a++){
                            matriz[a][p] = zonas[tos]->getBalde();
                    }
                    tos++;
                }

            }
            else
            {

                Balde *nb = new Balde();

                Zona *nz = new Zona();

                int i = 0;
                while(i<fecha.size() && fecha[i].anio<=proa)
                    i++;
                while(i<fecha.size() && fecha[i].anio==proa && fecha[i].mes<=mes)
                    i++;

                b->divFecha(nb,fecha[i].mes,fecha[i].anio);

                    int xi = original->getXinicial();
                    int yi = original->getYinicial();
                    int xf = i;
                    int yf = original->getYfinal();

                    nz->setPosicion(xi,yi,xf,yf);

                    original->setXinicial(i);

                    nz->setBalde(nb);

                    zonas.push_back(nz);

                    int tos = 0;

                    while(tos<zonas.size())
                    {
                        for(int p=zonas[tos]->getXinicial();p<zonas[tos]->getXfinal();p++)
                            for(int a=zonas[tos]->getYinicial();a<zonas[tos]->getYfinal();a++){
                                matriz[a][p] = zonas[tos]->getBalde();
                            }
                        tos++;
                    }

                }

            }
        else
            cout<<"La densidad del archivo no es soportada por la estructa ERROR!!"<<endl;

        addElemento(id,pos,mes,anio,cant);
    }

}
void Gridfile::mostrar(int y,int x)
{
    matriz[y][x]->mostrar();
}
void Gridfile::todos()
{
    for(int i =0;i<cantidad.size();i++)
        cout << cantidad[i]<< " ";
    for(int i=0;i<getsizeColumna();i++)
        for(int j=0; j<getsizeFila();j++){
            cout<< " en x "<<i<<" en y "<<j << endl;
            mostrar(j,i);
        }
}
vector<int> * Gridfile::consultar(int anio1,int anio2, int mes1,int mes2,int cant1,int cant2){

    int yi = getposCantidad(cant1);
    int xi = getposFecha(mes1,anio1);

    int yf = getposCantidad(cant2);
    int xf = getposFecha(mes2,anio2);

    vector<int> *aux = new vector<int>();
    vector<int> *obtiene = new vector<int>();

    for(yi;yi<yf;yi++)
        for(xi;xi<xf;xi++){
            obtiene = matriz[yi][xi]->getElementos();
            for(int i=0; i<(*obtiene).size();i++)
                aux->push_back((*obtiene)[i]);
            }

    return aux;
}

int Gridfile::getsizeColumna(){
    vector<Balde*> aux;
    aux = matriz[0];
    return aux.size();
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

void Gridfile::agregarFila(int pos)
{
    vector<Balde*> aux;
    vector<vector<Balde*> >::iterator it;
    it = matriz.begin();
    for(int i=0; i < getsizeColumna();i++)
    {
        Balde *b  = new Balde();
        aux.push_back(b);
    }
    matriz.insert(it+pos,aux);
}
