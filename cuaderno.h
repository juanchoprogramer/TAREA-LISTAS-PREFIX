#include "lista.h"
#pragma once
class Cuaderno {
protected:
	int id;
	int ciclo;
	int vuelta;
	int opcion;
	int eliminar;
	string texto;
	string nivel;
public:
	Cuaderno();
	void mostrarCuaderno();
	void setTexto();
};