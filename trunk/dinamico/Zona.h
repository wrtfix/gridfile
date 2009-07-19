#ifndef ZONA_H
#define ZONA_H
#include "Balde.h"

class Zona
{
    public:
        Zona();
        virtual ~Zona();
        int getXinicial();
        int getYinicial();
        int getXfinal();
        int getYfinal();
        Balde * getBalde();
        void setBalde(Balde*);
        void setPosicion(int,int,int,int);
        void setXinicial(int);
        void setYinicial(int);
        void setXfinal(int);
        void setYfinal(int);
        bool pertenece(int,int);
        bool iguales(Zona*);
        void mostrar();
    protected:

    private:
        int xini;
        int yini;
        int xfin;
        int yfin;
        Balde *mibalde;
};

#endif // ZONA_H
