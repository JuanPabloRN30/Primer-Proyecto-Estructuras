#ifndef __CODIGOGENETICO__H__
#define __CODIGOGENETICO__H__

#include <vector>
#include "Cadena.h"
using namespace std;

class CodigoGenetico {
  public:
    CodigoGenetico();
    vector < Cadena > getListaCadenas();
    int contarSecuencias();
    bool cargarDatos(string nombreArchivo);
    void listaSecuencias();
    Cadena* buscarCadena(string descripcion);
    void mostrarBases(string cadena);
    void mostrarHistograma(string descripcion);
    bool guardarDatos(string nombreArchivo);
    int subCadenas(string subCadena, bool bandera);

  protected:
    vector < Cadena > listaCadenas;
};

#include "CodigoGenetico.hxx"

#endif //
