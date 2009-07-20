#include <iostream>
#include "Gridfile.h"
using namespace std;

int main()
{
    Gridfile g;

    g.addFecha(6,1000);
    g.addFecha(12,2000);

    g.addCantidad(1000);
    g.addCantidad(2000);

    g.addxCantidad(10,1,2,1350,1500);
    g.addxCantidad(11,2,2,1350,1500);
    g.addxCantidad(12,3,2,1350,1500);
    g.addxCantidad(13,4,2,1350,1500);
    g.addxCantidad(14,5,2,1350,1500);

    g.addxCantidad(15,6,2,1350,1200);

    g.addxCantidad(17,13,2,1350,1900);

    g.addxCantidad(18,14,2,1350,1900);
    g.addxCantidad(19,15,2,1350,1900);
    g.addxCantidad(20,16,2,1350,1900);
    g.addxCantidad(21,17,2,1350,1900);

    g.addxCantidad(22,18,2,999,1800);

    g.addxCantidad(23,19,2,999,1800);
    g.addxCantidad(24,20,2,999,1800);
    g.addxCantidad(25,21,2,999,1800);
    g.addxCantidad(26,22,2,999,1500);

    g.addxCantidad(27,23,2,999,1500);

    g.addxCantidad(28,24,2,350,1550);

    g.addxCantidad(29,25,7,350,1550);
    g.addxCantidad(30,26,7,350,1550);
    g.addxCantidad(31,27,7,350,1440);
    g.addxCantidad(32,28,7,350,1470);
    g.addxCantidad(33,29,7,350,1480);
    g.addxCantidad(34,30,7,350,1545);

/*

    g.addxCantidad(26,14,2,350,300);
    g.addxCantidad(27,15,2,350,320);
    g.addxCantidad(28,16,2,350,350);
    g.addxCantidad(29,17,2,350,400);


    /*g.addxCantidad(30,18,7,350,1500);
    g.addxCantidad(31,19,7,350,1500);
    g.addxCantidad(32,20,7,350,1500);
    g.addxCantidad(33,21,7,350,1500);
    g.addxCantidad(34,22,7,350,1500);
    g.addxCantidad(35,23,7,350,1400);*/

    cout << "Muestro el nuevo balde 0,0"<<endl;
    g.mostrar(0,0);

    cout << "Muestro el nuevo balde 1,1"<<endl;
    g.mostrar(1,1);

    cout << "Muestro el nuevo balde 2,1"<<endl;
    g.mostrar(2,1);

    cout << "Muestro el nuevo balde 3,1"<<endl;
    g.mostrar(3,1);

    cout << "Muestro el nuevo balde 1,0"<<endl;
    g.mostrar(1,0);

    cout << "Muestro el nuevo balde 2,0"<<endl;
    g.mostrar(2,0);


    cout << "Muestro el nuevo balde 3,0"<<endl;
    g.mostrar(3,0);

    cout << "Hello world!" << endl;
    return 0;
}
