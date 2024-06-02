/*

Nombre: Grecia Klarissa Saucedo Sandoval
Matrícula: A00839374
Carrera: ITC
Fecha: 26 - MAYO - 2024

*/
#include "Polimorfismo.h"
#include "Serie.h"
#include "Pelicula.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

// Constructor default - vacio  
Polimorfismo::Polimorfismo(){
    for(int index = 0;  index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

    // Métodos modificadores - setters 
    void Polimorfismo::setPtrVideo(int index, Video *video){
        // Validar index - >=0 && < cantidad 
        if (index >=0 && index < cantidad){
            // Modificar el apuntador 
            arrPtrVideos[index] = video;
        }
    }
    // Cambiar el valor del atributo cantidad 
    // Validar que _cantidad este entre 0 .. MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo
    void Polimorfismo::setCantidad(int _cantidad){
        if (_cantidad >=0 && _cantidad <= MAX_VIDEOS) {
            cantidad = _cantidad;
        }
    }

    // Métodos de acceso - getters
    Video* Polimorfismo::getPtrVideo (int index){
        // Validar que _index exista en el arreglo, si no existe se retorna nullptr.
        if (index >= 0 && index < cantidad) {
            return arrPtrVideos[index];
        }

        // Si no existe
        return nullptr;
    }
    int Polimorfismo::getCantidad(){
        return cantidad;
    }

    // Otros métodos 
    /* reporteInventario
    Despliega todas las series y peliculas del arreglo 
    al final despliega ## indica la cantidad en existencia
    Peliculas = ##
    Series = ##
    */
    void Polimorfismo::reporteInventario(){
        // Declaración de contadores
        int contPeliculas, contSeries;

        // Inicializar contadores 
        contPeliculas = 0;
        contSeries = 0; 

        // Recorrer todo el arreglo de ptr usando un for 
        for (int index = 0; index < cantidad; index++){
            // * indireccion (ptr) genera el objeto 
            cout << arrPtrVideos[index]->str() << endl;
            
            if (typeid (*arrPtrVideos[index]) = typeid(Peliculas)){
                contPeliculas++;
            }
            else if (typeid (*arrPtrVideos[index]) = typeid(Series)){
                contSeries++;
            } 
        }
        // Fuera del for desplegar los totales 
        cout << "Peliculas = " << contPeliculas << endl;
        cout << "Series = " << contSeries << endl;
    }

    /* reporteCalificacion
    Despliega la información de todas las Series y Peliculas que tienen
    la calificación indicada en el parámetro de entrada,
    al final despliega la cantidad con el siguiente mensaje (ver casos de prueba).
    Total = ##
    */
    void Polimorfismo::reporteCalificacion(double _calificacion){
        // Contador de total
        int total;

        // Inicializar contador 
        total = 0;

        for (int index = 0; index < cantidad; index++){
            // Verificar si tiene la calificacion == _calificacion
            // Apuntador se usa la flecha 
            if (arrPtrVideos[index]->getCalificacion() == _calificacion){
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }
        }
        // Desplegar total fuera del for
        cout << "Total = " <<  total << endl;
    }

    /* reporteGenero
    Despliega la información de todas las Series y Peliculas que
    tienen el genero indicado en el parámetro de entrada,
    al final despliega la cantidad que cumplió (ver casos de prueba).
    Total = ##
    */
    void Polimorfismo::reporteGenero(string _genero){
        // Contador de total
        int total = 0; 

        for (int index = 0; index < cantidad; index++) {
            // Verificar si genero == _genero
            if (arrPtrVideos[index]->getGenero() == _genero){
                cout << arrPtrVideos[index]->str() << endl;
                total++:
            }
        }
        // Desplegar total fuera del for
        cout << "Total = " <<  total << endl;
    }

    /* reportePeliculas
    Despliega la información de todas las Peliculas que existan en el arreglo,
    al final despliega la cantidad en existencia.
    Total Peliculas = ##
    En caso de que no existan peliculas debe desplegar 
    No peliculas con salto de línea al final (ver casos de prueba)
    */

    void Polimorfismo::reportePeliculas() {
        int totalPeliculas = 0;  // Contador de cantidad de películas

        for (int index = 0; index < cantidad; index++) {
            // Verifica si el video es una Pelicula
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalPeliculas++;
                }
        }
        // Verifica si hay películas en el arreglo
        if (totalPeliculas > 0) {
            // Desplegar el total fuera del for
            cout << "Total Peliculas = " << totalPeliculas << endl;
            } else {
            cout << "No peliculas" << endl;
        }
    }

    /* reporteSeries
    Despliega todas las Series que existan en el arreglo,
    al final despliega la cantidad en existencia.
    Total Series = ##
    en caso de que no existan Series debe
    desplegar No series con salto de línea al final
    */

    void Polimorfismo::reporteSeries() {
        int totalSeries = 0;  // Contador para la cantidad de series

        for (int index = 0; index < cantidad; index++) {
            // Verifica si el video es una Serie
            if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
                cout << arrPtrVideos[index]->str() << endl;
                totalSeries++;
            }
        }

        // Verifica si hay series en el arreglo
        if (totalSeries > 0) {
            // Desplegar el total fuera del for
            cout << "Total Series = " << totalSeries << endl;
            } else {
            cout << "No series" << endl;
        }
    }

    // Inicializar cantidad de videos
    cantidad= 0;
    
    // Método para leer el archivo
    void Polimorfismo::leerArchivo (string nombre){
        Serie *arrPtrSeries[50];
        Pelicula *arrPtrPeliculas[50];
        Episodio episodio;
        fstream entrada;
        string row[7];      // row - arreglo de 7 elementos de strings, para almacenar los datos de la línea del archivo ya separados
        string line, word;  // line - almacena la línea leída, y word la palabra que se saca de line
        int cantidadPeliculas = 0; // Contadores de peliculas y series, inicialmente son 0 
        int cantidadSeries = 0;
        int iR = 0, index;
        double promedio;

        entrada.open (nombre, ios::in); // Abrir archivo de entrad)

        // En caso que haya un problema para abrir el archivo, se imprime este mensaje 
        if (!entrada.is_open) {
            cerr << "Error al abrir el archivo!" << endl;
            return;
        }

        while(getline(entrada, line)) { // Lee una línea del archivo y la almacena en line
            stringstream s(line);        // usado para separar las palabras split () 
            iR = 0;                      // cada vez que inicia una nueva línea inicializar iR = 0 

            // Ciclo que extrae caracteres de s y los almacena en word hasta que se encuentra el delimitador ','
            while(getline(s, word, ',')) {
                row[iR++] = word; // Añade word al arreglo row e incrementa iR p/la prosima palabra
            } 

            // Determinar si la línea es P-Pelicula, S-Serie, E-Episodio
            if (row[0] == "P"){
                // Se crea un apuntador usando el operador new y el constructor con parámetros y se guarda en el arrPtrPelículas
                arrPtrPeliculas[cantidadPeliculas] = new Pelicula (row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
                // cout << "Pelicula" <<arrPeliculas[cantidadPeliculas] -> str() << endl;
                cantidadPeliculas++; //inc la cantidad de peliculas 
            }
            else if (row[0] == "S"){
                arrPtrSeries[cantidadSeries] = new Serie (row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
                // cout << "Serie" <<arrSeries[cantidadSeries] -> str() << endl;
                cantidadSeries++;  
            }
            else if (row[0] == "E"){
                // Calcular a que Serire le pertenece al espisodio
                index = stoi(row[1]) - 500;
                // Se agg el episodio usando el método agregaEpisodio
                // Se crea el apuntador y se convierte a objeto el operador de indirección
                arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
                // cout << "Episodio" << arrSeries[index]->str() <<endl;
            }
        }

            entrada.close(); // Cerrar el archivo 

            for (int index  = 0; index < cantidadSeries; index++){
                promedio = arrPtrSeries[index]->calculaPromedio(); // Calcula la calificación de la Serie
                arrPtrSeries[index]->setCalificacion(promedio); // Cambia la calificacionde la Serie
                arrPtrSeries[index]->calculaDuracion();      
                arrPtrVideos[cantidad++] = arrPtrSeries[index];
            }

            // Copiar los apuntadores del arrelgo de Peliculas al arreglo de apuntadores de Video
            for (int index = 0; index < cantidadPeliculas; index++){
                arrPtrVideos[cantidad++]= arrPtrPeliculas[index];
            }

            // 
            
            //for(int index = 0; index < cantidad; index++){
              //  cout << index << " " << arrPtrVideos[index]->str() << endl; // Comentar para avance 2 
                // str se ejecuta al metodo de constructor no de arreglo
            //}

            entrada.close();
        }

    

