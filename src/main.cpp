#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
    
void copiar(char a[100],char b[100]){
	for (int i=0;i<100;i++)
	{
		b[i] = a[i];
	}
}

int main(int argc, char *argv[])
{
	//Abrimos el archivo
    ifstream f("./datos_medicamentos.dat");
    if (!f)
        cout << "fallo\n";

    /* Declaramos un array con suficiente tama�o para leer las l�neas */
    char cadena[256];
    
    /* Leemos */
    char a[100];

    /* Leemos la siguiente l�nea */
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

    f.close();    
    
    system("pause");
    return EXIT_SUCCESS;

	struct regMedicamento
	{
		//una secuencia de hasta 8 caracteres num�ricos. (0 a 99999999)
		int nro_registro;

		//puede contener un m�ximo de 256 caracteres (letras y n�meros).
		char descripcion[100];

		// puede contener un m�ximo de 16 caracteres (letras y n�meros).
		char laboratorio[16];

		//una secuencia de hasta 4 caracteres num�ricos. (0 a 9999)
		short int accion_medicamento;

		//una secuencia de hasta 2 caracteres num�ricos. (0 a 99)
		short int forma_medicamento;

		//una secuencia de hasta 2 caracteres num�ricos. (0 a 99)
		short int tamanio_medicamento;

		//una secuencia de hasta 2 caracteres num�ricos. (0 a 99)
		short int via_administracion;

		//una secuencia de hasta 3 caracteres num�ricos, una coma decimal y 2 caracteres num�ricos m�s.
		float precio;
	};
    
}
