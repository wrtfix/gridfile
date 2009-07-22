
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gridfile.h"

using namespace std;

//archivos


const char *datos = "./ventas.txt";
/*const char *datos_altas = "./altas_medicamentos.dat";
const char *datos_bajas = "./bajas_medicamentos.dat";
*/
const char *binario = "./datos.gridfile";
/*const char *bin_altas = "./altas_medicamentos.gridfile";
const char *bin_bajas = "./bajas_medicamentos.gridfile";*/

struct reg
{
        int borrado;
        int id_productor;
        char nombre[120];
        char mail[150];
        char pais[61];
        int anio;
        int mes;
        char producto[20];
        int cantidad_entregar;
        char calidad[10];
};

//esta funcion debuelbe toda la info de un archivo de texto en un vector de tipo regMedicamento
vector<reg> pasarArchivo(const char *dir)
{
    // creo un flujo de datos con una nombre (dir)
    ifstream f(dir);
    if (!f)
        cout << "fallo/n";

        // Declaramos un array con suficiente tamaño para leer las líneas del archivo
    char cadena[500];

        //variable auxiliar para ir cargando los dato que seran guardado en un vector
        reg pro;

        //vector que retornare una vez cargados los datos
        vector<reg> ventas;

        while (!f.eof())
        {
                f.getline(cadena,sizeof(cadena));
                char sd[256] = "";
                for (int i = 0; i<256;i++)
                        sd[i] = cadena[i];

                //arreglo con los elementos que divide la informacion en este caso ;
                char seps[] = ";";

                //elementos en donde guardo la informacion mientras la voy dividiendo
                char *token0;
                char *token1;
                char *token2;
                char *token3;
                char *token4;
                char *token5;
                char *token6;
                char *token7;
                char *token8;

                //divido el reglo por hasta llegar a un null y guardo en el registro
                token0 = strtok( sd, seps );
                if (token0 !=NULL){
                        pro.id_productor = atoi(token0);

                        token1 = strtok( NULL, seps );
                        strcpy(pro.nombre,token1);

                        token2 = strtok( NULL, seps );
                        strcpy(pro.mail,token2);

                        token3 = strtok( NULL, seps );
                        strcpy(pro.pais,token3);

                        token4 = strtok( NULL, seps );
                        pro.anio = atoi(token4);

                        token5 = strtok( NULL, seps );
                        pro.mes = atoi(token5);

                        token6 = strtok( NULL, seps );
                        strcpy(pro.producto,token8);

                        token7 = strtok( NULL, seps);
                        pro.cantidad_entregar = atoi(token7);

                        token8 = strtok( NULL, seps);
                        strcpy(pro.calidad,token8);

                        pro.borrado = 0;
                        //agrego el registro pro en el vector medicamentos
                        ventas.push_back(pro);
                }
        }
    f.close();
        return ventas;
}

void guardarArchivo(const char *pos,vector<reg> &ventas)
{

    FILE *f = fopen(pos,"wb+");
    rewind(f);
        for(int i=0;i<ventas.size();i++)
        fwrite(&ventas[i], sizeof(reg), 1, f);

    fclose(f);

}

reg obtenerDato(const char *dir, long pos)
{
    FILE *f = fopen(dir,"rb+");
        reg aux;
        fseek(f,(long)(pos*sizeof(struct reg)), SEEK_SET);
    fread(&aux, sizeof(struct reg), 1, f);
    fclose(f);
    return aux;
}

void cargarBinarios()
{
    // Paso los archivos de texto a un vector

        cout << "Cargando datos_medicamentos.dat... ";
        vector<reg> ventas;
        ventas = pasarArchivo(datos);
        guardarArchivo(binario,ventas);
        cout << " CARGADO" << endl;

        /*cout << "Cargando altas_medicamentos.dat... ";
        vector<regMedicamento> medicamentos1;
    medicamentos1 = pasarArchivo(datos_altas);
    guardarArchivo(bin_altas,medicamentos1);
    cout << " CARGADO" << endl;

        cout << "Cargando bajas_medicamentos.dat... ";
        vector<regMedicamento> medicamentos2;
    medicamentos2 = pasarArchivo(datos_bajas);
    guardarArchivo(bin_bajas,medicamentos2);
        cout << " CARGADO" << endl;*/


}

void imprimirReg(reg r)
{
        cout << "______________________________________________" << endl;
        cout << r.id_productor <<" Producto " << r.producto << " Pais:" << r.pais<< endl;
        cout << " Calidad:" << r.calidad << " Anio:" << r.anio << " Mes:" << r.mes<< " Cantidad:" << r.cantidad_entregar<<endl;
}

int main()
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
        cout << "5 - Mostrar estructura"<<endl;
        cout << "6 - Obtener un registro al azar"<<endl;
        cout << "7 - Acceder a medicamentos a partir de forma y/o accion y/o precios (rangos y valores exactos)"<<endl;

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
                  //              cin.get();
            }break;
            case 2:
            {   FILE *f = fopen(binario,"ab+");
                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(reg);

                g->addFecha(6,1994);
                g->addFecha(12,2008);
                g->addCantidad(55240);
                g->addCantidad(99519);

                 // Levanta los elementos que apunta pos
                int i = 0;
                while(i<final)
                {
                        reg registro = obtenerDato(binario,i);
                        imprimirReg(registro);
                        g->addxCantidad(registro.id_productor,i,registro.mes,registro.anio,registro.cantidad_entregar);
                        i++;
                }
                cout << "La estructura fue construida con exito"<<endl;
                system("PAUSE");

            }break;
/*
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

            }break;*/
            case 5:
            {
                g->todos();
            }break;
            case 6:
            {
                int nroreg;
                cout << "Ingrese un numero de registro: ";
                cin >> nroreg;
                char opcion = 's';
                while (opcion == 's' || opcion == 'S')
                {
                    reg aux;
                    aux = obtenerDato(binario,nroreg);
                    imprimirReg(aux);
                    cout << endl;
                    cout << "Desea ver el siguiente valor? (s/n) ";
                    cin >> opcion;
                    nroreg++;
                }
                system("pause");

            }break;
            case 7:
            {
                int c1,c2,m1,m2,a1, a2;

                cout << "@  Consultas  @"<<endl;
                cout << " Nota: - para buscar por un velor exacto, ingrese el mismo valor en 'desde' y 'hasta'" << endl;
                cout << "       - Si no desea utilizar un criterio, ingrese desde=-1 y hasta=-1" << endl << endl;

                cout << "Cantidad: " << endl;
                cout << "desde: ";
                cin >> c1;
                cout << "hasta: ";
                cin >> c2;

                cout << "Mes: " << endl;
                cout << "desde: ";
                cin >> m1;
                cout << "hasta: ";
                cin >> m2;

                cout << "Anio: " << endl;
                cout << "desde: ";
                cin >> a1;
                cout << "hasta: ";
                cin >> a2;

                vector<int> * resultado = g->consultar(a1,a2,m1,m2,c1,c2);

                reg aux;

                for (int i=0;i<resultado->size();i++)
                {
                        aux = obtenerDato(binario,(*resultado)[i]);
                        imprimirReg(aux);
                }

                cout << endl <<resultado->size() << " registros retornados" << endl;

                system("pause");

            }break;
            case 8:
            {
                int c1,c2;
                cout << "@  Consulta de elementos SOLO por intervalo de cantidad @"<<endl;
                cout << "Ingrese rango cantidad: ";
                cout << "Desde: ";
                cin >> c1;
                cout << "Hasta: ";
                cin >> c2;

                //vector<int> resultado = g->consultaCantidad(c1,c2);
                reg aux;


/*                for (int i=0;i<resultado.size();i++)
                {
                        aux = obtenerDato(binario,resultado[i]);
                        imprimirReg(aux);
                }
                cout << endl << resultado.size() << " registros retornados" << endl;
                system("pause");
*/
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

    return 0;
}
