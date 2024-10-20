#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<stdlib.h> // atoi
#include<unistd.h> // sleep

using namespace std;

mutex mtx;

//Funcion que representa la carrera de un auto
void grandprix(int id, int m, int* dist_reco){
    int vel= rand() % 10 + 1; //Velocidad 
    dist_reco += vel;

    if (*dist_reco > m)
    {
        *dist_reco = m;
    }
    
        lock_guard<mutex> lock(mtx); //Protege la salida de la terminal
        cout << "Automovil" << id << " avanza " << vel << " metros (total: " << dist_reco << " metros)" << endl;
    

    this_thread::sleep_for(chrono::milliseconds(100 + rand() % 400));//Espera en la pantalla
}



int main(){

    int m,n; // Tamaño de la pista y cantidad de automoviles

// Se obtiene tamaño de la pista y cantidad de automoviles
    cout << "Ingrese tamaño de la pista " << endl;
    cin >> m;


    cout << "Ingrese la cantidad de automoviles en la carrera: " << endl;
    cin >> n;

srand(static_cast<unsigned int>(time(0)));
vector<thread> hilos;
vector<int*> recorrido(n); // Distancia recorrida de cada auto con punteros

//Arreglo de punteros
    for (int i = 0; i < n; ++i) {
        recorrido[i] = new int(0); 
    }

//Crear y correr las hebras para la carrera *Funcion*
for (int i = 0; i < n; i++) {
    //Emplace back (?)
    hilos.emplace_back(grandprix, i, m, (recorrido[i]));
}

//Libera la memoria
    for (int i = 0; i < n; ++i) {
        delete recorrido[i]; 
    }

    return 0;

}