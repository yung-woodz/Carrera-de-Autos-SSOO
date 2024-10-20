# Carrera-de-Autos-SSOO

Este es un proyecto del ramo Sistemas Operativos de la Universidad del Bío-bío, el cual consiste en
una carrera de autos utilizando hilos en C++. Cada auto es representado por un hilo y la distancia 
puede ser definida por el usuario, al igual que la cantidad de autos (hilos) y dentro de la
carrera, la velocidad es aleatoria para cada vehículo dentro del ciclo iterátivo en el que
se desarrolla la carrera.

# Características

* Cada Auto tiene un identificador único (ej: Auto1, Auto2, etc.).
* Cada uno de los autos avanzará una cantidad aleatoria de metros en cada iteración.
* Se detendrá por un tiempo aleatorio (representando la velocidad aleatoria del auto) en cada iteración.
* La carrera se finalizará cuando todos los autos hayan terminado el recorrido.
* Al final de la carrera, se mostrará por pantalla el pódio.

# Requisitos

* Compilador GNU g++ std=c++11 o superior.
* Sistema Operativo Linux.

# Compilación y Ejecución

## Compilación Linux:

Dentro del directorio del proyecto y abriendo una terminal en este, puedes compilar fácilmente el programa con `Makefile`
que ya viene incluido en el proyecto.

```
make
```

## Ejecución:

Para ejecutar esta simulación de carreras, tienes que ingresar dos parámetros, la distancia total que tendrá la carrera y 
la cantidad de autos. Ejemplo:

```
./tarea1 100 3
```
Salida esperada (el resultado será completamente aleatorio):

```
Distancia total carrera: 100 metros
___________________________________
Auto1 avanza 8 metros (total: 8 metros)
Auto2 avanza 7 metros (total: 7 metros)
Auto3 avanza 6 metros (total: 6 metros)
...
Auto3 avanza 2 metros (total: 85 metros)
Auto1 avanza 6 metros (total: 78 metros)
Auto2 avanza 2 metros (total: 88 metros)
Auto3 avanza 1 metros (total: 86 metros)
Auto1 avanza 7 metros (total: 85 metros)
Auto2 avanza 2 metros (total: 90 metros)
Auto3 avanza 10 metros (total: 96 metros)
Auto1 avanza 8 metros (total: 93 metros)
Auto3 avanza 4 metros (total: 100 metros)
Auto3 terminó la carrera!!!
Auto2 avanza 9 metros (total: 99 metros)
Auto1 avanza 8 metros (total: 100 metros)
Auto2 avanza 3 metros (total: 100 metros)
Auto2 terminó la carrera!!!
Auto1 terminó la carrera!!!

La carrera ha terminado!
Lugar       Auto
________________
1           Auto3
2           Auto2
3           Auto1
```

# Integrantes:

Renato Chavez Molina y Dilan Toro Moraga