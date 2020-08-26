#include <iostream>
#include <string>
using namespace std;


struct MP3
{
    string artista;
    string title;
    float duracion;
    float tfichero = 7.964;
};

int main()
{
    MP3 mp3;

    mp3.artista;
    mp3.title;
    mp3.duracion;
    mp3.tfichero;

    float seg;

    cout << "Ingresar el nombre del artista: ";
    getline(cin,mp3.artista);

    cout << "Ingresar el titulo de la cancion: ";
    getline(cin,mp3.title);

    cout << "Ingresar duracion del tema: ";
    cin >> mp3.duracion;

    seg = mp3.duracion * 60;
    cout << "\nEl nombre del artista es: " << mp3.artista << ".\nEl titulo de la cancion es: " << mp3.title<<"." << endl;
    cout << "Duracion de la cancion: " << seg << " segundos.\nTamanio del fichero: " << mp3.tfichero << " KB." << endl;

    return 0;
}

