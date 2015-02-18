#include "Cadena.h"
#include <set>

// constructor
Cadena::Cadena(string tipo1, string cadena1 ){
    tipo = tipo1;
    cadena = cadena1;
}

string Cadena::getTipo()
{
    return tipo;
}

string Cadena::getCadena()
{
    return cadena;
}

set<char> ingresarBases()
{
    set<char> bases;
    bases.insert('A');
    bases.insert('C');
    bases.insert('G');
    bases.insert('T');
    bases.insert('U');
    bases.insert('R');
    bases.insert('Y');
    bases.insert('K');
    bases.insert('M');
    bases.insert('S');
    bases.insert('W');
    bases.insert('B');
    bases.insert('D');
    bases.insert('H');
    bases.insert('V');
    bases.insert('N');

    return bases;
}

int Cadena::contarBases()
{
    set < char > bases = ingresarBases();
    int cont = 0;
    for(int i = 0 ; i < cadena.size() ; i++)
    {
        if(bases.find(cadena[i]) != bases.end())
            cont++;
    }
    return cont;
}
