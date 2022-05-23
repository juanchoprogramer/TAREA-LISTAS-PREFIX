#include <iostream>
#include <string>
#include "nodo.h"
using namespace std;

template <class Tareas>
Nodo <Tareas> ::Nodo(Tareas informacion, Tareas valor) {
	siguiente = NULL;
	datos = new Tareas;
	*datos = informacion;
	estatus = new Tareas;
	*estatus = valor;
}
template <class Tareas>
void Nodo<Tareas>::setInformacion(Tareas informacion) {
	datos = new Tareas;
	*datos = informacion;
}
template <class Tareas>
void Nodo<Tareas>::setSiguiente(Nodo<Tareas>* s) {
	siguiente = s;
}
template <class Tareas>
void Nodo<Tareas>::setEstatus(Tareas valor) {
	estatus = new Tareas;
	*estatus = valor;
}
template <class Tareas>
const Tareas Nodo<Tareas>::getDatos() const {
	return *datos;
}
template <class Tareas>
const Tareas Nodo<Tareas>::getEstatus() const {
	return *estatus;
}
template <class Tareas>
Nodo<Tareas>* Nodo<Tareas>::getSiguiente() {
	return siguiente;
}
template class Nodo<int>;
template class Nodo<char>;
template class Nodo<string>;