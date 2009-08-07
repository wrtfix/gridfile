#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gridfile.h"

using namespace std;

//archivos


const char *datos = "./datos_b.txt";
const char *datos_altas = "./altas_b.txt";
const char *datos_bajas = "./bajas_b.txt";

const char *binario = "./datos.gridfile";
const char *bin_altas = "./altas.gridfile";
const char *bin_bajas = "./bajas.gridfile";

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

        cout << "Cargando ventas.txt.";
        vector<reg> ventas;
        ventas = pasarArchivo(datos);
        cout << ".";
        guardarArchivo(binario,ventas);
        cout << ".";
        cout << " CARGADO" << endl;

        cout << "Cargando altas.txt.";
        vector<reg> altas;
        altas = pasarArchivo(datos_altas);
        cout << ".";
        guardarArchivo(bin_altas,altas);
        cout << ".";
        cout << " CARGADO" << endl;

        cout << "Cargando bajas.txt.";
        vector<reg> bajas;
        bajas = pasarArchivo(datos_bajas);
        cout << ".";
        guardarArchivo(bin_bajas,bajas);
        cout << ".";
        cout << " CARGADO" << endl;


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
        system("cls");
        cout << "------->Menu<--------"<<endl;
        cout << "1 - Pasar archivos de texto a binario"<<endl;
        cout << endl;
        cout << "------>Cargar<-------"<<endl;
        cout << "2 - Cargar Gridfile a partir de archivo binario (unicen.gridfile)"<<endl;
        cout << endl;
        cout << "--->Actualizaciones<---"<<endl;
        cout << "3 - Alta de elementos a partir de un archivo binario (altas.txt)"<<endl;
        cout << "4 - Baja de elementos a partir de un archivo binario (bajas.txt)"<<endl;
        cout << endl;
        cout << "----->Consultas<-----"<<endl;
        cout << "5 - Descripcion"<<endl;
        cout << "6 - Obtener un registro al azar"<<endl;
        cout << "7 - Acceder a ventas a partir de fecha y/o cantidad"<<endl;

        cout << endl;
        cout << "9 - Salir"<<endl<<endl;
        cout << "Opcion desada: ";
        cin >> op;
        switch (op)
        {
            case 1:
            {
                cout << "Carga de Binario"<<endl;
                cargarBinarios();
                cout << "Los archivos se pasaron a binario" <<endl;
                system("pause");
            }break;
            case 2:
            {   FILE *f = fopen(binario,"ab+");
                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(reg);

                //escala definida a ojo
                g->addFecha(6,2000);
                g->addFecha(12,2010);
                g->addCantidad(50);
                g->addCantidad(99);

                 // Levanta los elementos que apunta pos
                int i = 0;
                while(i<final)
                {
                        reg registro = obtenerDato(binario,i);
                        imprimirReg(registro);
                        g->addxCantidad(registro.id_productor,i,registro.mes,registro.anio,registro.cantidad_entregar);
                        i++;
                }
                cout<<"Se insertaron "<<i<<" en total"<<endl;
                cout << "La estructura fue construida con exito"<<endl;
                system("PAUSE");

            }break;
            case 3:
            {
                cout<<"Altas de elmentos"<<endl;;
                FILE *f = fopen(binario,"ab+");

                fseek(f, 0L, SEEK_END);
                long int final = ftell(f)/sizeof(reg);

                FILE *f2 = fopen(bin_altas,"rb+");
                fseek(f2, 0L, SEEK_END);
                long int final2 = ftell(f2)/sizeof(reg);
                fclose(f2);

                int i = 0;
                while(i<final2)
                {
                        reg registro = obtenerDato(bin_altas,i);
                        imprimirReg(registro);
                        g->addxCantidad(registro.id_productor,final+i,registro.mes,registro.anio,registro.cantidad_entregar);
                        fwrite(&registro, sizeof(reg), 1, f);
                        i++;
                }
                cout << "La carga culmino con exito"<<endl;
                cout<<"Se insertaron "<<i<<" en total"<<endl;
                fclose(f);
                system("Pause");
            }break;
            case 4:
            {
                cout << "Baja de elementos"<<endl;

                FILE *f = fopen(bin_bajas,"rb+");
                fseek(f, 0L, SEEK_END);

                long int final = ftell(f)/sizeof(reg);

                int i = 0;

                FILE *f2 = fopen(binario,"rb+");

                int x,y;
                while(i<final)
                {
                    reg registro = obtenerDato(bin_bajas,i);
                    x = g->getposFecha(registro.mes,registro.anio);
                    y = g->getposCantidad(registro.cantidad_entregar);
                    int cont = 0;
                    Balde *b = g->getZona(x,y)->getBalde();
                    long posArch;
                    reg aux;
                    while(cont < b->getMaximo())
                    {
                        if (b->getBorrado(cont) != 1 &&b->getAnio(cont) == registro.anio && b->getMes(cont) == registro.mes && b->getCantidad(cont)==registro.cantidad_entregar)
                        {
                            posArch = b->getPos(cont);
                            aux = obtenerDato(binario,posArch);
                            aux.borrado = 1;
                            b->setBorrado(cont);
                            fseek(f2,(long)(posArch*sizeof(struct reg)), SEEK_SET);
                            fwrite(&aux, sizeof(reg), 1, f2);
                        }
                        cont++;
                    }
                    i++;
                }

                const char *dir2 = "./sin_borrados.gridfile";
                FILE *f3 = fopen(dir2,"wb+");
                reg rrr;

                //creo un archivo nuevo y paso todos los elementos exepto los que esten marcados con 1
                rewind(f2);
                while(!feof(f2)){
                    fread(&rrr, sizeof(struct reg), 1, f2);
                    if (rrr.borrado == 0)
                        fwrite(&rrr, sizeof(reg), 1, f3);
                }
                g->actualizar();
                system("pause");

            }break;
            case 5:
            {
                g->todos();
                system("pause");
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

                cout << "Fecha de inicio: " << endl;
                cout << "mes: ";
                cin >> m1;
                cout << "anio: ";
                cin >> a1;

                cout << "Fecha de fin: " << endl;
                cout << "mes: ";
                cin >> m2;
                cout << "anio: ";
                cin >> a2;

                vector<int> * resultado = g->consultar(a1,a2,m1,m2,c1,c2);

                reg aux;

                for (int i=0;i<resultado->size();i++)
                {
                        aux = obtenerDato(binario,(*resultado)[i]);
                        imprimirReg(aux);
                }

                cout << endl <<resultado->size() << " registros retornados" << endl;

                for (int i=0;i<resultado->size();i++)
                {   resultado->pop_back();
                }



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

    return 0;
}
