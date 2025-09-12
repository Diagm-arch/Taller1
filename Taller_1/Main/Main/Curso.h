#ifndef CURSO_H
#define CURSO_H

#include <string>
using namespace std;

struct Curso {
    string codigo;
    string nombre;
    int maxEstudiantes;
    string carrera;
    string profesor;

    Curso();
    Curso(string _codigo, string _nombre, int _max, string _carrera, string _profesor);

    void mostrar();
};

#endif
