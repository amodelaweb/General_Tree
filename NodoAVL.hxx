#ifndef __NodoAVL__HXX__
#define __NodoAVL__HXX__
#include "NodoAVL.h"
#include <queue>
template <class T>
NodoAVL<T>::NodoAVL(){
  this->dato=nullptr;
  this->izq=nullptr;
  this->der=nullptr;
}
template <class T>
NodoAVL<T>::NodoAVL(T& val){
  this->dato=val;
  this->izq=nullptr;
  this->der=nullptr;
}
template <class T>
NodoAVL<T>::NodoAVL(T& val,NodoAVL<T> *izq,NodoAVL<T> *der){
  this->dato=val;
  this->izq=izq;
  this->der=der;
}
template <class T>
T& NodoAVL<T>::obtenerDato(){
  return this->dato;
}
template <class T>
void NodoAVL<T>::fijarDato(T& ndato){
  this->dato=ndato;
}
template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq(){
  return this->izq;
}
template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer(){
  return this->der;
}
template <class T>
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T>*izq){
  this->izq=izq;
}
template <class T>
void NodoAVL<T>::fijarHijoDer(NodoAVL<T>*der){
  this->der=der;
}
template <class T>
void NodoAVL<T>::preOrden(){
  std::cout<<this->dato<<" ";
  if(this->izq!=nullptr)
  this->izq->preOrden();
  if(this->der!=nullptr)
  this->der->preOrden();
}
template <class T>
void NodoAVL<T>::inOrden(){
  if(this->izq!=nullptr)
  this->izq->inOrden();
  std::cout<<" "<<dato<<" ";
  if(this->der!=nullptr)
  this->der->inOrden();
}
template <class T>
void NodoAVL<T>::posOrden(){
  if(this->izq!=nullptr)
  this->izq->inOrden();
  if(this->der!=nullptr)
  this->der->inOrden();
  std::cout<<dato<<" ";
}
template <class T>
int NodoAVL<T>::altura(){
  int cont=0;
  int h1=0,h2=0;
  if(this->izq==nullptr && this->der==nullptr){
    return cont;
  }else{
  if(this->izq==nullptr){
    h2=this->der->altura();
    cont=cont+h2;
  }else if(this->der==nullptr){
    h1=this->izq->altura();
    cont=cont+h1;
  }else{
    h1=this->izq->altura();
    h2=this->der->altura();
    if(h1>h2){
     cont=cont+h1;
   }else if(h2>h1){
     cont=cont+h2;
   }else{
     cont=cont+h1;
   }
  }
  return cont+1;
}
}
template <class T>
int NodoAVL<T>::tamano(){
  int tam=1;
  if(this->izq!=nullptr){
    tam=tam+this->izq->tamano();
  }
  if(this->der!=nullptr){
    tam=tam+this->der->tamano();
  }
  return tam;
}
template <class T>
bool NodoAVL<T>::buscarNodo(T& dato){
  if(this->dato==dato){
    return true;
  }else{
    if(this->dato>dato){
      return this->izq->buscarNodo(dato);
    }else{
      return this->der->buscarNodo(dato);
    }
  }
}
template <class T>
bool NodoAVL<T>::insertarNodo(T& dato){
  if(dato<this->dato){
    if(this->izq!=nullptr){
      return this->izq->insertarNodo(dato);
    }else{
      this->izq=new NodoAVL<T>(dato);
      return true;
    }
  }
  if(dato>this->dato){
    if(this->der!=nullptr){
      return this->der->insertarNodo(dato);
    }else{
      this->der=new NodoAVL<T>(dato);
      return true;
    }
  }else{
    return false;
  }
}
template <class T>
bool NodoAVL<T>::eliminarNodo(NodoAVL<T> *padre,T& dato){
  if(dato<this->dato){
    return this->obtenerHijoIzq()->eliminarNodo(this,dato);
  }else if(dato>this->dato){
    return this->obtenerHijoDer()->eliminarNodo(this,dato);
  }else{
    if(this->izq==nullptr && this->der==nullptr){
      if(padre->obtenerHijoDer()->obtenerDato()==dato)
        padre->fijarHijoDer(nullptr);
      else if(padre->obtenerHijoIzq()->obtenerDato()==dato)
        padre->fijarHijoIzq(nullptr);
      delete (this);
      return true;
    }else if(this->izq==nullptr){
      padre->fijarHijoDer(this->obtenerHijoDer());
      delete(this);
      return true;
    }else if(this->der==nullptr){
      padre->fijarHijoIzq(this->obtenerHijoIzq());
      delete(this);
      return true;
    }else{
      NodoAVL<T>* min= this->der->minimo();
      this->fijarDato(min->obtenerDato());
      return this->obtenerHijoDer()->eliminarNodo(this,min->obtenerDato());
    }
  }
  return false;
}
template <class T>
NodoAVL<T>* NodoAVL<T>::rotDer(NodoAVL<T>* padre){
  NodoAVL<T>* n_padre;
  n_padre= padre->obtenerHijoIzq();
  padre->fijarHijoIzq(n_padre->obtenerHijoDer());
  n_padre->fijarHijoDer(padre);
  return padre;
}
template <class T>
NodoAVL<T>* NodoAVL<T>::rotIzq(NodoAVL<T>* padre){
  NodoAVL<T>* n_padre;
  n_padre= padre->obtenerHijoDer();
  padre->fijarHijoDer(n_padre->obtenerHijoIzq());
  n_padre->fijarHijoIzq(padre);
  return padre;
}
template <class T>
NodoAVL<T>* NodoAVL<T>::minimo(){
  if(this->izq==nullptr){
    return this;
  }else{
    return this->izq->minimo();
  }
}
template <class T>
NodoAVL<T>* NodoAVL<T>::maximo(){
  if(this->der==nullptr){
    return this;
  }else{
    return this->der->maximo();
  }
}
#endif
