#ifndef __TAD_NODO_H__
#define __TAD_NODO_H__
#include <iostream>
#include <list>

template<class T>

class Nodo{
protected:
	T dato ;
	std::list< Nodo<T>* > desc ;
public:
 	Nodo();
	Nodo(T& dato);
	~Nodo()= default;
	std::list< Nodo<T>* > obtenerDesc() ;
	T& obtenerDato();
	void fijarDato(T& val);
	void limpiarLista();
	bool adicionarDesc(T& padre , T& nval);
	bool eliminarDesc(T& nval );
	void imprimirpreOrden();
};

#include "Nodo.hxx"
#endif
