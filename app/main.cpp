#include <iostream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
#include "personas.h"

using namespace std;


int main() {
    
    //declaracion de variables globales
    Personas Listado[15001];
    int MejoresPromedios[300];


    leerArchivo(Listado);

    //Listado[1].verDatos();
    
    MejorPromedio(Listado, MejoresPromedios);
    MejorArtistico(Listado, MejoresPromedios);
    MejorHumanista(Listado, MejoresPromedios);
    MejorTecnicos(Listado, MejoresPromedios);


    return 0;
}
