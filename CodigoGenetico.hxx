// constructor
CodigoGenetico::CodigoGenetico()
{
}

vector < Cadena > CodigoGenetico::getListaCadenas()
{
    return listaCadenas;
}

bool CodigoGenetico::cargarDatos(string nombreArchivo)
{
    ifstream entrada;
    bool bandera = false;

    nombreArchivo+= ".fa";
    entrada.open(nombreArchivo.c_str(),ios::in);
    if(!entrada)
        return false;
    string tipo;
    getline(entrada,tipo);

    while(!entrada.eof() && !bandera)
    {
        string cadena,cadTot;
        cadena = cadTot = "";
        while(cadena[0] != '>' && !bandera)
        {
            cadTot+= cadena;
            getline(entrada,cadena);
            cadena+='\n';
            if(entrada.eof())
                bandera = true;

        }

        stringstream ss(tipo);
        char caracter;
        ss >> caracter >> tipo;
        Cadena cad(tipo,cadTot);
        listaCadenas.push_back(cad);
        tipo = cadena;
        tipo = tipo + '\n';
    }
    entrada.close();
    return true;
}

int CodigoGenetico::contarSecuencias()
{
    return listaCadenas.size();
}

void CodigoGenetico::listaSecuencias()
{
    for(int i = 0 ; i < contarSecuencias() ; i++)
    {
        string tipo = listaCadenas[i].getTipo() ;
        vector < int > bases = listaCadenas[i].contarBases();
        int cantidad = 0;
        for(int i = 0 ; i < bases.size() ; i++)
            cantidad += bases[i];


        cout << "Secuencia: " << tipo ;
        if(listaCadenas[i].getCadena().find('-') == string::npos)
            cout << " tiene " << cantidad << " bases" << endl;
        else
            cout << " tiene al menos " << cantidad << " bases" << endl;

    }
}

Cadena* CodigoGenetico::buscarCadena(string descripcion)
{
    Cadena* cad = NULL;
    for(int i = 0 ; i < contarSecuencias() ; i++)
    {
        if(listaCadenas[i].getTipo() == descripcion)
        {
            cad = new Cadena(listaCadenas[i].getTipo(),listaCadenas[i].getCadena());
        }
    }
    return cad;

}

bool CodigoGenetico::guardarDatos(string nombreArchivo)
{
    ofstream salida;
    nombreArchivo+= ".fa";
    salida.open(nombreArchivo.c_str(),ios::out);
    for(int i = 0 ; i < listaCadenas.size() ; i++)
    {
        salida << ">" << listaCadenas[i].getTipo().c_str() << endl;
        salida << listaCadenas[i].getCadena().c_str();
    }
    if(salida.fail())
        return false;
    else
        return true;
}

void CodigoGenetico::mostrarHistograma(string descripcion)
{
    Cadena* cadena = buscarCadena(descripcion);
    if(cadena == NULL)
        cout << "Secuencia invalida" << endl;
    else
    {
        vector < int > total = cadena->contarBases();
        vector < char > bases = ingresarBases();
        for(int i = 0 ; i < total.size() ; i++)
        {
            printf("%5c : %5d\n",bases[i],total[i]);
        }

    }
}

int CodigoGenetico::subCadenas(string subCadena, bool bandera)
{
    int cant = 0;
    for(int i = 0 ; i < listaCadenas.size() ; i++)
        cant += listaCadenas[i].subCadenas(subCadena, bandera);

    return cant;
}
