#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include "CodigoGenetico.h"
#include "Menu.h"
using namespace std;

void cargar(CodigoGenetico &codigo,string nombreArchivo)
{
    int diferencia = codigo.contarSecuencias();
    if(codigo.cargarDatos(nombreArchivo))
    {
        diferencia = codigo.contarSecuencias() - diferencia;
        if(diferencia == 0)
            cout << nombreArchivo << " no contiene ninguna secuencia" << endl;
        else if(diferencia == 1)
            cout << 1 << " secuencia cargada cargada de: " << nombreArchivo << endl;
        else
            cout << diferencia << " secuencia cargada cargada de: " << nombreArchivo << endl;
    }
    else
        cout << "ERROR CON EL ARCHIVO " << endl;
}

void contar(CodigoGenetico &codigo)
{
    int cantSecuencias = codigo.contarSecuencias();
    if(cantSecuencias == 0)
        cout << "No hay secuencias cargadas" << endl;
    else if(cantSecuencias == 1)
        cout << "1 secuencia cargada" << endl;
    else
        cout << cantSecuencias << " secuencias cargadas" << endl;
}

void listaSecuencias(CodigoGenetico &codigo)
{
    int cantSecuencias = codigo.contarSecuencias();
    if(cantSecuencias == 0)
        cout << "No hay secuencias cargadas" << endl;
    else
    {
        codigo.listaSecuencias();
    }
}

void subSecuencia(CodigoGenetico &codigo, string secuencia)
{
    int cantSecuencias = codigo.contarSecuencias();
    if(cantSecuencias == 0)
    {
        cout << "No hay secuencias cargadas" << endl;
    }
    else
    {
        int cantidad = codigo.subCadenas(secuencia,1);
        if(cantidad == 0)
            cout << "No existe esa subsecuencia" << endl;
        else
            cout << "La secuencia dada se repite: " << cantidad << " de veces." << endl;

    }
}

void mascara(CodigoGenetico &codigo, string secuencia )
{
    int cantSecuencias = codigo.contarSecuencias();
    if(cantSecuencias == 0)
        cout << "No hay secuencias cargadas" << endl;
    else
    {
        int cantidad = codigo.subCadenas(secuencia,0);
        if(cantidad == 0)
            cout << "No se enmascararon secuencias" << endl;
        else if(cantidad == 1)
            cout << "1 Secuencia se enmascaro" << endl;
        else
            cout << cantidad <<" Secuencias se enmascararon" << endl;
    }
}

void guardar(CodigoGenetico codigo, string nombreArchivo)
{
    int cantSecuencias = codigo.contarSecuencias();
    if(cantSecuencias == 0)
    {
        cout << "No hay secuencias cargadas" << endl;
    }
    else
    {
        if(codigo.guardarDatos(nombreArchivo))
            cout << "Las secuencias se guardaron correctamente en: " << nombreArchivo << endl;
        else
            cout << "Error escribiendo el archivo: " << nombreArchivo << endl;
    }
}

int main()
{
    CodigoGenetico codigo;
    string linea;
    int cantSecuencias;
    do
    {
        cout << "$ ";
        getline(cin,linea);
        stringstream ss(linea);
        string opc;
        ss >> opc;
        if(opc == "help")
        {
            string opc2;
            ss >> opc2;
            if(opc2 == "load")
                load();
            else if(opc2 == "count")
                countM();
            else if(opc2 == "list_sequences")
                list_sequences();
            else if(opc2 == "histogram")
                histogram();
            else if(opc2 == "is_subsequence")
                is_subsequence();
            else if(opc2 == "mask")
                mask();
            else if(opc2 == "save")
                save();

        }
        else
        {
            if(opc == "load")
            {
                string nombreArchivo;
                ss >> nombreArchivo;
                cargar(codigo,nombreArchivo);
            }
            else if(opc == "count")
            {
                contar(codigo);
            }
            else if(opc == "list_sequences")
            {
                listaSecuencias(codigo);
            }
            else if(opc == "histogram")
            {
                string secuenciaDescripcion;
                ss >> secuenciaDescripcion;
                codigo.mostrarHistograma(secuenciaDescripcion);
            }
            else if(opc == "is_subsequence")
            {
                string secuencia;
                ss >> secuencia;
                subSecuencia(codigo,secuencia);
            }
            else if(opc == "mask")
            {
                string secuencia;
                ss >> secuencia;
                mascara(codigo,secuencia);
            }
            else if(opc == "save")
            {
                string nombreArchivo;
                ss >> nombreArchivo;
                guardar(codigo,nombreArchivo);
            }
        }
    }
    while(linea != "exit");
    return 0;
}
