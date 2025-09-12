#include "Curso.h"
#include <iostream>
using namespace std;

Curso::Curso() {
    codigo = "";
    nombre = "";
    maxEstudiantes = 0;
    carrera = "";
    profesor = "";
}

Curso::Curso(string _codigo, string _nombre, int _max, string _carrera, string _profesor) {
    codigo = _codigo;
    nombre = _nombre;
    maxEstudiantes = _max;
    carrera = _carrera;
    profesor = _profesor;
}

void Curso::mostrar() {
    cout << "Codigo: " << codigo
        << ", Nombre: " << nombre
        << ", Max: " << maxEstudiantes
        << ", Carrera: " << carrera
        << ", Profesor: " << profesor << endl;
}
