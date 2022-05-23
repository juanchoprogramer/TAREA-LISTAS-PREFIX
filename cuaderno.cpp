#include <iostream>
#include <string>
using namespace std;
#include "cuaderno.h"
//agregar-eliminar-ver-marcar como completado
Cuaderno :: Cuaderno(){
    id=1;
    ciclo=1;
    vuelta=0;
    opcion=1;
    texto="";
    nivel="";
    eliminar=0;
}
void Cuaderno :: mostrarCuaderno(){
    Lista<string> Prueba;
    cout<<"numero de cuaderno:"<<id<<endl;
            texto="a";
            nivel="a";
            Prueba.agregar(texto,nivel);
            texto="b";
            nivel="b";
            Prueba.agregar(texto,nivel);
            texto="c";
            nivel="c";
            Prueba.agregar(texto,nivel);
            texto="d";
            nivel="d";
            Prueba.agregar(texto,nivel);
            texto="|e";
            nivel="e";
            Prueba.agregar(texto,nivel);
            texto="f";
            nivel="f";
            Prueba.agregar(texto,nivel);
    while(ciclo!=0){
        cout<<"1.-AGREGAR\n2.-MOSTRAR\n3.-ELIMINAR\n4.-COMPLETAR"<<endl;
        cin>>opcion;
        switch(opcion){
        case 1:
            cout<<"Agregar"<<endl;
            setTexto();
            Prueba.agregar(texto,nivel);
			//++Prueba;
        break;
        case 2:
            cout<<"Mostrar"<<endl;
            cout << "\nTotal de notas: " << Prueba.getTamanio() << endl;
            Prueba.mostrarLista();
        break;
        case 3:
            Prueba.agregar(texto,nivel);
            cout<<"Eliminar"<<endl;
            cout<<"Posicion a eliminar:"<<endl;
            cin>>eliminar;
            Prueba.eliminarNodo(eliminar);
			
			//--Prueba;
        break;
        case 4:
            cout<<"Completar"<<endl;
            cin.ignore();
            cout<<"Estatus a ingresar:";
            getline(cin, nivel);
            cout<<"Posicion a modificar:"<<endl;
            cin>>eliminar;
            Prueba.cambiarStatus(eliminar,nivel);
        break;
        default:
            cout<<"Opcion invalida"<<endl;
    }
        cout<<"0 Salir 1 Continuar"<<endl;
        cin>>ciclo;
    }
}
void Cuaderno :: setTexto(){
    cin.ignore();
    cout<<"Nota a ingresar:";
    getline(cin, texto);
    cout<<"Estatus a ingresar:";
    getline(cin, nivel);
    
}