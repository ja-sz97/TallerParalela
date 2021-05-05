#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

using namespace std;

// Clase Persona con la cual se manipulará la informacion de cada estudiante
class Persona{

    //Atributos
    private:
        int id;
        string idEstudiante;
        float promLenguaje, promIngles, promMatematicas, promCiencias, promHistoria, promTecnologia, promArte, promEdFisica;

    //Metodos Getters y Setters
    public:
        void setAtributos(int _id, string _idEstudiante, float _promLenguaje, float _promIngles, float _promMatematicas, float _promCiencias, float _promHistoria, float _promTecnologia, float _promArte, float _promEdFisica){
            id = _id;
            idEstudiante = _idEstudiante;
            promLenguaje = _promLenguaje;
            promIngles = _promIngles; 
            promMatematicas = _promMatematicas;
            promCiencias = _promCiencias;
            promHistoria = _promHistoria;
            promTecnologia = _promTecnologia;
            promArte = _promArte;
            promEdFisica = _promEdFisica;
        }

        int getId(){
            return id;
        }
        string getIdEstudiante(){
            return idEstudiante;
        }
        float getPromLenguaje(){
            return promLenguaje;
        }
        float getPromIngles(){
            return promIngles;
        }
        float getProMatematicas(){
            return promMatematicas;
        }
        float getPromCiencias(){
            return promCiencias;
        }
        float getPromHistoria(){
            return promHistoria;
        }
        float getPromTecnologia(){
            return promTecnologia;
        }
        float getPromArte(){
            return promArte;
        }
        float getPromEdfisica(){
            return promEdFisica;
        }
};

//Typedef de las estructuras de datos globales
typedef Persona Listado[15000];
typedef int MejoresPromedios[400];

//Funciones que utilizaran las estructuras de datos declaradas
void leerArchivo(Persona Listado[]);
void MejorPromedio(Persona Listado[], MejoresPromedios);
void MejorArtistico(Persona Listado[], MejoresPromedios);
void MejorHumanista(Persona Listado[], MejoresPromedios);
void MejorTecnicos(Persona Listado[],MejoresPromedios);

#endif //PERSONAS_H_INCLUDED
