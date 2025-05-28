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
void insertarCola(Nodo *&,Nodo *&,Alumno);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&, Nodo *&, Alumno &);
Alumno cargarAlumno();

int seleccion_cola() {
	int seleccion;
	cout<<"Seleccione una cola:"<<endl;
	cout<<"1. Cola N°1"<<endl;
	cout<<"2. Cola N°2"<<endl;
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
	// Cola 1
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	// Cola 2	
	Nodo *frente2 = NULL;
	Nodo *fin2 = NULL;
	
	
	do{
		cout<<"\t. Menu:\n";
		cout<<"1. Insertar un alumno a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de una cola"<<endl;
		cout<<"3. Mostrar alumno mas grande"<<endl;
		cout<<"4. Mostrar cantidad de alumnos en una cola"<<endl;
		cout<<"5. Sacar elementos de una cola"<<endl;
		cout<<"6. Salir"<<endl;
		cout<<"Opcion: ";cin>>opc;

		switch(opc) {
			case 1: {
				int cola = seleccion_cola();
				alu = cargarAlumno();
				if (cola == 1) {
					insertarCola(frente, fin, alu);	
					cout<<"Alumno agregado a la cola N°1"<<endl;
				} else if (cola == 2) {
					insertarCola(frente2, fin2, alu);
					cout<<"Alumno agregado a la cola N°2"<<endl;
				} else {
					cout<<"Seleccion de cola incorrecta"<<endl;	
				}	
				break;
			}
			case 2: {
				int cola = seleccion_cola();
				
				if (cola == 1) {
					if (cola_vacia(frente)) {
					cout << "\nLa cola está vacía." << endl;
					break;
					}

					cout << "\nMostrando los elementos de la cola N°1:\n";
	
					Nodo *aux = frente;
					while (aux != NULL) {
						cout << "Nombre: " << aux->alu.nombre << ", ";
						cout << "DNI: " << aux->alu.dni << ", ";
						cout << "Edad: " << aux->alu.edad << endl;
						aux = aux->siguiente;
					}
					break;
				} else if (cola == 2) {
					if (cola_vacia(frente2)) {
					cout << "\nLa cola está vacía." << endl;
					break;
					}

					cout << "\nMostrando los elementos de la cola N°2:\n";
	
					Nodo *aux = frente2;
					while (aux != NULL) {
						cout << "Nombre: " << aux->alu.nombre << ", ";
						cout << "DNI: " << aux->alu.dni << ", ";
						cout << "Edad: " << aux->alu.edad << endl;
						aux = aux->siguiente;
					}
					break;
				} else {
					cout<<"Seleccion de cola incorrecta"<<endl;	
				}	
				
				
			}
			case 3: {
				int cola = seleccion_cola();
				if (cola == 1) {
					Nodo *auxFrente = frente;
					Nodo *auxFin = fin;
					
					if (cola_vacia(auxFrente)) {
						cout<<"\n La cola esta vacia, no hay alumnos para comparar";
						break;
					}
					
					Alumno alumnoMayor = auxFrente->alu;
					auxFrente = auxFrente->siguiente;
					
					while(auxFrente != NULL) {
						if (auxFrente-> alu.edad > alumnoMayor.edad) {
							alumnoMayor = auxFrente->alu;
						}
						auxFrente = auxFrente->siguiente;
					}
					
					cout<<"\n El alumno de la cola N°1 con mayor edad es: "<<alumnoMayor.nombre<<", y tiene: "<<alumnoMayor.edad<<" años."<<endl;
					break;
				} else if (cola == 2) {
					Nodo *auxFrente = frente2;
					Nodo *auxFin = fin2;
					
					if (cola_vacia(auxFrente)) {
						cout<<"\n La cola esta vacia, no hay alumnos para comparar";
						break;
					}
					
					Alumno alumnoMayor = auxFrente->alu;
					auxFrente = auxFrente->siguiente;
					
					while(auxFrente != NULL) {
						if (auxFrente-> alu.edad > alumnoMayor.edad) {
							alumnoMayor = auxFrente->alu;
						}
						auxFrente = auxFrente->siguiente;
					}
					
					cout<<"\n El alumno de la cola N°2 con mayor edad es: "<<alumnoMayor.nombre<<", y tiene: "<<alumnoMayor.edad<<" años."<<endl;
					break;
				} else {
					cout<<"Seleccion de cola incorrecta"<<endl;	
				}
			}
				break;
			case 4: {
				int cola = seleccion_cola();
				if (cola == 1) {
					if (cola_vacia(frente)) {
						cout<<"\n La cola esta vacia, no hay alumnos.";
						break;
					}
					Nodo *aux = frente;
					int contador = 0;
					while(aux != NULL) {
						contador++;
						aux = aux->siguiente;
					}
					cout<<"La cantidad de alumnos en la cola N1 es de: "<<contador<<endl;
				} else if (cola == 2) {
					if (cola_vacia(frente2)) {
						cout<<"\n La cola esta vacia, no hay alumnos.";
						break;
					}
					Nodo *aux = frente2;
					int contador = 0;
					while(aux != NULL) {
						contador++;
						aux = aux->siguiente;
					}
					cout<<"La cantidad de alumnos en la cola N2 es de: "<<contador<<endl;
				} else {
					cout<<"Seleccion de cola incorrecta"<<endl;	
				}	
				break;
			}
			case 5: {
				int cola = seleccion_cola();
				if (cola == 1) {
					cout<<"\Sacando los elementos de la cola N°1:";
					while(frente != NULL) {
						suprimirCola(frente,fin,alu);
						
						if(frente != NULL) {
							cout<<alu.nombre<<" , ";
						}
						else {
							cout<<alu.nombre<<"."<<endl;
						}
					};
					break;
				} else if (cola == 2) {
					cout<<"\Sacando los elementos de la cola N°2:";
					while(frente2 != NULL) {
						suprimirCola(frente2,fin2,alu);
						
						if(frente2 != NULL) {
							cout<<alu.nombre<<" , ";
						}
						else {
							cout<<alu.nombre<<"."<<endl;
						}
					};
					break;
				} else {
					cout<<"Seleccion de cola incorrecta"<<endl;	
				}	
				break;
			}
			case 6:
				break;
				
		}

	}while(opc != 6);
};

// Seleccion de cola 


// Insertar elementos en la cola
void insertarCola(Nodo *&frente, Nodo *&fin, Alumno n) {
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->alu = n;
	nuevo_nodo-> siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	} else {
		fin->siguiente = nuevo_nodo;
	}
	
	fin = nuevo_nodo;
};

// Determinar si la cola esta vacía
bool cola_vacia(Nodo *frente) {
	return (frente == NULL)? true : false;
};

// Eliminar/Mostrar elementos de la cola
void suprimirCola(Nodo *&frente, Nodo *&fin, Alumno &n) {
	n = frente-> alu;
	Nodo *aux = frente;
	
	if(frente == fin) {
		frente = NULL;
		fin = NULL;
	} else {
		frente = frente->siguiente;
	}
	delete aux;	
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
