/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
¿Qué aprendí en el desarrollo de esta clase? Repase conceptos previamente aprendidos 
y para mi no es costumbre agregar comentarios pero puedo ver que es sumamente práctico.
*/

#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>
using namespace std;

class Episodio{
// Atributos 
private:
    string titulo;
    int temporada;
    int calificacion;

// Métodos
public: 
    // Constructores 
    Episodio ();
    Episodio (string titulo, int temporada, int calificacion);

    // Métodos modificadores - Setters
    void setTitulo(string _titulo);
    void setTemporada (int _temporada);
    void setCalificacion (int _calificacion);

    // Métodos de acceso - Getters
    string getTitulo ();
    int getTemporada ();
    int getCalificacion ();

    // Otros métodos
    string str();
};

#endif /* Episodio_hpp */