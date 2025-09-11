#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

// Nodo genérico
template <typename T>
struct Nodo {
    T dato;
    Nodo* sig;
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
