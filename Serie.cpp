/*
Nombre: Grecia Klarissa Saucedo Sandoval 
Matricula: A00839374
Carrera: ITC
Fecha: 2/junio/2024 
*/

#include "Serie.h"

// Constructores
        Serie::Serie() : Video() {
            cantidad = 0;
        }
        
        Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
        :Video(_iD, _titulo, _duracion, _genero, _calificacion){
            // Solo vamos a inicializar cantidad
            cantidad = 0;
        }

        // Métodos modificadores - setters
        void Serie::setEpisodio (int posicion, Episodio episodio){
            // Primero validar que exista el episodio 
            if (posicion >= 0 && posicion < cantidad) {
                episodios[posicion] = episodio;
            }
        }

        // Cambiar el valor del atributo cantidad con el nuevo valor recibido en _cantidad
        void Serie::setCantidad (int _cantidad){
            cantidad = _cantidad;
        }

        // Métodos de acceso - getters
        Episodio Serie::getEpisodio (int posicion){
            // Crea un objeto del tipo Episodio y lo inicializa con el Constructor default 
            Episodio epi; 
            // Validad primero que exista el episodio solicitado (posicion)
            if(posicion >= 0 && posicion < cantidad){
                return episodios[posicion];
            }

            // Si no existe retorna un default 
            return epi;
        }

        // Retornar el valor de atributo 
        int Serie::getCantidad(){
            return cantidad;
        }

        // Otros métodos 
        double Serie::calculaPromedio (){
        double acum = 0;

        for (int idex = 0; idex < cantidad; idex++){
            acum = acum + episodios[idex].getCalificacion(); 
        }
        
        // Validar que tenga episodios
        if (cantidad > 0){
            return acum / cantidad;
        }
        else {
            return 0;
        }
        }

        void Serie::calculaDuracion() {
            int duracionTotal = 0;

             for (int index = 0; index < cantidad; index++) {
                duracionTotal += episodios[index].getTemporada();
            }

            duracion = duracionTotal; // Duración total de la serie
        }
        
    // Overriding del método str() de la clase Base 
        string Serie::str (){
            if (cantidad > 0){
                string info = "";
                
                for (int idex = 0; idex < cantidad; idex++){
                    info = info + '\n' + episodios[idex].str() + '\n';
                } 
                return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +  genero + ' ' + to_string (calificacion) + ' ' + to_string(cantidad) + info + '\n'; 
        }
        else{
            return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +  genero + ' ' + to_string (calificacion) + ' ' + to_string(cantidad) + '\n'; 
        
        }
        }

    // Agrega un episodio solo si existe espacio 
        void Serie::agregaEpisodio (Episodio episodio) {
            if (cantidad < 5) {
                episodios[cantidad++] = episodio;
            }
        }

        