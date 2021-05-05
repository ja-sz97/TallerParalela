#include <stdlib.h>
#include <string>
#include "funciones.h"
#include "personas.h"

using namespace std;

/*Función que normaliza las lineas del archivo para poder transformar las variables*/

string normalizar( string palabra){
    char CaracterIndeseado[] = {'"'};
    string palabranueva;
    int aux = palabra.length();
    for (int i = 0; i < aux ; i++){
            if (palabra[i] != CaracterIndeseado[0]){
                palabranueva += palabra[i];
            }
    }
    return palabranueva;
}

/*
* Función que ordena en relacion a las notas
*/

void OrdenarMayorMenor(float mejores[][2]){
    float aux1, aux2;
    for (int i = 0; i<100; i++){
        for(int j = 0 ; j<99; j++){
            if (mejores[j][2] < mejores[j+1][2]){
                aux2 = mejores[j][2];
                aux1 = mejores[j][1];
                mejores[j][2] = mejores[j+1][2];
                mejores[j][1] = mejores[j+1][1];
                mejores[j+1][2] = aux2;
                mejores[j+1][1] = aux1;
                }
        }
    }
}

/* Comprobar si es que encuentra el id en el arreglo de mejores promedios para ignorarlo en los calculos */
bool comprobar(int id, int MejoresPromedios[]){
    bool aux=false;
    for(int i=1 ; i<301 ; i++){
        if(id == MejoresPromedios[i]){
            aux=true;
        }
    }
    return aux;
}
