#include <enrutador.h>
#include <red.h>
#include <gestorTxt.h>


int main(){
    red red_Principal;
    string ruta = "../Unidad4/Archivos/rutas.txt";
    srand(time(NULL));
    red_Principal.menu(ruta);
}



