/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
*/

#include "Episodio.h"
    // Constructores 
    Episodio::Episodio (){
        titulo = "Clases Video y Episodio";
        temporada = 3;
        calificacion = 100;
    }

    Episodio::Episodio (string _titulo, int _temporada, int _calificacion){
        titulo = _titulo;
        temporada = _temporada;
        calificacion =_calificacion;
    }

    // Métodos modificadores - Setters
    void Episodio::setTitulo(string _titulo){
        titulo = _titulo;
    }

    void Episodio::setTemporada (int _temporada){
        temporada = _temporada;
    }

    void Episodio::setCalificacion (int _calificacion){
        calificacion = _calificacion;
    }

    // Métodos de acceso - Getters
    string Episodio::getTitulo (){
        return titulo;
    }

    int Episodio::getTemporada (){
        return temporada;
    }

    int Episodio::getCalificacion (){
        return calificacion;
    }

    // Otros métodos
    string Episodio::str(){
        return titulo + ' ' + to_string(temporada) + ' ' + to_string (calificacion); 
    }
