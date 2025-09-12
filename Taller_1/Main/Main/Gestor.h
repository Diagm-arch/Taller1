#ifndef GESTOR_H
#define GESTOR_H

#include "Alumno.h"       
#include "Curso.h"
#include "Inscripcion.h"
#include "LinkedList.h"   

class Gestor {
private:
    LinkedList<Alumno> alumnos;
    LinkedList<Curso> cursos;
    LinkedList<Inscripcion> inscripciones;

public:
    Gestor();

    void agregarAlumno();
    void buscarAlumno();
    void eliminarAlumno();

    void agregarCurso();
    void buscarCurso();
    void eliminarCurso();

    void inscribirAlumno();
    void eliminarInscripcion();

    void mostrarAlumnos();
    void mostrarCursos();
    void mostrarInscripciones();

    void menu();
};

#endif
