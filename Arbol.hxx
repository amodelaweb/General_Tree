#ifndef __TAD_ARBOL_HXX__
#define __TAD_ARBOL_HXX__

#include "Arbol.h"
/*========================================================================*/
template<class T>
Arbol<T>::Arbol(){
  raiz = nullptr ;
}
/*========================================================================*/
template<class T>
Arbol<T>::Arbol(T& val){
  Nodo<T> *n = new Nodo<T>(val) ;
  this->fijarRaiz(n) ;
}
/*========================================================================*/
template<class T>
bool Arbol<T>::esVacio(){
  if (raiz != nullptr){
    return false ;
  }else{
    return true ;
  }
}
/*========================================================================*/
template<class T>
Nodo<T>* Arbol<T>::obtenerRaiz(){
  return this->raiz;
}
/*========================================================================*/
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>*nraiz)
{
  this->raiz= nraiz ;
}
/*========================================================================*/
template<class T>
bool Arbol<T>::insertarNodo(T& padre , T& n ){
  if(this->raiz != nullptr)
  return this->raiz->adicionarDesc(padre ,n );
  else
  this->raiz = new Nodo<T>(n) ;

  return true ;
}
/*========================================================================*/
template<class T>
bool Arbol<T>::eliminarNodo(T& n){
  if(this->raiz->obtenerDato() != n){
    return this->raiz()->eliminarDesc(n);
  }else{
    Nodo<T>* aux = this->raiz ;
    this->raiz = this->obtenerDesc().begin();
    delete aux ;
  }
  return false ;
}
/*========================================================================*/
template<class T>
void Arbol<T>::imprimirpreOrden(){
this->raiz->imprimirpreOrden();
}

#endif
