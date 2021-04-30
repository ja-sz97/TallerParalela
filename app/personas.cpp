#include <iostream>
#include <fstream> //libreria para lectura y escritura en archivos
#include <sstream> //libreria para lectura y asignacion a variables de datos de archivos
#include <cstring>
#include <stdlib.h>
#include <string>
#include "personas.h"

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

void leerArchivo(Personas Listado[]){
    ifstream archivo;
    string linea,linea2;
 
    string id, idEstudiante, promLenguaje, promIngles, promMatematicas, promCiencias, promHistoria, promTecnologia, promArte, promEdFisica;

    archivo.open("estudiantes.csv", ios::in );

    

        if(archivo.fail()){
            cout<<"error"<<endl;
            exit(1);
        }

        while (!archivo.eof()){
            int i = 1;
            

            //getline(archivo,linea2);
            //cout<<linea2<<endl;

            while(getline(archivo,linea)){
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

                int _id;
                float _promLenguaje, _promIngles, _promMatematicas, _promCiencias, _promHistoria, _promTecnologia, _promArte, _promEdFisica;


                _id = atoi(id.c_str());
                _promLenguaje = stof(promLenguaje);
                _promIngles = stof(promIngles);
                _promMatematicas = stof(promMatematicas);
                _promCiencias = stof(promCiencias);
                _promHistoria = stof(promHistoria);
                _promTecnologia = stof(promTecnologia);
                _promArte = stof(promArte);
                _promEdFisica = stof(promEdFisica);

                Listado[i].setAtributos(_id,idEstudiante,_promLenguaje,_promIngles,_promMatematicas,_promCiencias,_promHistoria,_promTecnologia,_promArte,_promEdFisica);


                i++;

            } 
        }
        archivo.close();
    }


void Personas::verDatos(){
    cout<<"id: "<<id<<endl;
    cout<<"idEstudiante: "<<idEstudiante<<endl;
    cout<<"Promedio Lenguaje: "<<promLenguaje<<endl;
}

void MejorPromedio(Personas Listado[], int MejoresPromedios[]){ 
    float mejores[100][2], promedio;
    int indice, aux= 0;
    for (int i = 1; i<15002; i++){ 
        promedio = (Listado[i].getPromArte() + Listado[i].getPromCiencias() + Listado[i].getPromEdfisica() + Listado[i].getPromHistoria() + Listado[i].getPromIngles() + Listado[i].getPromLenguaje() + Listado[i].getProMatematicas() + Listado[i].getPromTecnologia())/8 ;
        if(aux == 100){
            float menor = 7;
            for (int j = 0; j<100; j++){
                if ( menor > mejores[j][2]){       //guardado del menor promedio de la lista
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

    for (int x = 0 ; x<100 ; x++ ){
    //    cout<< "Alumno " << mejores[x][1] << " " <<"Promedio:"<< mejores[x][2] <<endl;
    //    cout << x << endl; 
        MejoresPromedios[x] = mejores[x][1];
    }
    
    for(int i=0;i<100;i++){
        cout<<"mejores Estudiantes "<<i<<" "<<MejoresPromedios[i]<<endl;
    }
    
}

bool comprobar(int id, int MejoresPromedios[]){
    bool aux=false;
    for(int i=1 ; i<15001 ; i++){
        if(id == MejoresPromedios[i]){
            aux=true;
        }
    }
    return aux;
}

void MejorArtistico(Personas Listado[], int MejoresPromedios[]){

    float promArteEdFisica, mejores[100][2];
    int aux=0, indice;
    bool encuentra;
    
    for(int i=1; i<15001 ; i++){
        encuentra = comprobar(Listado[i].getId(),MejoresPromedios);
        if(!encuentra){
            promArteEdFisica = (Listado[i].getPromArte() + Listado[i].getPromEdfisica())/2;
            if(aux == 100){
                float menor = 7;
                for (int j = 0; j<100; j++){
                    if ( menor > mejores[j][2]){       //guardado del menor promedio de la lista
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

    for (int x = 0 ; x<100 ; x++ ){
        MejoresPromedios[x+100] = mejores[x][1];
    }
    
    for(int i=0;i<200;i++){
        cout<<"mejores Estudiantes "<<i<<" "<<MejoresPromedios[i]<<endl;
    }
    
}


