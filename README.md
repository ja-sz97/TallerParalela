# Taller n°1 de Computación Paralela y Distribuida

<img alt="Visual Studio Code" src="https://img.shields.io/badge/VisualStudioCode-0078d7.svg?&style=for-the-badge&logo=visual-studio-code&logoColor=white"/> 

<img alt="C++" src="https://img.shields.io/badge/c++-%2300599C.svg?&style=for-the-badge&logo=c%2B%2B&ogoColor=white"/>

#### Resumen

El objetivo de este repositorio es presentar un programa escrito en el lenguaje c++ que hará uso de la utilidad de Makefile para compilar de forma ordenada y estructurada los distintos archivos .cpp, el cuál se ejecutará desde la terminal de GNU/Linux.

La finalidad de este programa es leer y operar la información de los promedios de 15.000 estudiantes almacenados en un archivo .csv ("Comma Separated Values"). Donde se utilizarán algoritmos y estructuras de datos para obtener los mejores promedios en base a determinados criterios:

+ 100 Mejores promedios generales.
+ 100 Mejores promedios artísticos.
+ 100 Mejores promedios humanistas.
+ 100 Mejores promedios técnicos.

Escribiendo dichos promedios en su respectivo archivo .csv con el formato:

+ Identificador, Nombre generico del estudiante, Promedio calculado.


Para ejecutar el programa:
make dist
Para limpiar:
make limpiar