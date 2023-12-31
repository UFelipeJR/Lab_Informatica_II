#include "funcionalidades.h"
#include "problemas.h"


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


int lenChar(char* cadena){

    /*
     * Contador de longitud de un arreglo caracteres
     *
     * Variables, constantes y arreglos.
     * cadena: arreglo de caracteres.
     *
     * Retorno:
     * len: longitud de la cadena.
    */

    int len = 0;
    while(cadena[len] != '\0'){
        len ++;
    }

    return len;
}


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

int contDigits(int n){

    /*
     * Contador de digitos
     *
     * Variables, constantes y arreglos.
     * n: numero n del que se calculará la longitud.
     *
     * Retorno:
     * cont: cantidad de digitos.
    */

    int cont = 0;

    while(n > 0){
        n /= 10;
        cont ++;
    }

    return cont;

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


int NearbyMulti(int numero, int longitudMinima){

    /*
     * Calculador del minimo multiplo más cercano
     *
     * Variables, constantes y arreglos.
     * numero: numero del cual se calculará el minimo multiplo no menor a longitudMinima.
     * longitudMinima: el valor minimo que se debe alcanzar.
     *
     * Retorno:
     * multiplo: minimo multiplo no menor a longitudMinima.
    */

    int multiplo = (longitudMinima / numero) * numero;
    if (multiplo < longitudMinima) {
        multiplo += numero;
    }
    return multiplo;
}

char* slicing(char* cadenaOriginal, int indiceInicio, int indiceFin){

    /*
     * Slicing de arreglos de caracteres
     *
     * Variables, constantes y arreglos.
     * cadenaOriginal: cadena de la cuál se extraerá la subcadena.
     * indiceInicio: extremo inferior para la subcadena.
     * indiceFin: extremo superior para la subcadena.
     *
     * Retorno:
     * nuevaCadena: subcadena generada en base a los indices.
    */

    int nuevaLongitud = indiceFin - indiceInicio;
    char* nuevaCadena = new char[nuevaLongitud + 1];
    int iGen = 0;

    for (int i = indiceInicio; i < indiceFin; i++) {
        nuevaCadena[iGen] =  cadenaOriginal[i];
        iGen ++;
    }
    nuevaCadena[nuevaLongitud] = '\0';

    return nuevaCadena;

}

int charToInt(char* cadena){

    /*
     * Conversor de caracter a entero
     * Cabe decir que esta funcion hace lo mismo que uno de los problemas sin embargo se separó para mayor orden
     *
     * Variables, constantes y arreglos.
     * cadena: cadena de caracteres númericos.
     *
     * Retorno:
     * resultado*signo: cadena de caracteres casteada a entero con su respectivo signo.
    */

    int resultado = 0;
    char* punteroIterador = cadena;
    int signo = 1;

    if(*punteroIterador == '-'){
        signo = -1;
    }

    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            resultado = resultado * 10 + (*punteroIterador - '0');
        }
        punteroIterador ++;
    }

    return resultado * signo;

}

bool checkRoman(char* array){

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


char** llenarMatrizCine() {
    /*
     * Rellenadora de matriz, por char
     * Única aplicación para problema 11
     *
     * Variables, constantes y arreglos
     * matriz: arreglo de caracteres dinamico.
     *
     * return:
     * matriz.
    */
    char** matriz = new char*[15];
    for (int i = 0; i < 15; ++i) {
        matriz[i] = new char[20];
        for (int j = 0; j < 20; ++j) {
            matriz[i][j] = '-';
        }
    }
    return matriz;
}


void printMatrizCine(char** arreglo){
    /*
     * Para mostrar la matriz en pantalla,
     * Justo como la anterior funcion pero
     * cambiada por un ocasional glitch del .h
     *
    */

    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << arreglo[i][j] << "  ";
        }
        cout << endl;
    }
}


void cleanMatrizCine(int filas, char **arreglo){

    /*
     * Liberador de memoria matriz dinamica de Caracteres.
     *
     * Variables, constantes y arreglos.
     * matriz: doble puntero indicador del espacio en memoria donde estará almacenada la matriz.
     * filas: numero de filas de la matriz.
     *
     * Retorno:
     * vacio.
    */

    for (int i = 0; i < filas; i++) {
        delete[] arreglo[i];
    }
    delete[] arreglo;
}


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
            if(matriz[i][j] > 9){
                cout << matriz[i][j] << " ";
            }
            else{
                cout << matriz[i][j] << "  ";
            }
    }

        cout << endl;
    }
}

void fillMatrizRandom(int** matriz, int filas, int columnas){

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
    srand(time(0));

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 15+1;
        }
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
                if(matriz[i][j] > 9){
                    cout << matriz[i][j] << " ";
                }
                else{
                    cout << matriz[i][j] << "  ";
                }
            }
            cout << endl;
        }
        break;
    case 180:
        for(int i = filas-1; i>=0; i--){
            for(int j = columnas-1; j>=0;j--){
                if(matriz[i][j] > 9){
                    cout << matriz[i][j] << " ";
                }
                else{
                    cout << matriz[i][j] << "  ";
                }
            }
            cout << endl;
        }
        break;
    case 270:
        for (int j = columnas - 1; j >= 0; j--) {
            for (int i = 0; i < filas; i++) {
                if(matriz[i][j] > 9){
                    cout << matriz[i][j] << " ";
                }
                else{
                    cout << matriz[i][j] << "  ";
                }
            }
            cout << endl;
        }

        break;

    }

}


unsigned long long factorial(int n) {

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
    if (n == 0) {
        return 1;
    }

    //La función se llama así misma hasta que llega al caso base
    return n * factorial(n - 1);
}

int divisoresSum(int num){
    /*
     * Suma de divisores de un número
     *
     * Variables, constantes.
     * num: número para determinar sus divisores
     * suma: lleva el resultado de la suma de sus divisores (v.r)
     *
     * Rwtorno:
     * Suma
     *
     */
    int suma = 1;
    for(int i = 2; i < num; ++i){
        if(num%i == 0){
            suma += i;
        }
    }
    return suma;
}


