/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
¿Qué aprendí en el desarrollo de esta clase?
*/

#ifndef Serie_h
#define Serie_h

#include <stdio.h>
#include <string>
// Para herencia 
#include "Video.h"
// Para composición 
#include "Episodio.h"
using namespace std;

class Serie : public Video {
// Atributos 
private:
    Episodio episodios [5];
    int cantidad;

    // Métodos
public:
        // Constructores
        Serie ();
        Serie(string _iD, string _titulo, int _duracion, 
        string _genero, double _calificacion); // Nuevo constructor

        // Métodos modificadores - setters
        void setEpisodio (int posicion, Episodio Episodio);
        void setCantidad (int _cantidad);

        // Métodos de acceso - getters
        Episodio getEpisodio (int posicion);
        int getCantidad ();

        // Otros métodos 
        double calculaPromedio ();
        void calculaDuracion(); // Método agregado 
        string str ();
        
        void agregaEpisodio (Episodio episodio); 

};


#endif /* Serie_h */