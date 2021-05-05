#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

using namespace std;

class Personas{
    private:
        int id;
        string idEstudiante;
        float promLenguaje, promIngles, promMatematicas, promCiencias, promHistoria, promTecnologia, promArte, promEdFisica;

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

        void verDatos();
};

typedef Personas Listado[15000];

typedef int MejoresPromedios[400];

void leerArchivo(Personas Listado[]);
void MejorPromedio(Personas Listado[], MejoresPromedios);
void MejorArtistico(Personas Listado[], MejoresPromedios);
void MejorHumanista(Personas Listado[], MejoresPromedios);
void MejorTecnicos(Personas Listado[],MejoresPromedios);
#endif //PERSONAS_H_INCLUDED
