#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Balde.h"
#include "Gridfile.h"

using namespace std;

struct regMedicamento
{
		//una secuencia de hasta 8 caracteres numéricos. (0 a 99999999)
		long int nro_registro;

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

//esta funcion debuelbe toda la info de un archivo de texto en un vector de tipo regMedicamento
vector<regMedicamento> pasarArchivo(const char *dir)
{
    // creo un flujo de datos con una nombre (dir)
    ifstream f(dir);
    if (!f)
        cout << "fallo\n";
	
	// Declaramos un array con suficiente tamaño para leer las líneas del archivo
    char cadena[256];

	//variable auxiliar para ir cargando los dato que seran guardado en un vector
	regMedicamento med;
	
	//vector que retornare una vez cargados los datos
	vector<regMedicamento> medicamentos;
    
    while (!f.eof())
    {		
		f.getline(cadena,sizeof(cadena));
		char sd[256] = "";
		for (int i = 0; i<256;i++)
			sd[i] = cadena[i];
		
		//arreglo con los elementos que divide la informacion en este caso ;
		char seps[] = ";\n\t";
		
		//elementos en donde guardo la informacion mientras la voy dividiendo
		char *token0; 
		char *token1; 
		char *token2; 
		char *token3; 
		char *token4; 
		char *token5; 
		char *token6; 
		char *token7; 
	
		//divido el reglo por hasta llegar a un null y guardo en el registro
		token0 = strtok( sd, seps );
		if (token0 !=NULL){
			
			med.nro_registro = atol(token0);
			printf( " %li\n", med.nro_registro);
		
			token1 = strtok( NULL, seps );
			for (int i = 0; i<100;i++)
				med.descripcion[i] = token1[i];
			
			printf( " %s\n", med.descripcion);
				
			token2 = strtok( NULL, seps );
			for (int i = 0; i<16;i++)
				med.laboratorio[i] = token2[i];
			printf( " %s\n", med.laboratorio);
			
			token3 = strtok( NULL, seps );
			med.accion_medicamento = atoi(token3);		
			printf( " %i\n", med.accion_medicamento);
			
			
			token4 = strtok( NULL, seps );
			med.forma_medicamento = atoi(token4);
			printf( " %i\n", med.forma_medicamento);
			
			token5 = strtok( NULL, seps );
			med.tamanio_medicamento = atoi(token5);
			printf( " %d\n", med.tamanio_medicamento);
				
			token6 = strtok( NULL, seps );
			med.via_administracion = atoi(token6);
			printf( " %d\n", med.via_administracion);
			
					
			token7 = strtok( NULL, seps);	
			med.precio = atof(token7);
			printf(" %f\n", med.precio);

			//agrego el registro med en el vector medicamentos
			medicamentos.push_back(med);
		}
	}
    f.close();
	return medicamentos;    
}	
//paso copia o paso punteros aca?
void guardarArchivo(const char *pos,vector<regMedicamento> &medicamentos)
{
	regMedicamento aux;
	//creo flujo de datos para almacenar en memoria con un nombre especifico
	ofstream my(pos,ios::out | ios::binary);
	for(int i=0;i<medicamentos.size();i++)
		my.write(reinterpret_cast<char *>(&medicamentos[i]), medicamentos.size());
	
	my.close();
}
int main(int argc, char *argv[])
{
	vector<regMedicamento> medicamentos;
    const char *dir = "./datos_medicamentos.dat";
    medicamentos = pasarArchivo(dir);
	
	const char *pos = "./unicen.gridfile";
    guardarArchivo(pos,medicamentos);
	
	cout << "Fin parte wrtfix" << endl << endl;
	Gridfile *g = new Gridfile();
	g->add(2,2,2,45);
	Balde *b = g->get(2,2,2);
	cout << endl << "balde unico por ahora:" << endl;
	cout << "size: " << b->size() << endl;	
	b->imprimir();
   	return EXIT_SUCCESS;
}

