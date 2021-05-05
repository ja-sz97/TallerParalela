#include <iostream>
#include <string>
#include <stdlib.h>
#include "funciones.h"
#include "persona.h"

using namespace std;

int main() {
    
    //Declaracion de variables globales
    Persona Listado[15001];
    int MejoresPromedios[400];

    //Lectura de archivo estudiantes.csv y asignacion a su correspondiente clase Persona
    leerArchivo(Listado);

    //LLamada a funciones para obtener los mejores promedios de cada estudiante según su criterio
    MejorPromedio(Listado, MejoresPromedios);
    MejorArtistico(Listado, MejoresPromedios);
    MejorHumanista(Listado, MejoresPromedios);
    MejorTecnicos(Listado, MejoresPromedios);

    return 0;
}
