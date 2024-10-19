#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<stdlib.h> // atoi
#include<unistd.h> // sleep

/*

***** PRUEBA *****

*/

using namespace std;

mutex mtx;

void fill_vector(vector<int>& vec, int start, int end) {
    for (int i = start; i < end; ++i) {
        // Sección crítica protegida por un mutex
        lock_guard<mutex> lock(mtx);
        vec[i] = i;
    }
}

int main(){

    int n; // tamano del vector

    cout << "Ingrese tamano del vector pista: " << endl;
    cin >> n;

    int automovil; // numero de hilos

    cout << "Ingrese la cantidad de hilos autos: " << endl;
    cin >> automovil;

    vector<int> vec(n);
    vector<thread> threads;

    int chunk_size = n / automovil;

    // Crear los hilos y asignarles la parte del trabajo
    for (int i = 0; i < automovil; ++i) {
        int start = i * chunk_size;
        int end = (i == automovil - 1) ? n : start + chunk_size;
        threads.emplace_back(fill_vector, ref(vec), start, end);
    }

    return 0;

}