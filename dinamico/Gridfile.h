#ifndef GRIDFILE_H
#define GRIDFILE_H
#include "Balde.h"
#include "Zona.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct regFecha{
    int anio;
    int mes;
};


class Gridfile
{
    public:
        Gridfile();
        virtual ~Gridfile();

        void addFecha(int,int);
        void addCantidad(int);

        int getposFecha(int,int);
        int getposCantidad(int);

        Balde* getBalde(int,int);
        Zona* getZona(int,int);

        void mostrar(int,int);

        void addescFecha(int);

        void addElemento(int,int,int,int,int);

        void addxCantidad(int,int,int,int,int);

        vector<int>* consultar(int,int,int,int,int,int);

        void todos();

    protected:
    private:
        vector<vector<Balde*> > matriz;
        vector<regFecha> fecha;
        vector<int> cantidad;
        vector<Zona*> zonas;


        void insertCantidad(int);
        void insertFecha(int,int);

        int getsizeColumna();
        int getsizeFila();

        void agregarColumna(int pos);
        void agregarFila(int pos);

};

#endif // GRIDFILE_H
