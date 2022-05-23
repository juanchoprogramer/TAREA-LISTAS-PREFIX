#include <iostream>
#include <string>
#include "lista.h"
using namespace std;
template <class Tareas>
void Lista<Tareas>::agregar(Tareas informacion, Tareas valor) {
	Nodo<Tareas>* aux = new Nodo<Tareas>(informacion, valor);
	if (vacia()) {
		inicio = aux;
	}
	else {
		final->setSiguiente(aux);
	}
	final = aux;
	tamanio++;
}
template <class Tareas>
int Lista<Tareas>::getTamanio() const {
	return tamanio;
}
template <class Tareas>
bool Lista<Tareas>::vacia() const {
	return (inicio == NULL);
}
template <class Tareas>
void Lista<Tareas>::mostrarLista() {
	Nodo<Tareas>* aux = inicio->getSiguiente();
	apuntador = 1;
	cout << "Tarea:" << inicio->getDatos() << endl;
	cout << "Estatus:" << inicio->getEstatus() << endl;
	while (aux) {
		cout << apuntador << " " << tamanio << endl;
		cout << "Tarea:" << aux->getDatos() << endl;
		cout << "Estatus:" << aux->getEstatus() << endl;
		aux = aux->getSiguiente();
		apuntador++;
		if (apuntador == tamanio) {
			return;
		}
	}
}
template <class Tareas>
void Lista<Tareas>::eliminarNodo(int locacion) {
	Nodo<Tareas>* aux = inicio->getSiguiente();
	Nodo<Tareas>* anterior = inicio;
	Nodo<Tareas>* ultimo = inicio;
	apuntador = 1;
	if (!vacia()) {
		if (locacion == 1) {
			eliminarNodoInicio(locacion);
		}
		else if (locacion == tamanio - 1) {
			eliminarNodoFinal(locacion);
		}
		else if (locacion >= tamanio) {
			cout << "Posicion no existe" << endl;
		}
		else eliminarNodoMedio(locacion);
	}
	else cout << "Agrega una nota antes de eliminar" << endl;
}
template <class Tareas>
void Lista<Tareas>::eliminarNodoInicio(int locacion) {
	Nodo<Tareas>* aux = inicio->getSiguiente();
	Nodo<Tareas>* anterior = inicio;
	Nodo<Tareas>* ultimo = inicio;
	cout << "llegue al principio";
	inicio = inicio->getSiguiente();
	//delete aux;
	tamanio--;
	tamanio--;
	while (ultimo) {
		if (apuntador == tamanio - 1) {
			ultimo->setSiguiente(ultimo->getSiguiente());
			return;
		}
		apuntador++;
		ultimo = ultimo->getSiguiente();
	}
}
template <class Tareas>
void Lista<Tareas>::eliminarNodoMedio(int locacion) {
	Nodo<Tareas>* aux = inicio->getSiguiente();
	Nodo<Tareas>* anterior = inicio;
	Nodo<Tareas>* ultimo = inicio;
	apuntador = 1;
	while (aux) {
		if (apuntador == locacion - 1) {
			anterior->setSiguiente(aux->getSiguiente());
			delete aux;
			tamanio--;
			tamanio--;
			while (ultimo) {
				if (apuntador == tamanio - 1) {
					ultimo->setSiguiente(final);
					return;
				}
				apuntador++;
				ultimo = ultimo->getSiguiente();
			}
		}
		aux = aux->getSiguiente();
		anterior = anterior->getSiguiente();
		ultimo = ultimo->getSiguiente();
		apuntador++;
	}
}
template <class Tareas>
void Lista<Tareas>::eliminarNodoFinal(int locacion) {
	Nodo<Tareas>* aux = inicio->getSiguiente();
	Nodo<Tareas>* anterior = inicio;
	Nodo<Tareas>* ultimo = inicio;
	apuntador = 1;
	while (aux) {
		if (locacion == tamanio - 1) {
			cout << "llegue al final";
			while (ultimo) {
				if (apuntador == tamanio - 3) {
					final = ultimo->getSiguiente();
					cout << apuntador << " " << tamanio << endl;
					cout << "Tarea:" << ultimo->getDatos() << endl;
					cout << "Estatus:" << ultimo->getEstatus() << endl;
					ultimo->setSiguiente(final);
					tamanio--;
					tamanio--;
					return;
				}
				apuntador++;
				ultimo = ultimo->getSiguiente();
				anterior = anterior->getSiguiente();
			}

		}
		aux = aux->getSiguiente();
		anterior = anterior->getSiguiente();
		ultimo = ultimo->getSiguiente();
		apuntador++;
	}
}
template <class Tareas>
void Lista<Tareas>::cambiarStatus(int locacion, Tareas valor) {
	Nodo<Tareas>* status = inicio;
	apuntador = 1;
	if (vacia()) {
		cout << "Agrega una nota antes de eliminar" << endl;
	}
	else {
		while (status) {
			if (apuntador == locacion) {
				status->setEstatus(valor);
			}
			status = status->getSiguiente();
			apuntador++;
		}
	}
}
template class Lista<int>;
template class Lista<char>;
template class Lista<string>;