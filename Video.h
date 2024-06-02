/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
¿Qué aprendí en el desarrollo de esta clase?
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;

class Video {
// Atributos 
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;
    
// Métodos
public: 
    // Constructores 
    Video();
    Video (string _iD, string titulo, int duracion, string genero, double _calificacion);

    // Métodos modificadores - Setters
    void setId(string _iD);
    void setNombre(string _titulo);
    void setDuracion (int _duracion);
    void setGenero (string _genero);
    void setCalificacion (double _calificacion);

    // Métodos de acceso - Getters
    string getId ();
    string getNombre ();
    int getDuracion ();
    string getGenero ();
    double getCalificacion ();

    // Otros métodos
    virtual string str();
};

 #endif /* Video_hpp */

