#pragma once
template <class Tareas>
class Nodo {
protected:
	Tareas* datos;
	Tareas* estatus;
	Nodo<Tareas>* siguiente;
	int apuntador;
public:
	Nodo(Tareas informacion, Tareas valor);
	Nodo() : datos(NULL), estatus(NULL), siguiente(NULL) {}
	~Nodo() {
		delete datos;
		delete estatus;
		siguiente = NULL;
	}
	void setInformacion(Tareas informacion);
	void setSiguiente(Nodo<Tareas>* s);
	void setEstatus(Tareas valor);
	const Tareas getDatos() const;
	const Tareas getEstatus() const;
	Nodo<Tareas>* getSiguiente();
};