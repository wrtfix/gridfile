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

    g.addElemento(10,10,2,350,500);
    g.addElemento(11,20,5,600,500);
    g.addElemento(12,30,5,700,500);
    g.addElemento(13,40,5,597,500);
    g.addElemento(14,50,5,550,500);

    g.addElemento(21,60,5,1500,500);
    g.addElemento(31,70,7,100,1500);
    g.addElemento(41,80,7,1500,1500);

    cout << "Mostrar balde 1"<<endl;
    g.mostrar(0,0);
    cout << "Mostrar balde 2"<<endl;
    g.mostrar(0,1);
    cout << "Mostrar balde 3"<<endl;
    g.mostrar(1,0);
    cout << "Mostrar balde 4"<<endl;
    g.mostrar(1,1);

    // pruebba de rotura!!
    g.addElemento(151,90,2,499,500);
    g.addElemento(152,90,2,159,500);
    g.addElemento(153,90,2,49,500);
    g.addElemento(154,90,2,4,500);

    cout << "Muestro el nuevo balde 0,0"<<endl;
    g.mostrar(0,0);

    cout << "Muestro el nuevo balde 0,1"<<endl;
    g.mostrar(0,1);

    cout << "Muestro el nuevo balde 0,2"<<endl;
    g.mostrar(0,2);

    cout << "Muestro el nuevo balde 1,0"<<endl;
    g.mostrar(1,0);

    cout << "Muestro el nuevo balde 1,1"<<endl;
    g.mostrar(1,1);

    cout << "Muestro el nuevo balde 1,2"<<endl;
    g.mostrar(1,2);

   /* g.addElemento(155,90,2,5,500);
    cout << endl<<endl;

    cout << "Muestro el nuevo balde 0,0"<<endl;
    g.mostrar(0,0);

    cout << "Muestro el nuevo balde 0,1"<<endl;
    g.mostrar(0,1);

    cout << "Muestro el nuevo balde 0,2"<<endl;
    g.mostrar(0,2);

    cout << "Muestro el nuevo balde 0,3"<<endl;
    g.mostrar(0,3);

    cout << "Muestro el nuevo balde 1,0"<<endl;
    g.mostrar(1,0);*/

    cout << "Hello world!" << endl;
    return 0;
}
