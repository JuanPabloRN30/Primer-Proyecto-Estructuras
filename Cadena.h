#ifndef __CADENA__H__
#define __CADENA__H__

using namespace std;

class Cadena {
  public:
    Cadena(string tipo1, string cadena1);
    string getTipo();
    string getCadena();
    int contarBases();
  protected:
    string tipo;
    string cadena;
};

#include "Cadena.hxx"

#endif //
