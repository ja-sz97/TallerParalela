#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include "funciones.h"
#include "personas.h"

using namespace std;

int main() {
    cout << "Hello, World!" <<endl;
    saludo();
    
    Personas Listado[15000];
    
    leerArchivo(Listado);

    Listado[1].verDatos();

    return 0;
}
