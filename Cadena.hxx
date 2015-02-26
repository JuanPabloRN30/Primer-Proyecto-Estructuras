// constructor
Cadena::Cadena(string tipo1, string cadena1 )
{
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

void Cadena::setTipo(string tipo1)
{
    tipo = tipo1;
}

void Cadena::setCadena(string cadena1)
{
    cadena = cadena1;
}

vector< char > ingresarBases()
{
    vector< char > bases;
    bases.push_back('A');
    bases.push_back('C');
    bases.push_back('G');
    bases.push_back('T');
    bases.push_back('U');
    bases.push_back('R');
    bases.push_back('Y');
    bases.push_back('K');
    bases.push_back('M');
    bases.push_back('S');
    bases.push_back('W');
    bases.push_back('B');
    bases.push_back('D');
    bases.push_back('H');
    bases.push_back('V');
    bases.push_back('N');
    bases.push_back('X');
    return bases;
}

int buscarBasePos(char letra)
{
    vector < char > bases = ingresarBases();
    for(int i = 0 ; i < bases.size() ; i++)
    {
        if(bases[i] == letra)
            return i;
    }
    return -1;
}

vector < int > Cadena::contarBases()
{
    vector < int > totales(17,0);
    int cont = 0;
    for(int i = 0 ; i < cadena.size() ; i++)
    {
        int pos = buscarBasePos(cadena[i]);
        if(pos != -1)
            totales[pos]++;
    }
    return totales;
}

int Cadena::subCadenas(string subcadena, bool bandera1)
{
    int cont = 0;
    int j,k;
    for(int i = 0 ; i < cadena.size() ; i++)
    {
        bool bandera = false;
        if(cadena[i] == subcadena[0])
        {
            bandera = true;
            int j,k;
            j = i; k = 0;
            int pos = 0;
            while(pos < subcadena.size())
            {
                if(cadena[j] == '\n')
                    j++;
                if(cadena[j] != subcadena[k])
                    bandera = false;
                if(j >= cadena.size())
                    break;
                if(k >= subcadena.size())
                    break;
                j++; k++;
                pos++;
            }
        }
        if(bandera)
        {
            if(!bandera1)
            {
                int pos = i, j = 0;
                while(j < subcadena.size())
                {
                    if(cadena[pos] == '\n')
                    {
                        pos++;
                    }
                    cadena[pos++] = 'X';
                    j++;
                }
            }
            cont++;
        }
    }
    return cont;
}
