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
		//una secuencia de hasta 8 caracteres num�ricos. (0 a 99999999)
		long int nro_registro;

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
vector<regMedicamento> pasarArchivo(const char *dir)
{
    ifstream f(dir);
    if (!f)
        cout << "fallo\n";
	// Declaramos un array con suficiente tama�o para leer las l�neas.
    char cadena[256];

	regMedicamento med;
	vector<regMedicamento> medicamentos;
    
    while (!f.eof())
    {		
		f.getline(cadena,sizeof(cadena));
		char sd[256] = "";
		for (int i = 0; i<256;i++)
			sd[i] = cadena[i];
		
		char seps[] = ";\n\t";
		char *token0; 
		char *token1; 
		char *token2; 
		char *token3; 
		char *token4; 
		char *token5; 
		char *token6; 
		char *token7; 
	
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
			medicamentos.push_back(med);
		}
	}
    f.close();
	return medicamentos;    
}	
    //paso copia o paso punteros aca?
/*void guardarArchivo(const char *dir, std::vector<regMedicamento> *medicamentos)
{

	ofstream my(dir,, ios::out | ios::binary);
	for(int i=0;i<medicamentos->size();i++)
	{
		my<<medicamentos[i];
	}
	my.close();
}*/
int main(int argc, char *argv[])
{
	//Abrimos el archivo
    
    vector<regMedicamento> medicamentos;
    const char *dir = "./datos_medicamentos.dat";
    medicamentos = pasarArchivo(dir);

	ofstream my("./putoarchivo.flexible", ios::app);
	for(int i=0;i<medicamentos.size();i++)
	{
		my<<medicamentos[i].nro_registro;
		my<<medicamentos[i].descripcion;
		my<<medicamentos[i].laboratorio;
		my<<medicamentos[i].accion_medicamento;
		my<<medicamentos[i].forma_medicamento;
		my<<medicamentos[i].tamanio_medicamento;
		my<<medicamentos[i].via_administracion;
		my<<medicamentos[i].precio;
	}
	my.close();
	
	//guardarArchivo(pos,medicamentos);
	
	cout << "Fin parte wrtfix" << endl << endl;
	Gridfile *g = new Gridfile();
	g->add(2,2,2,45);
	Balde *b = g->get(2,2,2);
	cout << endl << "balde unico por ahora:" << endl;
	cout << "size: " << b->size() << endl;	
	b->imprimir();
	
   	return EXIT_SUCCESS;
}
