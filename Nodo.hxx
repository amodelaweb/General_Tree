#ifndef __TAD_NODO_HXX__
#define __TAD_NODO_HXX__
#include "Nodo.h"

/* ============================================================================ */
template<class T>
Nodo<T>::Nodo()
{

}
/* ============================================================================ */
template<class T>
Nodo<T>::Nodo(T& dato)
{
  this->dato = dato ;
}
/* ============================================================================ */
template<class T>
T& Nodo<T>::obtenerDato()
{
  return this->dato ;
}
/* ============================================================================ */
template<class T>
void Nodo<T>::fijarDato(T& val)
{
  this->dato = val ;
}
/* ============================================================================ */
template<class T>
void Nodo<T>::limpiarLista()
{
  desc.clear();
}
/* ============================================================================ */
template<class T>
bool Nodo<T>::adicionarDesc(T& padre , T& nval)
{
  bool ya = false ;
  if(this->dato != padre ){
    if(!(this->desc.empty())){
      for(typename std::list<Nodo<T>*>::iterator it = this->desc.begin() ; it != this->desc.end() && !ya ; it++){
        ya = (*it)->adicionarDesc(padre , nval);
      }
      return ya ;
    }else{
      return false ;
    }
  }
  else{
    Nodo<T> *n = new Nodo(nval) ;
    this->desc.push_back(n);
    return true ;
  }
}
/* ============================================================================ */
template<class T>
bool Nodo<T>::eliminarDesc(T& nval )
{
  bool ya = false ;
  if (!(this->desc.empty())){
    for(typename std::list<Nodo<T>*>::iterator it = this->desc.begin() ; it != this->desc.end() && !ya ; it++){
      Nodo<T>* aux = *it ;
      if(*it->obtenerDato() != nval){
        ya = *it->eliminarDesc(nval);
      }else{
        ya = true ;
        it = this->desc.erase(it);
        if(!aux->obtenerDesc().empty()){
          this->desc.push_back(aux->obtenerDesc());
        }
        delete aux ;
      }
    }
    return ya ;
  }else{
    return false ;
  }

}
template<class T>
std::list< Nodo<T>* > Nodo<T>::obtenerDesc()
{
  return this->desc ;
}
/* ===============================================================================*/
template<class T>
void Nodo<T>::imprimirpreOrden(){

  if (!(this->desc.empty()))
  {

    std::cout<<std::endl<<this->obtenerDato() ;
    for (typename std::list<Nodo<T>*>::iterator it = this->desc.begin() ; it != this->desc.end()  ; it++ ){

        (*it)->imprimirpreOrden();
    }
  }
  else{
    std::cout<<std::endl<<this->obtenerDato() ;
  }


}
#endif
