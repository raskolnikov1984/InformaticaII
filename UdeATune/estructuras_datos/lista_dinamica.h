#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <iostream>
#include <stdexcept>

template<typename T>
class ListaDinamica {
private:
    T* data;           // Puntero al array de elementos
    size_t capacidad;  // Capacidad total del vector
    size_t tamaño;     // Número actual de elementos

    // Método para redimensionar la capacidad interna
    void redimensionarCapacidad(size_t nueva_capacidad) {
        if (nueva_capacidad == 0) {
            // Liberar memoria si la nueva capacidad es 0
            if (data != nullptr) {
                delete[] data;
                data = nullptr;
            }
            capacidad = 0;
            tamaño = 0;
            return;
        }

        T* new_data = new T[nueva_capacidad];

        // Copiar elementos existentes solo si hay elementos
        if (data != nullptr && tamaño > 0) {
            size_t elementos_a_copiar = (tamaño < nueva_capacidad) ? tamaño : nueva_capacidad;
            for (size_t i = 0; i < elementos_a_copiar; ++i) {
                new_data[i] = data[i];
            }
        }

        // Liberar memoria antigua
        if (data != nullptr) {
            delete[] data;
        }

        data = new_data;
        capacidad = nueva_capacidad;

        // Ajustar tamaño si es necesario
        if (tamaño > capacidad) {
            tamaño = capacidad;
        }
    }

public:
    // Constructor por defecto
    ListaDinamica() : data(nullptr), capacidad(0), tamaño(0) {}

    // Constructor con capacidad inicial
    explicit ListaDinamica(size_t capacidad_inicial) : data(nullptr), capacidad(capacidad_inicial), tamaño(0) {
        if (capacidad_inicial > 0) {
            data = new T[capacidad_inicial];
        }
    }

    // Constructor de copia
    ListaDinamica(const ListaDinamica& other) : data(nullptr), capacidad(0), tamaño(0) {
        if (other.tamaño > 0) {
            // Alocar memoria directamente
            data = new T[other.capacidad];
            capacidad = other.capacidad;
            tamaño = other.tamaño;
            // Copiar los elementos
            for (size_t i = 0; i < tamaño; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    // Operador de asignación (usando copy-and-swap idiom)
    ListaDinamica& operator=(const ListaDinamica& other) {
        if (this != &other) {
            // Crear una copia temporal
            ListaDinamica temp(other);
            // Intercambiar con this
            intercambiar(temp);
        }
        return *this;
    }

    // Move constructor
    ListaDinamica(ListaDinamica&& other) noexcept
        : data(other.data), capacidad(other.capacidad), tamaño(other.tamaño) {
        other.data = nullptr;
        other.capacidad = 0;
        other.tamaño = 0;
    }

    // Move assignment operator
    ListaDinamica& operator=(ListaDinamica&& other) noexcept {
        if (this != &other) {
            // Liberar memoria actual
            if (data != nullptr) {
                delete[] data;
            }
            // Tomar ownership
            data = other.data;
            capacidad = other.capacidad;
            tamaño = other.tamaño;
            // Reset other
            other.data = nullptr;
            other.capacidad = 0;
            other.tamaño = 0;
        }
        return *this;
    }

    // Destructor
    ~ListaDinamica() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    // Agregar elemento al final
    void agregar(const T& value) {
        if (tamaño >= capacidad) {
            // Redimensionar con crecimiento exponencial
            size_t nueva_capacidad = (capacidad == 0) ? 1 : capacidad * 2;
            redimensionarCapacidad(nueva_capacidad);
        }
        data[tamaño++] = value;
    }

    // Insertar elemento en posición específica
    void insertar(size_t indice, const T& valor) {
        if (indice > tamaño) {
            throw std::out_of_range("Índice fuera de rango");
        }

        if (tamaño >= capacidad) {
            size_t nueva_capacidad = (capacidad == 0) ? 1 : capacidad * 2;
            redimensionarCapacidad(nueva_capacidad);
        }

        // Desplazar elementos a la derecha
        for (size_t i = tamaño; i > indice; --i) {
            data[i] = data[i - 1];
        }

        data[indice] = valor;
        ++tamaño;
    }

    // Eliminar elemento del final
    void eliminarUltimo() {
        if (tamaño > 0) {
            --tamaño;
        }
    }

    // Eliminar elemento en posición específica
    void eliminar(size_t indice) {
        if (indice >= tamaño) {
            throw std::out_of_range("Índice fuera de rango");
        }

        // Desplazar elementos a la izquierda
        for (size_t i = indice; i < tamaño - 1; ++i) {
            data[i] = data[i + 1];
        }
        --tamaño;
    }

    // Acceder a elemento (con verificación de límites)
    T& obtener(size_t indice) {
        if (indice >= tamaño) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return data[indice];
    }

    const T& obtener(size_t indice) const {
        if (indice >= tamaño) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return data[indice];
    }

    // Acceder a elemento (sin verificación)
    T& operator[](size_t indice) {
        return data[indice];
    }

    // Acceso constante
    const T& operator[](size_t indice) const {
        return data[indice];
    }

    // Obtener primer elemento
    T& primero() {
        if (tamaño == 0) throw std::out_of_range("Lista vacía");
        return data[0];
    }

    const T& primero() const {
        if (tamaño == 0) throw std::out_of_range("Lista vacía");
        return data[0];
    }

    // Obtener último elemento
    T& ultimo() {
        if (tamaño == 0) throw std::out_of_range("Lista vacía");
        return data[tamaño - 1];
    }

    const T& ultimo() const {
        if (tamaño == 0) throw std::out_of_range("Lista vacía");
        return data[tamaño - 1];
    }

    // Redimensionar el tamaño de la lista (cambia el número de elementos)
    void redimensionar(size_t nuevo_tamaño, const T& valor = T()) {
        if (nuevo_tamaño > capacidad) {
            redimensionarCapacidad(nuevo_tamaño);
        }

        if (nuevo_tamaño > tamaño) {
            // Inicializar nuevos elementos con el valor por defecto
            for (size_t i = tamaño; i < nuevo_tamaño; ++i) {
                data[i] = valor;
            }
        }
        tamaño = nuevo_tamaño;
    }

    // Reservar capacidad
    void reservar(size_t nueva_capacidad) {
        if (nueva_capacidad > capacidad) {
            redimensionarCapacidad(nueva_capacidad);
        }
    }

    // Limpiar la lista
    void limpiar() {
        tamaño = 0;
    }

    // Obtener tamaño actual
    size_t obtenerTamaño() const {
        return tamaño;
    }

    // Obtener capacidad
    size_t getCapacidad() const {
        return capacidad;
    }

    // Verificar si está vacío
    bool estaVacia() const {
        return tamaño == 0;
    }

    // Intercambiar contenido con otra lista
    void intercambiar(ListaDinamica& other) {
        std::swap(data, other.data);
        std::swap(capacidad, other.capacidad);
        std::swap(tamaño, other.tamaño);
    }
};

#endif // LISTA_DINAMICA_H
