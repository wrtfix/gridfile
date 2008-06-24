#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
    
void copiar(char a[100];char b[100]){
	for (int i=0;i<100;i++)
	{
		b[i] = a[i];
	}
}

int main(int argc, char *argv[])
{
    ifstream f("./datos_medicamentos.dat");
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
    
    d = a;

    j = 0;
    i++;
    while(cadena[i] !=';')
    {
        a[j]= cadena[i];
        i++;
        j++;
    }
    
    char *g = new char;
    g = a;



    
    cout << d <<endl;
    
    
    
    
    
    f.close();
    
    
    system("pause");
    return EXIT_SUCCESS;
}
