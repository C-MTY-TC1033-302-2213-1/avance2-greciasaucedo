/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
*/

#include "Pelicula.h"

// Constructores: vacio y con parámetros 
    Pelicula::Pelicula():Video () {
        oscares = 100;
    }
    Pelicula::Pelicula(string _iD, string _titulo,
            int _duracion, string _genero,
            double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
                oscares = _oscares;
            }

    // Métodos modificadores - setters
    void Pelicula::setOscares(int _oscares){
        oscares = _oscares;
    }

    // Métodos de acceso - getters
    int Pelicula::getOscares(){
        return oscares;
    }

    // Otros métodos 
    string Pelicula::str(){
        // Tenemos acceso directo a los atributos de la clase padre porque son protected 
      return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +  genero + ' ' 
        + to_string (calificacion) + ' ' + to_string(oscares); 
    }
