#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



regMedicamento obtenerDato(const char *dir, long pos)
{
    FILE *f = fopen(dir,"rb+");
	regMedicamento aux;
   	fseek(f,(long)(pos*sizeof(struct regMedicamento)), SEEK_SET);
    fread(&aux, sizeof(struct regMedicamento), 1, f);
//    cout << aux.accion_medicamento << " "<< aux.forma_medicamento << " " << aux.precio << "  "<<aux.laboratorio<< " "<< aux.descripcion <<endl;
    fclose(f);
    return aux;

}

//esta funcion debuelbe toda la info de un archivo de texto en un vector de tipo regMedicamento
vector<regMedicamento> pasarArchivo(const char *dir)
{
    // creo un flujo de datos con una nombre (dir)
    ifstream f(dir);
    if (!f)
        cout << "fallo/n";
	
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
		char seps[] = ";/'";
		
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
		
			token1 = strtok( NULL, seps );
            strcpy(med.descripcion,token1);

			token2 = strtok( NULL, seps );
            strcpy(med.laboratorio,token2);
            
			token3 = strtok( NULL, seps );
			med.accion_medicamento = atoi(token3);		
			
			
			token4 = strtok( NULL, seps );
			med.forma_medicamento = atoi(token4);
			
			token5 = strtok( NULL, seps );
			med.tamanio_medicamento = atoi(token5);
			
			token6 = strtok( NULL, seps );
			med.via_administracion = atoi(token6);
					
			token7 = strtok( NULL, seps);	
			med.precio = atof(token7);

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
	
    FILE *f = fopen(pos,"wb+");
    rewind(f);
	for(int i=0;i<medicamentos.size();i++)
	{
        //cout << medicamentos[i].descripcion<<endl;
        fwrite(&medicamentos[i], sizeof(regMedicamento), 1, f);
    }
    fclose(f);

}
int main(int argc, char *argv[])
{
	vector<regMedicamento> medicamentos;
    const char *dir = "C:/Documents and Settings/pirata/Escritorio/gridfile/src/datos_medicamentos.dat";
    medicamentos = pasarArchivo(dir);
	
	const char *pos = "C:/Documents and Settings/pirata/Escritorio/gridfile/src/unicen.gridfile";
    guardarArchivo(pos,medicamentos);
    long i = 0;
    
	Gridfile *g = new Gridfile();
	
	short int escalaAccion[16] = {1,20,30,40,50,60,70,80,90,100,150,250,350,500,600,1000};
	short int escalaForma[8] = {54,56,57,58,59,60,63,64};
	float escalaPrecio[64]={2.15,2.93,3.8,4.39,5.08,5.75,6.4,6.95,7.19,7.93,8.32,8.74,9.26,9.8,10.07,10.66,11.06,11.53,12.1,12.76,13.15,13.72,14.54,14.9,15.33,15.84,16.55,17.29,18.46,19.21,19.69,20.29,21.22,22.12,22.94,
    23.83,24.53,25.12,25.6,26.32,27.35,28.7,29.79,30.8,32.19,33.7,35,36,37.9,38.5,42,45,48.14,50.42,52.86,58.15,62.8,71.97,81.58,95.01,117.11,157.25,234.86,999};

	g->guardarEscalas(escalaAccion,escalaForma,escalaPrecio);

    while(i<1000){
		regMedicamento reg = obtenerDato(pos,i);
		g->add(reg.accion_medicamento,reg.forma_medicamento,reg.precio,i);
		i++;
    }
    
    g->imprimir();
    system("PAUSE");
    return EXIT_SUCCESS;
}
