#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<stdlib.h> // atoi
#include<unistd.h> // sleep

using namespace std;

mutex mtx;//Para sincronizar la salida a la terminal

//Funciones



int main(){

    int m,automoviles; // Tamaño de la pista y cantidad de automoviles

// Se obtiene tamaño de la pista y cantidad de automoviles
    cout << "Ingrese tamaño de la pista " << endl;
    cin >> m;


    cout << "Ingrese la cantidad de automoviles en la carrera: " << endl;
    cin >> automoviles;

vector<thread> hilos;
vector<int> vec(m, 0); // Distancia recorrida


//Crear y correr las hebras para la carrera *Funcion*
for (int i = 0; i < automoviles; i++) {
    cout << "Creando hilo " << i << endl; 
}

    return 0;

}