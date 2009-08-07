#ifndef BALDE_H
#define BALDE_H
#include <iostream>
#include <vector>

#define CAPACIDAD_BALDE 5

using namespace std;
// se agrego mes anio y cantidad para mejorar la distribucion de los elementos en el balde
typedef struct regBalde{
        int cantidad;
        int mes;
        int anio;
        int id_productor;
        int pos;
        int borrado;
};

class Balde
{
    public:
        Balde();
        virtual ~Balde();
        void agregarBalde(int id, int posicion,int mes, int anio,int cantidad);
        bool overflow();
        bool igualesCantidad(int);
        bool igualesFecha(int,int);
        int getPos(int pos);
        int getId(int pos);
        int getMes(int pos);
        int getAnio(int pos);
        int getCantidad(int pos);
        bool getBorrado(int pos);
        void mostrar();
        int getMaximo();
        bool completo();
        void divFecha(Balde*& nuevo, int,int);
        void divCantidad(Balde *& nuevo, int);
        int promedioCantidad(int);
        void promedioFecha(int,int,int&,int&);
        void actualizar();
        void setBorrado(int);
        vector<regBalde>* getElementos();
    protected:
    private:
        vector<regBalde> * elementos;
        void eliminarElemento(int pos);
};

#endif // BALDE_H
