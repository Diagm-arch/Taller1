#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
using namespace std;

struct Alumno {
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    Alumno();
    Alumno(int _id, string _nombre, string _apellido, string _carrera, string _fecha);

    void mostrar();
};

#endif
