#ifndef __TAD_ARBOL_H__
#define __TAD_ARBOL_H__
#include <iostream>
#include <list>
#include "Nodo.h"
template<class T>

class Arbol{
protected:
	Nodo<T>* raiz;
public:
 	Arbol();
	Arbol(T& val);
	~Arbol() = default;
	bool esVacio();
	Nodo<T>* obtenerRaiz();
	void fijarRaiz(Nodo<T>* nraiz);
	bool insertarNodo(T& padre , T& n);
	bool eliminarNodo(T& n) ;
	void imprimirpreOrden() ;
};

#include "Arbol.hxx"
#endif
