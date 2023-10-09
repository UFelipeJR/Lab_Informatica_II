#ifndef GESTORTXT_H
#define GESTORTXT_H


#include <iostream>|
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

class gestorTxt
{

private:

public:
    gestorArchivos();
    unsigned long long int obtenerLongitud(string ruta);
    unsigned long long int obtenerLongitud(const vector<unsigned char> &miVector);
    vector<unsigned char> leerArchivo(string rutaArchivo);
    vector<string>split(const string& entrada, char delimitador);
    string vector_String(vector<unsigned char>&miVector);
    friend ostream& operator<<(ostream& os, const gestorTxt& gestor);
};


ostream& operator<<(ostream& os, const gestorTxt& gestor);

#endif // GESTORTXT_H