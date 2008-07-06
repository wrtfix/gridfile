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
    //cout << aux.accion_medicamento << " "<< aux.forma_medicamento << " " << aux.precio << "  "<<aux.laboratorio<< " "<< aux.descripcion <<endl;
    fclose(f);
    return aux;

}

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
		char seps[] = ";\'";
		
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
        cout << medicamentos[i].descripcion<<endl;
        fwrite(&medicamentos[i], sizeof(regMedicamento), 1, f);
    }
    fclose(f);

}
int main(int argc, char *argv[])
{
	vector<regMedicamento> medicamentos;
    const char *dir = "C:/Documents and Settings/Jorge/Desktop/new/src/datos_medicamentos.dat";
    medicamentos = pasarArchivo(dir);
	
	const char *pos = "C:/Documents and Settings/Jorge/Desktop/new/src/unicen.gridfile";
    guardarArchivo(pos,medicamentos);
    long i = 0;
    
	cout << "Fin parte wrtfix" << endl << endl;
	
	Gridfile *g = new Gridfile();

  	Zona *zonita0 = new Zona(0,0,0,7,7,15);
	Zona *zonita1 = new Zona(8,0,0,15,7,15);
	Zona *zonita2 = new Zona(0,8,0,7,15,15);
	Zona *zonita3 = new Zona(8,8,0,15,15,15);
	
	Balde* baldex0 = new Balde();
	Balde* baldex1 = new Balde();
   	Balde* baldex2 = new Balde();
	Balde* baldex3 = new Balde();

    zonita0->setBalde(baldex0);
    zonita1->setBalde(baldex1);
    zonita2->setBalde(baldex2);
    zonita3->setBalde(baldex3);
    
    g->addZona(zonita0);
	g->addZona(zonita1);
	g->addZona(zonita2);
	g->addZona(zonita3);
	
	g->asigBalde(zonita0);
	g->asigBalde(zonita1);
	g->asigBalde(zonita2);
	g->asigBalde(zonita3);			
	
	short int escalaAccion[16] = {1,20,30,40,50,60,70,80,90,100,200,300,500,600,1000};
	short int escalaForma[16] = {55,55,55,55,55,55,55,55,55,55,55,57,59,58,61,65};
	float escalaPrecio[16] = {0.0,9.96,19.97,29.91,39.98,49.91,59.51,69.0,102.36,199.95,269.81,335.38,493.56,590.61,777};

	g->guardarEscalas(escalaAccion,escalaForma,escalaPrecio);

    while(i<48){
		cout << i << " ";
		regMedicamento reg = obtenerDato(pos,i);
		cout << "a: " << reg.accion_medicamento;
		cout << "  f: " << reg.forma_medicamento;
		cout << "  p: " << reg.precio << endl;
		g->add(reg.accion_medicamento,reg.forma_medicamento,reg.precio,i);
		i++;
		
		cout << "BALDES x ZONA: " << endl;
		zonita0->getBalde()->imprimir();
		zonita1->getBalde()->imprimir();
		zonita2->getBalde()->imprimir();
		zonita3->getBalde()->imprimir();
    }
    
	cout << " G R I D F I L E " << endl;

    g->imprimir();

    system("PAUSE");
    return EXIT_SUCCESS;
}
