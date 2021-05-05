#include <iostream>
#include <stdlib.h>
#include <string>
#include "funciones.h"
#include "persona.h"

using namespace std;

/*
Función que retorna un string normalizado de las variables, removiendo caracteres no deseados
*/
string normalizar(string palabra){
    
    //Variables
    char caracterIndeseado[] = {'"'};
    string palabranueva;
    int aux = palabra.length();

    for (int i = 0; i < aux ; i++){
        if (palabra[i] != caracterIndeseado[0]){
            palabranueva += palabra[i];
        }
    }
    return palabranueva;
}


/*
Función que ordena los promedios de las notas de mayor a menor
*/
void ordenarMayorMenor(float mejores[][2]){
    
    //Variables
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


/* 
Funcion que retorna true en el caso de que coinsida un id de un estudiante con uno ya asignado u operado, para ignorarlo en posteriores calculos
*/
bool comprobar(int id, int MejoresPromedios[]){
    
    //Variables
    bool coincide=false;

    for(int i=1 ; i<301 ; i++){
        if(id == MejoresPromedios[i]){
            coincide=true;
        }
    }
    return coincide;
}


void imprimirIntegrantes(){
    cout<<endl;
    cout<<" === Integrantes === "<<endl;
    cout<<endl;
    cout<<" - Leonardo Peña"<<endl;
    cout<<" - Javier Saavedra"<<endl;
    cout<<" - Esteban Moyano"<<endl;
    cout<<endl;
}