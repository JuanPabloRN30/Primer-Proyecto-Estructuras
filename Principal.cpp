#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include "Cadena.h"
using namespace std;

vector < Cadena > cargarDatos(string nombreArchivo)
{
    vector < Cadena > arregloCadenas;
    ifstream entrada;
    bool bandera = false;

    nombreArchivo+= ".fa";
    entrada.open(nombreArchivo.c_str(),ios::in);
    string tipo;
    entrada >> tipo;
    while(!entrada.eof() && !bandera)
    {
        string cadena,cadTot;
        cadena = cadTot = "";
        while(cadena[0] != '>' && !bandera)
        {
            cadTot+= cadena;
            getline(entrada,cadena);
            if(entrada.eof())
                bandera = true;

        }
        stringstream ss(tipo);
        char caracter;
        ss >> caracter >> tipo;
        Cadena cad(tipo,cadTot);
        arregloCadenas.push_back(cad);
        tipo = cadena;
    }
    return arregloCadenas;
}

int contarSecuencias(vector < Cadena > arregloCadenas)
{
    return arregloCadenas.size();
}

int main()
{
    vector < Cadena > arregloCadenas;
    string linea;
    int cantSecuencias;
    do
    {
        cout << "$ ";
        getline(cin,linea);
        stringstream ss(linea);
        string opc;
        ss >> opc;

        if(opc == "load")
        {
            //PREGUNTAR SI PUEDEN ENTRAR MAS SECUENCIAS, CAMBIARIA UNAS COSITAS.
            string nombreArchivo;
            ss >> nombreArchivo;
            arregloCadenas = cargarDatos(nombreArchivo);
            if(arregloCadenas.size() == 0)
                cout << nombreArchivo << " no contiene ninguna secuencia" << endl;
            else if(arregloCadenas.size() == 1)
                cout << 1 << " secuencia cargada cargada de: " << nombreArchivo << endl;
            else
                cout << arregloCadenas.size() << " secuencia cargada cargada de: " << nombreArchivo << endl;
        }
        else if(opc == "count")
        {
            int cantSecuencias = contarSecuencias(arregloCadenas);
            if(cantSecuencias == 0)
                cout << "No hay secuencias cargadas" << endl;
            else if(cantSecuencias == 1)
                cout << "1 secuencia cargada" << endl;
            else
                cout << cantSecuencias << " secuencias cargadas" << endl;

        }
        else if(opc == "list_sequences")
        {
            int cantSecuencias = contarSecuencias(arregloCadenas);
            if(cantSecuencias == 0)
                cout << "No hay secuencias cargadas" << endl;
            else
            {
                for(int i = 0 ; i < arregloCadenas.size() ; i++)
                {
                    string tipo = arregloCadenas[i].getTipo() ;
                    int cantidad = arregloCadenas[i].contarBases();
                    cout << "Secuencia: " << tipo ;
                    if(tipo == "Incomplete_sequence")
                        cout << " tiene al menos " << cantidad << " bases" << endl;
                    else
                        cout << " tiene " << cantidad << " bases" << endl;
                }
            }
        }
        else if(opc == "histogram")
        {
            string secuenciaDescripcion;
            ss >> secuenciaDescripcion;
            // SE CUENTAN LAS QUE NO SON BASES
            // QUE ES COMO TAL DESCRIPCION DE LA SECUENCIA, SI HAY 2 O MAS QUE PASA.
        }
        else if(opc == "is_subsequence")
        {
            string secuencia;
            ss >> secuencia;
            cantSecuencias = contarSecuencias(arregloCadenas);
            if(cantSecuencias == 0)
            {
                cout << "No hay secuencias cargadas" << endl;
            }
            else
            {
                cout << "Ingrese linea: ";
                string line;
                cin >> line;
                cout << "Ingrese la sub:";
                string sub;
                cin >> sub;
            }
        }
        else if(opc == "mask")
        {
            string secuencia;
            ss >> secuencia;
        }
        else if(opc == "save")
        {
            string nombreArchivo;
            ss >> nombreArchivo;
            cantSecuencias = contarSecuencias(arregloCadenas);
            if(cantSecuencias == 0)
            {
                cout << "No hay secuencias cargadas" << endl;
            }
            else
            {

            }

        }
    }
    while(linea != "exit");

    return 0;
}


