#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Nodo genérico
template <typename T>
struct Nodo {
    T dato;
    Nodo* sig = nullptr;
};

// Lista enlazada genérica
template <typename T>
class LinkedList {
private:
    Nodo<T>* cabeza;
    int tam;

public:
    LinkedList() {
        cabeza = NULL;
        tam = 0;
    }

    // Obtener cabeza
    Nodo<T>* getCabeza() {
        return cabeza;
    }

    // Agregar al final
    void agregar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo->dato = valor;
        nuevo->sig = NULL;

        if (cabeza == NULL) {
            cabeza = nuevo;
        }
        else {
            Nodo<T>* aux = cabeza;
            while (aux->sig != NULL) {
                aux = aux->sig;
            }
            aux->sig = nuevo;
        }
        tam++;
    }

    // Eliminar alumno por ID (para Alumno)
    bool eliminarPorId(int id) {
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = NULL;

        while (actual != NULL) {
            if (actual->dato.id == id) {
                if (anterior == NULL) {
                    cabeza = actual->sig;
                }
                else {
                    anterior->sig = actual->sig;
                }
                delete actual;
                tam--;
                return true;
            }
            anterior = actual;
            actual = actual->sig;
        }
        return false;
    }

    // Eliminar nodo con aux y anterior
    bool eliminarNodo(Nodo<T>* aux, Nodo<T>* anterior) {
        if (aux == NULL) return false;

        if (anterior == NULL) {
            // Si es la cabeza
            cabeza = aux->sig;
        }
        else {
            anterior->sig = aux->sig;
        }

        delete aux;
        tam--;
        return true;
    }

    // Buscar alumno por ID
    T* buscarPorId(int id) {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            if (aux->dato.id == id) {
                return &aux->dato;
            }
            aux = aux->sig;
        }
        return NULL;
    }

    // Mostrar todos con operador <<
    void mostrarTodo() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            cout << aux->dato << endl;
            aux = aux->sig;
        }
    }

    // Mostrar todos usando método mostrar() (para Alumno)
    void mostrarTodos() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            aux->dato.mostrar();
            aux = aux->sig;
        }
    }

    // Mostrar todos usando método mostrar() (para Inscripcion)
    void mostrarTodosInscripciones() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            aux->dato.mostrar();  // <<--- llama a Inscripcion::mostrar()
            aux = aux->sig;
        }
    }
};

#endif // LINKEDLIST_H
