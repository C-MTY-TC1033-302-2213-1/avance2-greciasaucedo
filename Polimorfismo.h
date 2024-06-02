/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
¿Qué aprendí en el desarrollo de esta clase?
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include "Video.h"

using namespace std;

const int MAX_VIDEOS = 100;

// Identificar si un objeto es de cierta clase usaremos
if (typeid(*arrPtrVideos[index]) == typeid(Pelicula))

class Polimorfismo {
private:
    Video* arrPtrVideos[MAX_VIDEOS]; // Pointers a objetos de Video
    int cantidad;

public:
    Polimorfismo();
    void leerArchivo(string _nombre);

    // Métodos modificadores - setters 
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // Métodos de acceso - getters
    Video* getPtrVideo (int index);
    int getCantidad();

    // Otros métodos 
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif /* Polimorfismo_h */
