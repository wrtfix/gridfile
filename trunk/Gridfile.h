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

        void asignarBalde(Zona*);
        void asignarZona(Zona*);
        void mostrar(int,int);

        void addescFecha(int);

        void addElemento(int,int,int,int,int);

    protected:
    private:
        vector<vector<Balde*> > matriz;
        vector<regFecha> fecha;
        vector<int> cantidad;
        vector<Zona*> zonas;


        int getsizeColumna();
        int getsizeFila();

        void agregarColumna(int pos);
        void agregarFila(int pos);
        void apuntarColumnas(int);

};

#endif // GRIDFILE_H
