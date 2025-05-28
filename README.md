# 📚 Gestión de Alumnos con Colas y Pilas (C++)

Este es un proyecto estudiantil en C++ que permite gestionar alumnos utilizando **colas dinamicas (manuales)** o **pilas dinámicas (manuales)**. Se pueden registrar múltiples alumnos, visualizarlos, buscar al de mayor edad y más, todo a través de un menú interactivo por consola.

## 🚀 Funcionalidades

- Insertar alumnos en dos colas o dos pilas distintas.
- Mostrar los elementos de una cola o pila **sin modificarla**.
- Obtener el alumno de mayor edad en una cola o pila.
- Contar la cantidad de alumnos en cada cola o pila.
- Eliminar todos los alumnos de una cola o pila.

## 🧱 Estructura del Código

El sistema utiliza estructuras (`struct`) para representar alumnos y nodos:

```cpp
struct Alumno {
    int dni;
    char nombre[20];
    int edad;
};

struct Nodo {
    Alumno alu;
    Nodo *siguiente;
};
Las colas y pilas son manipuladas con punteros frente y fin.
```

## 🖥️ Uso

1. Compila el programa:
### Bash
```bash
g++ -o alumnos main.cpp
```
2. Ejecuta:
### Bash
```bash
./alumnos
```
3. Sigue las opciones del menú para gestionar los alumnos en dos colas independientes.


## ✅ Requisitos

- Compilador C++ (por ejemplo, g++).
- Sistema operativo compatible con la terminal (Linux, macOS, Windows con CMD/Powershell).

## 📌 Mejoras sugeridas

- Validación de entradas.

- Uso de std::string en vez de char[].

- Guardar y cargar datos desde archivos.

- Interfaz gráfica con Qt o SFML.
