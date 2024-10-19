# Variables
CXX = g++                   # Compilador C++
CXXFLAGS = -Wall -std=c++11 # Opciones del compilador (sin el "g++")
TARGET = tarea1             # Nombre del archivo ejecutable
SRCS = tarea1.cpp           # Archivos fuente

# Regla principal
all: $(TARGET)              # La regla 'all' se ejecuta por defecto

# Enlazar los archivos fuente para crear el ejecutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Limpiar los archivos compilados
clean:
	rm -f $(TARGET)

