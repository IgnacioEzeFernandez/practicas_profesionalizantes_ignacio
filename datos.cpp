#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include "datos.h"

using namespace std;

tdatos Dates[30];
int MaxAlumnos = 0;
int contador;

void listaPalumno()
{
    int option;


    fstream archivo("Alumnos.txt");

    do
    {
      if(!archivo.is_open())
      {
          archivo.open ("Alumnos.txt",ios::out);
      }

        cout << endl;
        cout << "Escoja una opcion:" << endl;
        cout << "1.- Insertar un alumno al registro." << endl;
        cout << "2.- Mostrar informacion de todos los alumnos." << endl;
        cout << "3.- Buscar a un alumno." << endl;
        cout << "4.- Eliminar alumno." << endl;
        cout << "5.- Ordenar registros de forma descendente." << endl;
        cout << "6.- Ordenar registros de forma ascendente." << endl;
        cout << "7.- Guardar registros y salir." << endl;
        cin >> option;


        switch(option)
        {
case 1:

               {
               datosAlumno();
               }
                break;

case 2:

                {
                mostrarAlumno();
                }

                break;

case 3:

               {
               pedirAlumno();
               }
                break;

case 4:

              {
              eliminarAlumno();
              }
                break;

case 5:

              {
              ordenDescendente();
              }
               break;

case 6:
               {
               ordenAscendente();
               }
               break;
case 7:

            {
                  for (contador = 0; contador < MaxAlumnos ; contador++)

                   archivo << "\nNombre: " << Dates[contador].nombre << "." << "\nApellido: " << Dates[contador].apellido << "." << "\nCarrera: " << Dates[contador].carrera << "." << "\nAnio: " << Dates[contador].anio << "." <<"\n" << endl;


                    system("cls");

                cout << "Datos guardados correctamente...\n";
                cout << "\nFin del programa\n" << endl;

                    system ("pause");
                    system("cls");
                    archivo.close();

            break;

            default:
                cout << "¡Opcion desconocida!" << endl;
        }
                break;
        }

    }
     while (option != 7);

}

void datosAlumno()
{



   if(MaxAlumnos < 30)
   {

                    cout << "Introduce el nombre del alumno: ";
                    fflush(stdin);
                    getline (cin,Dates[MaxAlumnos].nombre);

                    cout << "\nIntroduce el apellido del alumno: ";
                    fflush(stdin);
                    getline (cin,Dates[MaxAlumnos].apellido);


                    cout << "\nIntroduce la carrera del alumno: ";
                    getline(cin,Dates[MaxAlumnos].carrera);

                    cout << "\nIntroduce el anio: ";
                    cin >> Dates[MaxAlumnos].anio;

                     MaxAlumnos++;

    }else
    cout <<"Maximo de alumnos superada. (30)" << endl;
}

void mostrarAlumno()

{


for (contador = 0; contador < MaxAlumnos ; contador++)
{
cout << "\nNombre: " << Dates[contador].nombre << "." << "\nApellido: " << Dates[contador].apellido << "." << "\nCarrera: " << Dates[contador].carrera  << "." <<"\nAnio: " << Dates[contador].anio << "." << "\n"<< endl;
}
}


void pedirAlumno()

{

       string tempText;

       cout << "\nMuestre los datos de un alumno.\n" << endl;
       cout << "Ingrese el nombre del alumno: ";
       cin >> tempText;

        for (contador= 0; contador < MaxAlumnos; contador++)

           if (Dates[contador].nombre == tempText)

          cout << "\nNombre: " << Dates[contador].nombre << "." << "\nApellido: " << Dates[contador].apellido << "." << "\nAnio: " << Dates[contador].anio << "." << "\nCarrera: "<< Dates[contador].carrera << "." << endl;
}

void eliminarAlumno()
{
    string x;

   cout << "Ingrese el nombre del alumno a eliminar: ";
   cin >>x;

   cout << "\n:::REGISTRO DE ALUMNOS MODIFICADO:::\n" << endl;

    for(contador=0; contador<MaxAlumnos; contador++)
    {
        if(Dates[contador].nombre == x)
        {
        Dates[contador].nombre = '0';
        Dates[contador].apellido = '0';
        Dates[contador].carrera = '0';
        Dates[contador].anio = 0;

        }
      cout << "\nNombre: " << Dates[contador].nombre << "\nApellido: " << Dates[contador].apellido << "\nCarrera: " << Dates[contador].carrera << "\nAnio: " << Dates[contador].anio << endl;
    }
    cout << "\nAlumno eliminado del registro correctamente.\n" << endl;
}

void ordenDescendente()
{
    ///Metodo burbuja
    int j, aux;
    for(contador=0; contador<MaxAlumnos; contador++){
        for(j=contador+1;j<MaxAlumnos; j++){
            if(Dates[contador].anio < Dates[j].anio){
                aux = Dates[contador].anio;
                Dates[contador].anio = Dates[j].anio;
                Dates[j].anio = aux;

             }

        }

    }

    cout << "ORDEN DESCENDENTE: " << endl;
    cout << "(del mayor anio al menor)" << endl;
    for(contador = 0; contador < MaxAlumnos; contador++){
        cout << "\nAnio: " << Dates[contador].anio << "\nNombre: " << Dates[contador].nombre << "\nApellido: " << Dates[contador].apellido << "\nCarrera: " << Dates[contador].carrera << endl;
    }


}

void ordenAscendente()
{

    int j, aux;
    for(contador=0; contador<MaxAlumnos; contador++){
        for(j=contador+1;j<MaxAlumnos; j++){
            if(Dates[contador].anio > Dates[j].anio){
                aux = Dates[contador].anio;
                Dates[contador].anio = Dates[j].anio;
                Dates[j].anio = aux;

             }

        }

    }

    cout << "ORDEN ASCENDENTE: " << endl;
    cout << "(del menor anio al mayor)\n" << endl;
    for(contador = 0; contador<MaxAlumnos; contador++){
        cout << "\nAnio: " << Dates[contador].anio << "\nNombre: " << Dates[contador].nombre << "\nApellido: " << Dates[contador].apellido << "\nCarrera: " << Dates[contador].carrera << endl;
    }


}
