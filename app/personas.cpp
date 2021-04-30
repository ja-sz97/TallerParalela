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

void MejorPromedio1(Personas Listado[]){ 
    float Mejores[100][2], promedio;
    int indice, aux= 0;
    for (int i = 1; i<15002; i++){ 
        promedio = (Listado[i].getpromArte() + Listado[i].getpromCiencias() + Listado[i].getpromEdfisica() + Listado[i].getpromHistoria() + Listado[i].getpromIngles() + Listado[i].getpromLenguaje() + Listado[i].getproMatematicas() + Listado[i].getpromTecnologia())/8 ;
        if(aux == 100){
            int menor = 7;
            for (int j = 0; j<100; j++){
                if ( menor > Mejores[j][2]){       //guardado del menor promedio de la lista
                    menor = Mejores[j][2];
                    indice = j;
                }
            }
            if (menor < promedio){
                Mejores[indice][1] = Listado[i].getid();
                Mejores[indice][2] = promedio;
            }
        } 
        else{
            Mejores[aux][1] = Listado[i].getid();
            Mejores[aux][2] = promedio;
            aux++;
        }
    }

    for (int x = 0 ; x<100 ; x++ ){
        cout<< "Alumno " << Mejores[x][1] << " " <<"Promedio:"<< Mejores[x][2] <<endl;
        cout << x << endl; 
    }
}



