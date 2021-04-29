#include <iostream>
#include <fstream> //libreria para lectura y escritura en archivos
#include <sstream> //libreria para lectura y asignacion a variables de datos de archivos
#include <cstring>
#include <stdlib.h>
#include <string>
#include "personas.h"

void leerArchivo(Personas Listado[]){
    ifstream archivo;
    string linea,linea2;
 
    string id, idEstudiante, promLenguaje, promIngles, promMatematicas, promCiencias, promHistoria, promTecnologia, promArte, promEdFisica;

    archivo.open("estudiantes.csv", ios::in );

    try{

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
                
                cout<<"aah"<<endl;

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
                
                
            
                cout<<id<<endl;
                cout<<idEstudiante<<endl;
                cout<<promLenguaje<<endl;

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
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}

void Personas::verDatos(){
    cout<<"id: "<<id<<endl;
    cout<<"idEstudiante: "<<idEstudiante<<endl;
    cout<<"Promedio Lenguaje: "<<promLenguaje<<endl;
}





