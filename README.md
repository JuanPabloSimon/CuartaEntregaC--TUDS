# 📚 Gestión de Alumnos con Colas (C++)

Este es un proyecto estudiantil en C++ que permite gestionar alumnos utilizando **colas dinamicas (manuales)**. Se pueden registrar múltiples alumnos, visualizarlos, buscar al de mayor edad y más, todo a través de un menú interactivo por consola.

## 🚀 Funcionalidades

- Insertar alumnos en dos colas distintas.
- Mostrar los elementos de una cola **sin modificarla**.
- Obtener el alumno de mayor edad en una cola.
- Contar la cantidad de alumnos en cada cola.
- Eliminar todos los alumnos de una cola.

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
Las colas son manipuladas con punteros frente y fin.

🖥️ Uso
Compila el programa:

bash
Copiar
Editar
g++ -o alumnos main.cpp
Ejecuta:

bash
Copiar
Editar
./alumnos
Sigue las opciones del menú para gestionar los alumnos en dos colas independientes.

✅ Requisitos
Compilador C++ (por ejemplo, g++)

📌 Mejoras sugeridas
Validación de entradas.

Uso de std::string en vez de char[].

Guardar y cargar datos desde archivos.

Interfaz gráfica con Qt o SFML.
