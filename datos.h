#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#include <string>
#include <stdio.h>

using namespace std;


typedef struct
{
    string nombre;
    string apellido;
    string carrera;
   int anio;
}tdatos;

void listaPalumno();
void datosAlumno();
void mostrarAlumno();
void pedirAlumno();
void eliminarAlumno();
void ordenDescendente();
void ordenAscendente();

#endif // DATOS_H_INCLUDED
