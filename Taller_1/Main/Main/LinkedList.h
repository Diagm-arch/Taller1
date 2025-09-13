#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;


template <typename T>
struct Nodo {
    T dato;
    Nodo* sig = nullptr;
};


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


    Nodo<T>* getCabeza() {
        return cabeza;
    }


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


    bool eliminarNodo(Nodo<T>* aux, Nodo<T>* anterior) {
        if (aux == NULL) return false;

        if (anterior == NULL) {
           
            cabeza = aux->sig;
        }
        else {
            anterior->sig = aux->sig;
        }

        delete aux;
        tam--;
        return true;
    }


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


    void mostrarTodo() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            cout << aux->dato << endl;
            aux = aux->sig;
        }
    }

    void mostrarTodos() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            aux->dato.mostrar();
            aux = aux->sig;
        }
    }

    void mostrarTodosInscripciones() {
        Nodo<T>* aux = cabeza;
        while (aux != NULL) {
            aux->dato.mostrar();
            aux = aux->sig;
        }
    }
};

#endif 
