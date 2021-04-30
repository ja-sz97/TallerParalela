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

        int getid(){
            return id;
        }
        string getidEstudiante(){
            return idEstudiante;
        }
        float getpromLenguaje(){
            return promLenguaje;
        }
        float getpromIngles(){
            return promIngles;
        }
        float getproMatematicas(){
            return promMatematicas;
        }
        float getpromCiencias(){
            return promCiencias;
        }
        float getpromHistoria(){
            return promHistoria;
        }
        float getpromTecnologia(){
            return promTecnologia;
        }
        float getpromArte(){
            return promArte;
        }
        float getpromEdfisica(){
            return promEdFisica;
        }

        void verDatos();
};

typedef Personas Listado[15000];

void leerArchivo(Personas Listado[]);

void MejorPromedio1(Personas Listado[]);

#endif //PERSONAS_H_INCLUDED
