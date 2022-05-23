#include "nodo.h"
using namespace std;
#pragma once
template <class Tareas>
class Lista {
private:
	Nodo<Tareas>* inicio;
	Nodo<Tareas>* final;
	int tamanio;
	int apuntador;
public:
	Lista() : inicio(NULL), final(NULL), tamanio(0) {}
	~Lista() {
		Nodo<Tareas>* aux = inicio;
		if (!vacia()) {
			while (inicio) {
				inicio = inicio->getSiguiente();
				delete aux;
				aux = inicio;
			}
		}
		final = NULL;
		tamanio = 0;
	}
	void agregar(Tareas informacion, Tareas valor);
	int getTamanio() const;
	bool vacia() const;
	void mostrarLista();
	void eliminarNodo(int locacion);
	void eliminarNodoInicio(int locacion);
	void eliminarNodoMedio(int locacion);
	void eliminarNodoFinal(int locacion);
	void cambiarStatus(int locacion, Tareas valor);
	Lista& operator ++() {
		tamanio++;
		return *this;
	}
	Lista operator --() {
		int eliminar;
		cout << "Posicion a eliminar:" << endl;
		cin >> eliminar;
		eliminarNodo(eliminar);
		return *this;
	}
};

