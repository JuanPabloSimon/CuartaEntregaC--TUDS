#include<iostream>
#include<stdlib.h>

using namespace std;

struct Alumno {
	int dni;
	char nombre[20];
	int edad;
};

struct Nodo {
	Alumno alu;
	Nodo *siguiente; 
};

// Prototipos de funciones 
void menu();
void agregarPila(Nodo *&, Alumno);
void sacarPila(Nodo *&, Alumno &);
bool pila_vacia(Nodo *);
Alumno cargarAlumno();

int seleccion_pila() {
	int seleccion;
	cout<<"Seleccione una pila:"<<endl;
	cout<<"1. Pila N°1"<<endl;
	cout<<"2. Pila N°2"<<endl;
	cout<<"Opcion: ";cin>>seleccion;
	return seleccion;
}


int main() {
	menu();
	return 0;
}

void menu() {
	int opc;
	Alumno alu;
	// Pila 1
	Nodo *pila = NULL;
	// Pila 2	
	Nodo *pila2 = NULL;
	
	
	do{
		cout<<"\t. Menu:\n"; 
		cout<<"1. Insertar un alumno a una pila"<<endl;
		cout<<"2. Mostrar todos los elementos de una pila"<<endl;
		cout<<"3. Mostrar alumno mas grande"<<endl;
		cout<<"4. Mostrar cantidad de alumnos en una pila"<<endl;
		cout<<"5. Sacar elementos de una pila"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion: ";cin>>opc;

		switch(opc) {
			case 1: {
				int selecPila = seleccion_pila();
				alu = cargarAlumno();
				if (selecPila == 1) {
					agregarPila(pila, alu);
					cout<<"Alumno agregado a la pila N°1"<<endl;
				} else if (selecPila == 2) {
					agregarPila(pila2, alu);					
					cout<<"Alumno agregado a la cola N°2"<<endl;
				} else {
					cout<<"Seleccion de pila incorrecta"<<endl;	
				}	
				break;
			}
			case 2: {
				int selecPila = seleccion_pila();
				Nodo *aux;
				if (selecPila == 1) aux = pila;
				else if (selecPila == 2) aux = pila2;
				else {
					cout<<"Seleccion de pila incorrecta"<<endl;
					break;
				}
				
				if (pila_vacia(aux)) {
					cout << "\nLa pila está vacía." << endl;
					break;
					}
					
				cout << "\nMostrando los elementos de la pila N"<<selecPila<<": "<<endl;
	
				while (aux != NULL) {
					cout << "Nombre: " << aux->alu.nombre << ", ";
					cout << "DNI: " << aux->alu.dni << ", ";
					cout << "Edad: " << aux->alu.edad << endl;
					aux = aux->siguiente;
				}
				break;
			}
			case 3: {
				int selecPila = seleccion_pila();
				Nodo *aux;
				if (selecPila == 1) aux = pila;
				else if (selecPila == 2) aux = pila2;
				else {
					cout<<"Seleccion de pila incorrecta"<<endl;	
				}
				
				if (pila_vacia(aux)) {
					cout<<"\n La píla esta vacia, no hay alumnos para comparar"<<endl;
					break;
				}
				
				Alumno alumnoMayor = aux->alu;
				aux = aux->siguiente;
				
				while(aux != NULL) {
					if (aux-> alu.edad > alumnoMayor.edad) {
						alumnoMayor = aux->alu;
					}
					aux = aux->siguiente;
				}
				
				cout<<"\n El alumno de la fila N"<<selecPila<<" con mayor edad es: "<<alumnoMayor.nombre<<", y tiene: "<<alumnoMayor.edad<<" años."<<endl;
				break;
			}
			case 4: {
				int selecPila = seleccion_pila();
				Nodo *aux;
				
				if(selecPila == 1) aux = pila;
				else if (selecPila == 2) aux = pila2;
				else {
					cout<<"Seleccion de pila incorrecta"<<endl;	
					break;
				}	
				int contador = 0;
				while(aux != NULL) {
					contador++;
					aux = aux->siguiente;
				}
				cout<<"La cantidad de alumnos en la pila N1 es de: "<<contador<<endl;
				break;
			}
			case 5: {
				int selecPila = seleccion_pila();
				if (selecPila == 1) {
					if (pila_vacia(pila)) {
						cout<<"\n La pila esta vacia, no hay alumnos."<<endl;
						break;
					}
					cout<<"\Sacando los elementos de la pila N°1:";
					while(pila != NULL) {
						sacarPila(pila, alu);
						
						if(pila != NULL) {
							cout<<alu.nombre<<" , ";
						}
						else {
							cout<<alu.nombre<<"."<<endl;
						}
					};
					break;
				} else if (selecPila == 2) {
					if (pila_vacia(pila2)) {
						cout<<"\n La pila esta vacia, no hay alumnos."<<endl;
						break;
					}
					cout<<"\Sacando los elementos de la pila N°2:";
					while(pila2 != NULL) {
						sacarPila(pila2, alu);
						
						if(pila2 != NULL) {
							cout<<alu.nombre<<" , ";
						}
						else {
							cout<<alu.nombre<<"."<<endl;
						}
					};
					break;
				} else {
					cout<<"Seleccion de pila incorrecta"<<endl;	
				}	
				break;
			}
			case 6:
				break;
		}
	}while(opc != 6);
};


// Insertar elementos en la pila
void agregarPila(Nodo *&pila, Alumno n) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->alu = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\nElemento: "<<n.nombre<<" agregado a la Pila correctamente"<<endl;
};


// Eliminar elementos de la pila
void sacarPila(Nodo *&pila, Alumno &n) {
	Nodo *aux = pila;
	n = aux->alu;
	pila = aux->siguiente;
	delete aux;
};

// Determinar si la cola esta vacía
bool pila_vacia(Nodo *pila) {
	return (pila == NULL)? true : false;
};


Alumno cargarAlumno() {
	Alumno *nuevo = new Alumno();
	
	cout<<"\nIngrese el nombre del alumno: "<<endl;
	cin>>nuevo->nombre;
	cout<<"\nIngrese el documento del alumno (sin puntos ni espacios): "<<endl;
	cin>>nuevo->dni;
	cout<<"\nIngrese la edad del alumno: "<<endl;
	cin>>nuevo->edad;
	
	return *nuevo;
};
