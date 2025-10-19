#ifndef LISTA_DINAMICA_H_
#define LISTA_DINAMICA_H_

#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class ListaDinamica {
private:
  T* datos;
  size_t tamano;
  size_t capacidad;

public:
  ListaDinamica();
  explicit ListaDinamica(size_t capacidad_inicial);
  ~ListaDinamica();

  T* getDatos() const;
  void setDatos(T* newDatos);
  size_t getTamano() const;
  void setTamano(size_t newTamano);
  size_t getCapacidad() const;
  void setCapacidad(size_t newCapacidad);
};


template <typename T>
ListaDinamica<T>::ListaDinamica()
  : datos(nullptr), tamano(0), capacidad(0) {}

template <typename T>
ListaDinamica<T>::ListaDinamica(size_t capacidad_inicial)
  : tamano(0), capacidad(capacidad_inicial) {
  datos = new T[capacidad];
}

template <typename T>
ListaDinamica<T>::~ListaDinamica() {
  delete[] datos;
}

template <typename T>
T* ListaDinamica<T>::getDatos() const { return datos; }

template <typename T>
void ListaDinamica<T>::setDatos(T* newDatos) { datos = newDatos; }

template <typename T>
size_t ListaDinamica<T>::getTamano() const { return tamano; }

template <typename T>
void ListaDinamica<T>::setTamano(size_t newTamano) { tamano = newTamano; }

template <typename T>
size_t ListaDinamica<T>::getCapacidad() const { return capacidad; }

template <typename T>
void ListaDinamica<T>::setCapacidad(size_t newCapacidad) { capacidad = newCapacidad; }

#endif // LISTA_DINAMICA_H_
