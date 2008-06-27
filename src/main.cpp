#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct regMedicamento
{
		//una secuencia de hasta 8 caracteres numéricos. (0 a 99999999)
		int nro_registro;

		//puede contener un máximo de 256 caracteres (letras y números).
		char descripcion[100];

		// puede contener un máximo de 16 caracteres (letras y números).
		char laboratorio[16];

		//una secuencia de hasta 4 caracteres numéricos. (0 a 9999)
		short int accion_medicamento;

		//una secuencia de hasta 2 caracteres numéricos. (0 a 99)
		short int forma_medicamento;

		//una secuencia de hasta 2 caracteres numéricos. (0 a 99)
		short int tamanio_medicamento;

		//una secuencia de hasta 2 caracteres numéricos. (0 a 99)
		short int via_administracion;

		//una secuencia de hasta 3 caracteres numéricos, una coma decimal y 2 caracteres numéricos más.
		float precio;
};
    
int main(int argc, char *argv[])
{
	//Abrimos el archivo
    ifstream f("./datos_medicamentos.dat");
    if (!f)
        cout << "fallo\n";

    /* Declaramos un array con suficiente tamaño para leer las líneas */
    char cadena[256];
    
   
    /* Leemos la siguiente línea */
    f.clear();
    
    while (!f.eof())
    {
    
    f.getline(cadena,sizeof(cadena));
    
    
    char string[] = "";
	for (int i = 0; i<100;i++){
		string[i] = cadena[i];
	}
	
	char seps[] = ";";
	char *token0; 
	char *token1; 
	char *token2; 
	char *token3; 
	char *token4; 
	char *token5; 
	char *token6; 
	char *token7; 
	regMedicamento med;
    /* Establish string and get the first token: */
	token0 = strtok( string, seps );
	med.nro_registro = atoi(token0);
	
	token1 = strtok( NULL, seps );
	for (int i = 0; i<100;i++)
		med.descripcion[i] = token1[i];
	
		
	token2 = strtok( NULL, seps );
	for (int i = 0; i<100;i++)
		med.laboratorio[i] = token2[i];
	
	token3 = strtok( NULL, seps );
	med.accion_medicamento = atoi(token3);		
	
	token4 = strtok( NULL, seps );
	med.forma_medicamento = atoi(token4);
	
	token5 = strtok( NULL, seps );
	med.tamanio_medicamento = atoi(token5);
		
	
	token6 = strtok( NULL, seps );
	med.via_administracion = atoi(token6);
	printf( " %d\n", med.via_administracion);
	
	token7 = strtok( NULL, seps );
	med.precio = atof(token7);
	
	}
	  
    f.close();
    
   	return EXIT_SUCCESS;
}
