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

regMedicamento obtenerDato(const char *dir, int pos)
{
 	ifstream fentrada(dir, ios::in|ios::binary);
	fentrada.seekg(pos);
	regMedicamento aux;
	fentrada.read((char*)&aux,sizeof(regMedicamento));
   	fentrada.close();
	cout << aux.nro_registro << endl;
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
			for (int i = 0; i<100;i++)
				med.descripcion[i] = token1[i];
			
				
			token2 = strtok( NULL, seps );
			for (int i = 0; i<16;i++)
				med.laboratorio[i] = token2[i];
			
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
	//creo flujo de datos para almacenar en memoria con un nombre especifico
	ofstream my(pos,ios::out | ios::binary);
	for(int i=0;i<medicamentos.size();i++)
		my.write((const char*)(&medicamentos[i]), medicamentos.size());
	
	my.close();
}
int main(int argc, char *argv[])
{
	
	vector<regMedicamento> medicamentos;
    const char *dir = "./datos_medicamentos.dat";
    medicamentos = pasarArchivo(dir);
	
	const char *pos = "./unicen.gridfile";
    guardarArchivo(pos,medicamentos);
	
	regMedicamento pp;
	pp = obtenerDato(pos,2);
	
	cout << "Fin parte wrtfix" << endl << endl;
	
	Gridfile *g = new Gridfile();
	
	//accion 2 forma 2 precio 2 
	g->add(2,2,2,45);
	Balde *b = g->get(2,2,2);
	
	Balde *bb = new Balde();
	Balde *bb2 = new Balde();
	bb->add(20,2,2,12);
	bb->add(30,2,2,13);
	bb->add(40,2,2,14);
	bb->add(50,2,2,15);
	
	/*bb->imprimir();
	
	int posi = 3;
	regBalde r1 = bb->getReg(posi);
	cout << "posi = "<< posi << " valor " << r1.valor << endl;
	bb-> imprimir();
	
	posi = 1;
	regBalde r2 = bb->getReg(posi);
	cout << "posi = "<< posi << " valor " << r2.valor << endl;
	bb-> imprimir();
	
	regBalde r3 = bb->getReg(posi);
	cout << "posi = "<< posi << " valor " << r3.valor << endl;
	bb-> imprimir();
	
	posi = 0;
	regBalde r4 = bb->getReg(posi);
	cout << "posi = " << posi << " valor " << r4.valor << endl;
	bb-> imprimir();
	
	short int escalaAccion[16] = {0,54,56,57,58,59,60,64,0,0,0,0,0,0,0,0};
	short int escalaForma[16] = {0,1,2,3,4,5,11,0,0,0,0,0,0,0,0,0};
	float escalaPrecio[16] = {0.0,9.96,19.97,29.91,39.98,49.91,59.51,69.0,102.36,199.95,269.81,335.38,493.56,590.61,786.5};
	g->guardarEscalas(escalaAccion,escalaForma,escalaPrecio);
	*/
	
/*	cout << "bb: " << endl;
	bb->imprimir();
	
	short int accion;
	cout << "ingrese ACCION: ";
	cin >> accion;
	bb->divAccion(bb2,accion);
	
	cout << "bb: " << endl;
	bb->imprimir();
	cout << "bb2: "	<< endl;
	bb2->imprimir();
*/
   	return EXIT_SUCCESS;
}

