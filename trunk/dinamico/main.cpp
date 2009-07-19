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

    g.addxCantidad(10,1,2,350,500);
    g.addxCantidad(11,2,2,350,500);
    g.addxCantidad(12,3,2,350,500);
    g.addxCantidad(13,4,2,350,500);
    g.addxCantidad(14,5,2,350,500);
    g.addxCantidad(15,6,2,350,200);
    g.addxCantidad(17,13,2,350,900);

    g.addxCantidad(18,19,2,350,300);
    g.addxCantidad(19,14,2,350,325);
    g.addxCantidad(30,15,2,350,315);
    g.addxCantidad(31,16,2,350,316);
    g.addxCantidad(32,17,2,350,215);
    g.addxCantidad(33,18,2,350,150);

    g.addxCantidad(20,7,7,1350,460);
    g.addxCantidad(21,8,7,1350,450);
    g.addxCantidad(22,9,7,1350,440);
    g.addxCantidad(23,10,7,1350,470);
    g.addxCantidad(24,11,7,1350,480);
    g.addxCantidad(25,12,7,1350,145);

    /*


    g.addxCantidad(26,14,2,350,300);
    g.addxCantidad(27,15,2,350,320);
    g.addxCantidad(28,16,2,350,350);
    g.addxCantidad(29,17,2,350,400);


    g.addxCantidad(30,18,7,1350,1500);
    g.addxCantidad(31,19,7,1350,1500);
    g.addxCantidad(32,20,7,1350,1500);
    g.addxCantidad(33,21,7,1350,1500);
    g.addxCantidad(34,22,7,1350,1500);
    g.addxCantidad(35,23,7,1350,1400);

    /*g.addElemento(10,10,2,350,500);
    g.addElemento(11,20,5,400,500);
    g.addElemento(12,30,5,450,500);
    g.addElemento(13,40,5,500,500);
    g.addElemento(14,50,5,550,500);

    g.addElemento(15,30,5,600,500);
    g.addElemento(16,40,5,700,500);
    g.addElemento(17,50,5,325,500);
    g.addElemento(18,50,5,324,500);
    g.addElemento(19,50,5,322,500);*/

    /*g.addElemento(21,60,5,1500,500);
    g.addElemento(22,60,6,1400,500);
    g.addElemento(23,60,7,1300,500);
    g.addElemento(24,60,8,1200,500);
    g.addElemento(25,60,9,1100,500);
    g.addElemento(26,60,10,900,500);


    g.addElemento(31,70,7,100,1500);
    g.addElemento(41,80,7,1500,1500);

    // prueba de rotura!!
    g.addElemento(151,90,2,499,500);
    g.addElemento(152,90,2,159,500);
    g.addElemento(153,90,2,49,500);
    g.addElemento(154,90,2,4,500);

    g.addElemento(155,90,2,5,500);
    g.addElemento(156,90,2,4,500);
    g.addElemento(157,90,2,3,500);
    g.addElemento(158,90,2,2,500);
    g.addElemento(159,90,2,1,500);

    g.addElemento(160,90,2,1,499);*/


    cout << "Muestro el nuevo balde 0,0"<<endl;
    g.mostrar(0,0);

    cout << "Muestro el nuevo balde 1,0"<<endl;
    g.mostrar(1,0);

    cout << "Muestro el nuevo balde 2,0"<<endl;
    g.mostrar(2,0);

    cout << "Muestro el nuevo balde 0,1"<<endl;
    g.mostrar(0,1);

    cout << "Muestro el nuevo balde 2,0"<<endl;
    g.mostrar(2,1);

    cout << "Muestro el nuevo balde 3,0"<<endl;
    g.mostrar(3,1);

    /*cout << "Muestro el nuevo balde 3,1"<<endl;
    g.mostrar(3,1);


    cout << "Muestro el nuevo balde 4,0"<<endl;
    g.mostrar(4,0);

    cout << "Muestro el nuevo balde 6,1"<<endl;
    g.mostrar(6,1);

    /*cout << "Muestro el nuevo balde 0,4"<<endl;
    g.mostrar(0,4);

    cout << "Muestro el nuevo balde 0,5"<<endl;
    g.mostrar(0,5);

    /*cout << "Muestro el nuevo balde 0,6"<<endl;
    g.mostrar(0,6);

    cout << "Muestro el nuevo balde 1,0"<<endl;
    g.mostrar(1,0);

    cout << "Muestro el nuevo balde 1,1"<<endl;
    g.mostrar(1,1);

    cout << "Muestro el nuevo balde 1,2"<<endl;
    g.mostrar(1,2);

    cout << "Muestro el nuevo balde 1,3"<<endl;
    g.mostrar(1,3);

    cout << "Muestro el nuevo balde 1,3"<<endl;
    g.mostrar(1,4);

    cout << "Muestro el nuevo balde 1,3"<<endl;
    g.mostrar(1,5);

    cout << "Muestro el nuevo balde 1,3"<<endl;
    g.mostrar(1,6);*/

    cout << "Hello world!" << endl;
    return 0;
}
