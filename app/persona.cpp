#include <iostream>
#include <fstream> //Libreria para lectura y escritura en archivos
#include <sstream> //Libreria para lectura y asignacion a variables de datos de archivos
#include <cstring>
#include <stdlib.h>
#include <string>
#include "persona.h"
#include "funciones.h"

/*
Funcion para leer el archivo .csv mediante el uso de librería ifstream.
Se asignan los valores obtenidos a los atributos de la clase Persona()
*/
void leerArchivo(Persona Listado[]){
    //Declaracion de variables
    ifstream archivo;
    string linea, id, idEstudiante, promLenguaje, promIngles, promMatematicas, promCiencias, promHistoria, promTecnologia, promArte, promEdFisica;
    int _id;
    float _promLenguaje, _promIngles, _promMatematicas, _promCiencias, _promHistoria, _promTecnologia, _promArte, _promEdFisica;

    //Abrir archivo .csv con permiso de lectura
    archivo.open("estudiantes.csv", ios::in );
    if(archivo.fail()){
        cout<<"error"<<endl;
        exit(1);
    }
    while (!archivo.eof()){
        int i = 1;
        while(getline(archivo,linea)){
            
            //Lectura linea por linea, separando por ";" y asignando a variables
            stringstream stream(linea);
            getline(stream,id,';');
            getline(stream,idEstudiante,';');
            getline(stream,promLenguaje,';');
            getline(stream,promIngles,';');
            getline(stream,promMatematicas,';');
            getline(stream,promCiencias,';');
            getline(stream,promHistoria,';');
            getline(stream,promTecnologia,';');
            getline(stream,promArte,';');
            getline(stream,promEdFisica,';');

            //Normalizar las variables para quitar formato con comillas             
            id = normalizar(id);
            idEstudiante = normalizar(idEstudiante);
            promLenguaje = normalizar(promLenguaje);
            promIngles = normalizar(promIngles);
            promMatematicas = normalizar(promMatematicas);
            promCiencias = normalizar(promCiencias);
            promHistoria = normalizar(promHistoria);
            promTecnologia = normalizar(promTecnologia);
            promArte = normalizar(promArte);
            promEdFisica = normalizar(promEdFisica);

            //Cambiamos el tipo de variable de los datos, de string a int o floar
            _id = atoi(id.c_str());
            _promLenguaje = stof(promLenguaje);
            _promIngles = stof(promIngles);
            _promMatematicas = stof(promMatematicas);
            _promCiencias = stof(promCiencias);
            _promHistoria = stof(promHistoria);
            _promTecnologia = stof(promTecnologia);
            _promArte = stof(promArte);
            _promEdFisica = stof(promEdFisica);

            //Asignar valores obtenidos a los atributos de la clase Persona
            Listado[i].setAtributos(_id,idEstudiante,_promLenguaje,_promIngles,_promMatematicas,_promCiencias,_promHistoria,_promTecnologia,_promArte,_promEdFisica);
        
            i++;
        } 
    }
    archivo.close();
}


/*
Funcion que rellena los archivos .csv (creados en Makefile) dependiendo del nombreArchivo pasado por referencia
*/
void insertarMejorPromedio(Persona Listado[], float MejoresPromedios[][2], string nombreArchivo){
    //Declaracion de variables
    ofstream archivo;
    const char comilla = '"';

    //Escritura en el archivo .csv manteniendo el formato inicial
    for (int i=0 ; i<100 ; i++ ){
        for (int j=0; j<15001 ; j++){
            if (MejoresPromedios[i][1] == Listado[j].getId()){

                //Abrir archivo .csv con permisos de escritura
                archivo.open("al/"+nombreArchivo+".csv",ios::out | ios::app);
                archivo<<comilla << Listado[j].getId() << comilla << ";" << comilla <<Listado[j].getIdEstudiante()<<comilla<<";"<<comilla<<MejoresPromedios[i][2]<<comilla<<endl;
                archivo.close();
            }
        }
    }
}


/*
Funcion que obtiene los mejores 100 promedios de todos los estudiantes
*/
void MejorPromedio(Persona Listado[], int MejoresPromedios[]){ 
    
    //Declaracion de variables
    float mejores[100][2], promedio;
    int indice, aux=0;

    for (int i=1; i<15001 ; i++){ 

        //Calculo del promedio de cada estudiante
        promedio = (Listado[i].getPromArte() + Listado[i].getPromCiencias() + Listado[i].getPromEdfisica() + Listado[i].getPromHistoria() + Listado[i].getPromIngles() + Listado[i].getPromLenguaje() + Listado[i].getProMatematicas() + Listado[i].getPromTecnologia())/8 ;

        //Algoritmo que obtiene los 100 mejores promedios y los asigna al arreglo mejores
        if(aux == 100){
            float menor = 7;
            for (int j=0; j<100 ; j++){

                //Guardado del menor promedio de la lista
                if ( menor > mejores[j][2]){       
                    menor = mejores[j][2];
                    indice = j;
                }
            }
            if (menor < promedio){
                mejores[indice][1] = Listado[i].getId();
                mejores[indice][2] = promedio;
            }
        } 
        else{
            mejores[aux][1] = Listado[i].getId();
            mejores[aux][2] = promedio;
            aux++;
        }
    }

    //Asigna la lista de los mejores 100 promedios al arreglo de los mejoresPromedios
    for (int x=0 ; x<100 ; x++ ){
        MejoresPromedios[x] = mejores[x][1];
    }

    //Se ordena de mayor a menor promedio 
    ordenarMayorMenor(mejores); 
    //Se llama la siguiente funcion para insertar los promedios en el archivo .csv 
    insertarMejorPromedio(Listado, mejores, "mejoresPromedios");
}


/*
Funcion que obtiene los mejores promedios artisticos entre artes y Ed Fisica
*/
void MejorArtistico(Persona Listado[], int MejoresPromedios[]){

    //Declaracion de variables
    float promArteEdFisica, mejores[100][2];
    int aux=0, indice;
    bool encuentra;
    
    for(int i=1; i<15001 ; i++){

        //Excluimos a los estudiantes ya asignados
        encuentra = comprobar(Listado[i].getId(),MejoresPromedios);
        if(!encuentra){

            //Calculo del promedio entre artes y ed. fisica
            promArteEdFisica = (Listado[i].getPromArte() + Listado[i].getPromEdfisica())/2;

            //Algoritmo que obtiene los 100 mejores promedios y los asigna al arreglo mejores
            if(aux == 100){
                float menor = 7;
                for (int j = 0; j<100; j++){
                    //Guardado del menor promedio de la lista
                    if ( menor > mejores[j][2]){       
                        menor = mejores[j][2];
                        indice = j;
                    }
                }
                if (menor < promArteEdFisica){
                    mejores[indice][1] = Listado[i].getId();
                    mejores[indice][2] = promArteEdFisica;
                }
            }else{
                mejores[aux][1] = Listado[i].getId();
                mejores[aux][2] = promArteEdFisica;
                aux++;
            }
        }
    }

    //Asigna la lista de los mejores 100 promedios al arreglo de los mejoresPromedios
    for (int x = 0 ; x<100 ; x++ ){
        MejoresPromedios[x+100] = mejores[x][1];
    }
    
    //Se ordena de mayor a menor promedio 
    ordenarMayorMenor(mejores);
    //Se llama la siguiente funcion para insertar los promedios en el archivo .csv 
    insertarMejorPromedio(Listado, mejores, "mejoresArtisticos");

}


/*
Funcion que obtiene los mejores promedios humanistas entre Lenguaje e Historia
*/
void MejorHumanista(Persona Listado[], int MejoresPromedios[]){

    //Declaracion de variables
    float promLengHistoria, mejores[100][2];
    int aux=0, indice;
    bool encuentra;
    
    for(int i=1; i<15001 ; i++){

        //Excluimos a los estudiantes ya asignados
        encuentra = comprobar(Listado[i].getId(),MejoresPromedios);
        if(!encuentra){

            //Calculo del promedio entre lenguaje e historia
            promLengHistoria = (Listado[i].getPromLenguaje() + Listado[i].getPromHistoria())/2;

            //Algoritmo que obtiene los 100 mejores promedios y los asigna al arreglo mejores
            if(aux == 100){
                float menor = 7;
                for (int j = 0; j<100; j++){
                    //Guardado del menor promedio de la lista
                    if ( menor > mejores[j][2]){       
                        menor = mejores[j][2];
                        indice = j;
                    }
                }
                if (menor < promLengHistoria){
                    mejores[indice][1] = Listado[i].getId();
                    mejores[indice][2] = promLengHistoria;
                }
            }else{
                mejores[aux][1] = Listado[i].getId();
                mejores[aux][2] = promLengHistoria;
                aux++;
            }
        }
    }

    //Asigna la lista de los mejores 100 promedios al arreglo de los mejoresPromedios
    for (int x = 0 ; x<100 ; x++ ){
        MejoresPromedios[x+200] = mejores[x][1];
    }
    
    //Se ordena de mayor a menor promedio
    ordenarMayorMenor(mejores);
    //Se llama la siguiente funcion para insertar los promedios en el archivo .csv 
    insertarMejorPromedio(Listado, mejores, "mejoresHumanistas");
}


/*
Funcion que obtiene los mejores promedios tecnicos entre tecnologia, matematicas y ciencias
*/
void MejorTecnicos(Persona Listado[], int MejoresPromedios[]){

    //Declaracion de variables
    float promTecMat, mejores[100][2];
    int aux=0, indice;
    bool encuentra;
    
    for(int i=1; i<15001 ; i++){

        //Excluimos a los estudiantes ya asignados
        encuentra = comprobar(Listado[i].getId(),MejoresPromedios);
        if(!encuentra){

            //Calculo del promedio entre tecnologia y matematicas
            promTecMat= (Listado[i].getPromTecnologia() + Listado[i].getProMatematicas() + Listado[i].getPromCiencias())/3;

            //Algoritmo que obtiene los 100 mejores promedios y los asigna al arreglo mejores
            if(aux == 100){
                float menor = 7;
                for (int j = 0; j<100; j++){
                    //Guardado del menor promedio de la lista
                    if ( menor > mejores[j][2]){       
                        menor = mejores[j][2];
                        indice = j;
                    }
                }
                if (menor < promTecMat){
                    mejores[indice][1] = Listado[i].getId();
                    mejores[indice][2] = promTecMat;
                }
            }else{
                mejores[aux][1] = Listado[i].getId();
                mejores[aux][2] = promTecMat;
                aux++;
            }
        }
    }

    //Asigna la lista de los mejores 100 promedios al arreglo de los mejoresPromedios
    for (int x = 0 ; x<100 ; x++ ){
        MejoresPromedios[x+300] = mejores[x][1];
    }
    
    //Se ordena de mayor a menor promedio
    ordenarMayorMenor(mejores);
    //Se llama la siguiente funcion para insertar los promedios en el archivo .csv
    insertarMejorPromedio(Listado, mejores, "mejoresTecnicos");

}

