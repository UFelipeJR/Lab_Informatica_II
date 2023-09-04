#include <iostream>
#include "funcionalidades.h"
#include <cstdlib>
#include <ctime>

using namespace std;

char* genDinamicCharArray(const int size){

    /*
     * Generador de arreglo dinamico char
     *
     * Variables, constantes y arreglos.
     * size: tamaño máximo definido como constante para el arreglo.
     * arrayC: arreglo dinamico.
     *
     * Retorno:
     * array de caracteres.
    */

    char* arrayC = new char[size];
    cout << "Ingrese una cadena de caracteres:";
    //cin >> arrayC; // Por definir
    cin.getline(arrayC,size); // Por definir
    return arrayC;
}


char* genDinamicRandomAlphabet(const int size){

    /*
     * Generador de arreglo dinamico con n letras aleatorias
     *
     * Variables, constantes y arreglos.
     * size: tamaño máximo definido como constante para el arreglo.
     * arrayC: arreglo dinamico.
     * indiceRandom: numero aleatorio entre 0 y 26 que corresponde a la cantidad de letras del alfabeto.
     * letraRandom: letra alatoria generada con indiceRandom;
     *
     * Retorno:
     * array dinamico de n letras mayusculas.
    */

    char* arrayRandom = new char[size];
    char* punteroPrimario = arrayRandom;
    int indiceRandom;
    char letraRandom;

    for(int i = 0; i < size; i++){
        indiceRandom = rand() % 26;
        letraRandom = 'A' + indiceRandom;
        *punteroPrimario = letraRandom;
        punteroPrimario++;
    }

    return arrayRandom;
}


char upperChar(char caracter){

    /*
     * Conversor de caracter a mayúscula
     *
     * Variables, constantes y arreglos.
     * caracter: caracter que será convertido a mayuscula.
     *
     * Retorno:
     * caracter convertido en mayuscula.
    */

    if(caracter >= 'a' && caracter <= 'z'){
        return caracter - 32;
    }
    else{
        return caracter;
    }

}

bool checkRoman(char* array) {

    /*
     * Checker de posibles romanos
     *
     * Variables, constantes y arreglos.
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     * denominaciones: arreglo de caracteres que almacena las letras usadas para denominar los numeros romanos.
     *
     * Retorno:
     * true o false dependiendo de si es o no un posible romano
    */

    char* punteroIterador = array;
    char denominaciones[] = "MDCLXVI";

    while (*punteroIterador != '\0') {
        bool esValido = false;
        for (int i = 0; i < 7; i++) {
            if (*punteroIterador == denominaciones[i]) {
                esValido = true;
                break;
            }
        }
        if (!esValido) {
            return false;
        }
        punteroIterador++;
    }
    return true;
}

int equivRoman(char caracter){

    /*
     * Buscador de equivalencia de letra con numero romano
     *
     * Variables, constantes y arreglos.
     * romanos: arreglo de caracteres que almacena las letras usadas para denominar los numeros romanos.
     * valores: arreglo con los valores que pueden tomar los numeros romanos.
     *
     * Retorno:
     * true o false dependiendo de si es o no un posible romano
    */

    char romanos[] = "MDCLXVI";
    int valores[] = {1000,500,100,50,10,5,1};

    for(int i = 0; romanos[i] != '\0'; i++){
        if(caracter == romanos[i]){
            return valores[i];
        }
    }

    return -1;
}



//SIN DOCUMENTAR

int** genDinamicMatriz(int filas, int columnas) {

    /*
     * Generador de matriz dinamica vacia mxn
     *
     * Variables, constantes y arreglos.
     * matriz: doble puntero indicador del espacio en memoria donde estará almacenada la matriz.
     * filas: numero de filas de la matriz.
     * columnas: numero de columnas de la matriz.
     *
     * Retorno:
     * vacio.
    */

    int** matriz = new int*[filas];

    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }

    return matriz;
}

void cleanMemoryMatrizmxn(int filas, int **matriz){

    /*
     * Liberador de memoria matriz dinamica
     *
     * Variables, constantes y arreglos.
     * matriz: doble puntero indicador del espacio en memoria donde estará almacenada la matriz.
     * filas: numero de filas de la matriz.
     *
     * Retorno:
     * vacio.
    */

    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void fillMatriz(int** matriz, int filas, int columnas){

    /*
     * Rellenador de matriz
     *
     * Variables, constantes y arreglos.
     * matriz: matriz o doble puntero donde está almacenada.
     * filas: numero de filas de la matriz.
     * columnas: numero de columnas de la matriz.
     *
     * Retorno:
     * vacio.
    */

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Ingrese el valor para la posicion [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> *(*(matriz + i) + j);
        }
    }

}

void printMatriz(int** matriz, int filas, int columnas){

    /*
     * Impresor de matriz mxn
     *
     * Variables, constantes y arreglos.
     * matriz: matriz o doble puntero donde está almacenada.
     * filas: numero de filas de la matriz.
     * columnas: numero de columnas de la matriz.
     *
     * Retorno:
     * vacio.
    */

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
}
}

void rotatedMatriz(int** matriz,int filas,int columnas, int angulo){

    /*
     * Rotador de matriz nxn
     *
     * Variables, constantes y arreglos.
     * matriz: matriz o doble puntero donde está almacenada.
     * filas: numero de filas de la matriz.
     * columnas: numero de columnas de la matriz.
     * angulo: angulo en el que se quiere rotar la materia, puede ser 0,90,180 y 270.
     *
     * Retorno:
     * vacio.
    */

    switch (angulo) {
        case 0:
            printMatriz(matriz,filas,columnas);
            break;
        case 90:
            for (int j = 0; j < columnas; j++) {
                for (int i = filas - 1; i >= 0; i--) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 180:
            for(int i = filas-1; i>=0; i--){
                for(int j = columnas-1; j>=0;j--){
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }
            break;
        case 270:
            for (int j = columnas - 1; j >= 0; j--) {
                for (int i = 0; i < filas; i++) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }

            break;

    }

}

int factorial(int numero){

    /*
     * Calculo de factorial
     *
     * Variables, constantes y arreglos.
     * numero: numero al que se le calculará el factorial
     *
     * Retorno:
     * vacio.
    */

    //Caso base
    if(numero == 0){
        return 1;
    }

    //La función se llama así misma hasta que llega al caso base
    else{
        return numero*factorial(numero-1);
    }

}