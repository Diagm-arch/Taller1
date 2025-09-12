#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno() {
    id = -1;
    nombre = "";
    apellido = "";
    carrera = "";
    fechaIngreso = "";
}

Alumno::Alumno(int _id, string _nombre, string _apellido, string _carrera, string _fecha) {
    id = _id;
    nombre = _nombre;
    apellido = _apellido;
    carrera = _carrera;
    fechaIngreso = _fecha;
}

void Alumno::mostrar() {
    cout << "ID: " << id << ", "
        << nombre << " " << apellido
        << ", Carrera: " << carrera
        << ", Ingreso: " << fechaIngreso << endl;
}
