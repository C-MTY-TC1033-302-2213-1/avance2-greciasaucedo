/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
¿Qué aprendí en el desarrollo de esta clase? Que no necesito agregar todos los 
nombres solamente de lo nuevo ya que se heredan de otras clases.
*/

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include <iostream>
#include <string>
#include "Video.h" // Clase base 
using namespace std;

// Clase Pelicula es derivada de Video (:)
class Pelicula : public Video {
    private:
    int oscares;

    public:
    // Constructores: vadio y con parámetros
    Pelicula();
    Pelicula(string _iD, string _titulo,
            int _duracion, string _genero,
            double _calificacion, int _oscares);

    // Métodos modificadores - setters
    void setOscares (int _oscares);

    // Métodos de acceso - getters
    int getOscares();

    // Otros métodos 
    string str();

};


#endif /* Pelicula_h */