#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
using namespace std;

struct NotaNode {
    double nota;
    NotaNode* sig;
};

struct Inscripcion {
    int alumnoId;
    string cursoCodigo;
    NotaNode* listaNotas;

    Inscripcion();
    Inscripcion(int _id, string _codigo);

    void agregarNota(double n);
    double promedio();
    void mostrar();
};

#endif
