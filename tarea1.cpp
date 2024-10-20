#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<cstdlib>
#include<ctime>
#include<chrono>
#include<stdlib.h> // atoi

using namespace std;

mutex mtx;

//Funcion que representa la carrera de un auto
void grandprix(int id, int m, int* dist_reco, vector<int>*llegada){

    while(*dist_reco < m){

        int vel= rand() % 10 + 1; //Velocidad 
        *dist_reco += vel;

        if (*dist_reco > m){

            *dist_reco = m;

        }
        
        {
            lock_guard<mutex> lock(mtx); //Protege la salida de la terminal
            cout << "Auto" << id << " avanza " << vel << " metros (total: " << *dist_reco << " metros)" << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 400));//Espera en la pantalla

    }

    
    {
        lock_guard<mutex> lock(mtx); //Protege la salida de la terminal
        cout << "Auto" << id << " terminó la carrera!!!" << endl;
        llegada->push_back(id);
    }

    
}



int main(int argc, char* argv[]){

    if(argc != 3) cerr << "Tienes que ingresar <distancia> <cantidad_autos>" << endl;

    int m = stoi(argv[1]); // Tamaño de la pista
    int n = stoi(argv[2]); // Cantidad de automoviles

    // Validación de la distancia y cantidad de autos
    if (n < 2) cerr << "La cantidad de autos debe ser mayor o igual a 2" << endl;
    if (m < 50) cerr << "La distancia de la pista debe ser mayor o igual a 50 metros" << endl;

    srand(static_cast<unsigned int>(time(0))); // se activa la funcion de aleatoriedad
    vector<thread> hilos;
    vector<int*> recorrido(n); // Distancia recorrida de cada auto con punteros
    vector<int> llegada;

    //Arreglo de punteros
    for (int i = 0; i < n; ++i) {
        recorrido[i] = new int(0); 
    }

    cout << "Distancia total carrera: " << m << " metros" << endl;
    cout << "___________________________________" << endl;

    //Crear y correr las hebras para la carrera *Funcion*
    for (int i = 0; i < n; i++) {
        hilos.emplace_back(grandprix, i+1, m, (recorrido[i]), &llegada);
    }

    for (auto& hilo : hilos) { // el hilo se iterá así mismo para confirmar si terminó o no su proceso
        if (hilo.joinable()) {
            hilo.join(); // se utiliza para unir el hilo actual con el hilo principal
        }
    }

    //Libera la memoria
    for (int i = 0; i < n; ++i) {
        delete recorrido[i]; 
    }

    cout << "\nLa carrera ha terminado!" << endl;
    cout << "Lugar       Auto" << endl;
    cout << "________________" << endl;
    for (size_t i = 0; i < llegada.size(); ++i) {
        cout << (i + 1) << "           Auto" << llegada[i] << endl;
    }

    return 0;

}
