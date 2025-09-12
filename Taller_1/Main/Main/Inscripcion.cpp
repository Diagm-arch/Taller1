#include "Inscripcion.h"
#include <iostream>
using namespace std;

Inscripcion::Inscripcion() {
    alumnoId = -1;
    cursoCodigo = "";
    listaNotas = NULL;
}

Inscripcion::Inscripcion(int _id, string _codigo) {
    alumnoId = _id;
    cursoCodigo = _codigo;
    listaNotas = NULL;
}

void Inscripcion::agregarNota(double n) {
    NotaNode* nuevo = new NotaNode;
    nuevo->nota = n;
    nuevo->sig = NULL;

    if (listaNotas == NULL) {
        listaNotas = nuevo;
    }
    else {
        NotaNode* aux = listaNotas;
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

double Inscripcion::promedio() {
    if (listaNotas == NULL) return 0.0;

    double suma = 0;
    int cantidad = 0;
    NotaNode* aux = listaNotas;
    while (aux != NULL) {
        suma += aux->nota;
        cantidad++;
        aux = aux->sig;
    }
    return (cantidad > 0) ? suma / cantidad : 0.0;
}

void Inscripcion::mostrar() {
    cout << "Inscripcion -> Alumno ID: " << alumnoId
        << ", Curso: " << cursoCodigo << endl;
    double p = promedio();
    if (p > 0) {
        cout << "  Promedio: " << p << endl;
    }
}
