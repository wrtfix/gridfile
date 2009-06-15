/*
 *      main.cpp
 *
 *      Copyright 2008 	Jorge Carlos Mendiola <wrtfix@gmail.com> &
 * 						Manuel Alonso <manuel.alonso.d@gmail.com>
 *
 *
 * Este programa es de libre distribución; puedes distribuirlo y/o modificarlo
 * bajo los términos de la GNU General Public License como se publicó por la
 * Free Software Foundation; bien la versión 2 de la licencia o,  bajo tu
 * criterio, cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil, pero
 * SIN NINGUNA GARANTÏA; sin, incluso, ninguna garantía implicada por
 * MERCANCIBILIDAD o POR ALGÜN PROPÓSITO PARTICULAR. Lee la
 * GNU General Public License para más información.
 *
 * Deberías haber recibido una copia de la GNU General Public License
 * junto con este programa. Si no es así escribe a Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gridfile.h"

using namespace std;

//archivos
const char *datos_medicamentos = "./datos_medicamentos.dat";
const char *datos_altas = "./altas_medicamentos.dat";
const char *datos_bajas = "./bajas_medicamentos.dat";

const char *bin_medicamentos = "./datos_medicamentos.gridfile";
const char *bin_altas = "./altas_medicamentos.gridfile";
const char *bin_bajas = "./bajas_medicamentos.gridfile";

struct regMedicamento
{
        int borrado;
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

            med.borrado = 0;
			//agrego el registro med en el vector medicamentos
			medicamentos.push_back(med);
		}
	}
    f.close();
	return medicamentos;
}

void guardarArchivo(const char *pos,vector<regMedicamento> &medicamentos)
{

    FILE *f = fopen(pos,"wb+");
    rewind(f);
	for(int i=0;i<medicamentos.size();i++)
        fwrite(&medicamentos[i], sizeof(regMedicamento), 1, f);

    fclose(f);

}

regMedicamento obtenerDato(const char *dir, long pos)
{
    FILE *f = fopen(dir,"rb+");
	regMedicamento aux;
   	fseek(f,(long)(pos*sizeof(struct regMedicamento)), SEEK_SET);
    fread(&aux, sizeof(struct regMedicamento), 1, f);
    fclose(f);
    return aux;
}

void cargarBinarios()
{
    // Paso los archivos de texto a un vector

	cout << "Cargando datos_medicamentos.dat... ";
	vector<regMedicamento> medicamentos;
    medicamentos = pasarArchivo(datos_medicamentos);
    guardarArchivo(bin_medicamentos,medicamentos);
    cout << " CARGADO" << endl;

	cout << "Cargando altas_medicamentos.dat... ";
	vector<regMedicamento> medicamentos1;
    medicamentos1 = pasarArchivo(datos_altas);
    guardarArchivo(bin_altas,medicamentos1);
    cout << " CARGADO" << endl;

	cout << "Cargando bajas_medicamentos.dat... ";
	vector<regMedicamento> medicamentos2;
    medicamentos2 = pasarArchivo(datos_bajas);
    guardarArchivo(bin_bajas,medicamentos2);
	cout << " CARGADO" << endl;


}

void imprimirReg(regMedicamento r)
{
	cout << "______________________________________________" << endl;
	cout << r.nro_registro <<" Med: " << r.descripcion  << " Lab:" << r.laboratorio << endl;
	cout << " Acc:" << r.accion_medicamento << " Forma:" << r.forma_medicamento << " tam:" << r.tamanio_medicamento << " viaAd:" << r.via_administracion << " $" << r.precio << endl;
}

int main(int argc, char *argv[])
{
    int op = 0;

    Gridfile *g = new Gridfile();
    
    while (op !=9)
    {
		system("clear");
    	cout << "------->Menu<--------"<<endl;
        cout << "1 - Pasar archivos de texto a binario"<<endl;
        cout << endl;
        cout << "------>Cargar<-------"<<endl;
        cout << "2 - Cargar Gridfile a partir de archivo binario (unicen.gridfile)"<<endl;
        cout << endl;
        cout << "--->Actualizaciones<---"<<endl;
        cout << "3 - Alta de elementos a partir de un archivo binario (alta_medicamentos.dat)"<<endl;
        cout << "4 - Baja de elementos a partir de un archivo binario (baja_medicamentos.dat)"<<endl;
        cout << endl;
        cout << "----->Consultas<-----"<<endl;
        cout << "5 - Obtener un registro al azar"<<endl;
        cout << "6 - Acceder a medicamentos a partir de forma y/o accion y/o precios (rangos y valores exactos)"<<endl;
        cout << endl;
        cout << "9 - Salir"<<endl;
        cin >> op;
        switch (op)
        {
            case 1:
            {
                cout << "Carga de Binario"<<endl;
                cargarBinarios();
                cout << "Los archivos se pasaron a binario" <<endl;
                cout << "Presione una ENTER para terminar...";
				cin.get(); 
            }break;
            case 2:
            {
                FILE *f = fopen(bin_medicamentos,"ab+");
                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(regMedicamento);

                 // Levanta los elementos que apunta pos
                int i = 0;
                while(i<final)
                {
                	regMedicamento reg = obtenerDato(bin_medicamentos,i);
                	g->add(reg.accion_medicamento,reg.forma_medicamento,reg.precio,i);
                	i++;
                }
                cout << "La estructura fue construida con exito"<<endl;
                system("PAUSE");

            }break;

            case 3:
            {

                FILE *f = fopen(bin_medicamentos,"ab+");

                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(regMedicamento);

                FILE *f2 = fopen(bin_altas,"rb+");
                fseek(f2, 0L, SEEK_END);
                long int final2 = ftell(f2)/sizeof(regMedicamento);
                fclose(f2);

                int i = 0;
                while(i<final2)
                {
                	regMedicamento reg = obtenerDato(bin_altas,i);
                    cout << "Balde Antes"<<endl;
                	Balde *b = g->getOriginal(reg.accion_medicamento,reg.forma_medicamento,reg.precio);
                	b->imprimir();
                    g->add(reg.accion_medicamento,reg.forma_medicamento,reg.precio,final+i);
                    cout << "Balde Despues"<<endl;
                	b->imprimir();
                    system("pause");
                    fwrite(&reg, sizeof(regMedicamento), 1, f);
                	i++;
                }
                cout << "La carga culmino con exito"<<endl;
                fclose(f);
                system("Pause");
            }break;
            case 4:
            {
                cout << "Baja de elementos"<<endl;

                FILE *f = fopen(bin_altas,"rb+");
                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(regMedicamento);
                int i = 0;

                FILE *f2 = fopen(bin_medicamentos,"rb+");

                int x,y,z;
                while(i<final)
                {
                    regMedicamento reg = obtenerDato(bin_bajas,i);
                    x = g->getPosAccion(reg.accion_medicamento);
                    y = g->getPosForma(reg.forma_medicamento);
                    z = g->getPosPrecio(reg.precio);
                    int cont = 0;
                    Balde *b = g->get(x,y,z);
                    long posArch;
                    regMedicamento aux;
                    while(cont <b->size())
                    {
                        if (b->getAccion(cont) == reg.accion_medicamento && b->getForma(cont) == reg.forma_medicamento && b->getPrecio(cont)==reg.precio)
                        {
                            posArch = b->getReg(cont).valor;
                            aux = obtenerDato(bin_medicamentos,posArch);
                            aux.borrado = 1;
                           	fseek(f2,(long)(posArch*sizeof(struct regMedicamento)), SEEK_SET);
                   	        fwrite(&aux, sizeof(regMedicamento), 1, f2);
                        }
                        cont++;
                    }
                    i++;
                }

                const char *dir2 = "./datos_medicamentos2.gridfile";
                FILE *f3 = fopen(dir2,"wb+");
                regMedicamento rrr;

                //creo un archivo nuevo y paso todos los elementos exepto los que esten marcados con 1
                rewind(f2);
                while(!feof(f2)){
                    fread(&rrr, sizeof(struct regMedicamento), 1, f2);
                    if (rrr.borrado == 0)
                        fwrite(&rrr, sizeof(regMedicamento), 1, f3);
                }
                system("pause");

            }break;
            case 5:
			{
				int nroreg;
				cout << "Ingrese un numero de registro: ";
				cin >> nroreg;
				char opcion = 's';
				while (opcion == 's' || opcion == 'S')
                {
    				regMedicamento aux;
    				aux = obtenerDato(bin_medicamentos,nroreg);
    				imprimirReg(aux);
    				cout << endl;
    				cout << "Desea ver el siguiente valor? (s/n) ";
    				cin >> opcion;
                    nroreg++;
                }
				system("pause");

			}break;
            case 6:
            {
                short int a1,a2,f1,f2;
                float p1, p2;
                cout << "@  Consultas  @"<<endl;
                cout << " Nota: - para buscar por un velor exacto, ingrese el mismo valor en 'desde' y 'hasta'" << endl;
                cout << "       - Si no desea utilizar un criterio, ingrese desde=-1 y hasta=-1" << endl << endl;

                cout << "Accion: " << endl;
                cout << "desde: ";
                cin >> a1;
                cout << "hasta: ";
                cin >> a2;

                cout << "Forma: " << endl;
                cout << "desde: ";
                cin >> f1;
                cout << "hasta: ";
                cin >> f2;

                cout << "Precio: " << endl;
                cout << "desde: ";
                cin >> p1;
                cout << "hasta: ";
                cin >> p2;

                vector<int> resultado = g->consulta3rangos(a1,a2,f1,f2,p1,p2);
                regMedicamento aux;

				for (int i=0;i<resultado.size();i++)
                {
                	aux = obtenerDato(bin_medicamentos,resultado[i]);
                	imprimirReg(aux);
                }
                cout << endl <<resultado.size() << " registros retornados" << endl;
                system("pause");

            }break;
            case 7:
            {
				float p1,p2;
                cout << "@  Consulta de elementos SOLO por intervalo de precio @"<<endl;
                cout << "Ingrese rango precio: ";
               	cout << "Desde: ";
                cin >> p1;
                cout << "Hasta: ";
                cin >> p2;

                vector<int> resultado = g->consultaPrecio(p1,p2);
                regMedicamento aux;

                for (int i=0;i<resultado.size();i++)
                {
                	aux = obtenerDato(bin_medicamentos,resultado[i]);
                	imprimirReg(aux);
                }
                cout << endl << resultado.size() << " registros retornados" << endl;
                system("pause");

            }break;

            case 9:
            {
                cout << "chau!!"<<endl;
            }

            default:
            {
            } break;
        }
    }
    return EXIT_SUCCESS;
    
}
