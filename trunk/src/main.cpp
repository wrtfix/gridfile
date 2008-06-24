#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
    


int main(int argc, char *argv[])
{
    ifstream f("C:/Users/jorge/Desktop/Estructura/datos_medicamentos.dat");
    if(!f)
        cout << "fallo\n";

    /* Declaramos un array con suficiente tamaño para leer las líneas */
    char cadena[256];
      /* Leemos */
    char a[100];

    /* Leemos la siguiente línea */
    f.getline(cadena,sizeof(cadena));
    cout << cadena<<"\n";
    int i = 0;
    
    while(cadena[i] !=';')
    {
        a[i]= cadena[i];
        i++;
    }
    
    
    int nro_registro;
    nro_registro = atoi(a);
    cout << nro_registro << endl;

    i++;
    int j =0;
    
    while(cadena[i] !=';')
    {
        a[j]= cadena[i];
        i++;
        j++;
    }
    


    char *d = new char;
    
    d = a;
    
    cout << d <<endl;
    
    f.close();
    
    
    system("pause");
    return EXIT_SUCCESS;
}
