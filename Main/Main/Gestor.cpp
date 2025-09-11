#include "Gestor.h"
#include <iostream>
using namespace std;

Gestor::Gestor() {}

//// ======== CRUD Alumnos ========
void Gestor::agregarAlumno() {
    int id;
    string nombre, apellido, carrera, fecha;

    cout << "ID: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido: "; cin >> apellido;
    cout << "Carrera: "; cin >> carrera;
    cout << "Fecha ingreso (YYYY-MM-DD): "; cin >> fecha;

    Alumno a(id, nombre, apellido, carrera, fecha);
    alumnos.agregar(a);
    cout << "Alumno agregado.\n";
}

void Gestor::buscarAlumno() {
    int id;
    cout << "ID a buscar: ";
    cin >> id;
    Alumno* a = alumnos.buscarPorId(id);
    if (a != NULL) {
        a->mostrar();
    }
    else {
        cout << "Alumno no encontrado.\n";
    }
}

void Gestor::eliminarAlumno() {
    int id;
    cout << "ID a eliminar: ";
    cin >> id;
    bool ok = alumnos.eliminarPorId(id);
    if (ok) cout << "Alumno eliminado.\n";
    else cout << "No existe alumno con ese ID.\n";
}

//// ======== CRUD Cursos ========
void Gestor::agregarCurso() {
    string codigo, nombre, carrera, profesor;
    int maxEst;

    cout << "Codigo: "; cin >> codigo;
    cout << "Nombre: "; cin >> nombre;
    cout << "Max estudiantes: "; cin >> maxEst;
    cout << "Carrera: "; cin >> carrera;
    cout << "Profesor: "; cin >> profesor;

    Curso c(codigo, nombre, maxEst, carrera, profesor);
    cursos.agregar(c);
    cout << "Curso agregado.\n";
}

void Gestor::buscarCurso() {
    string codigo;
    cout << "Codigo del curso: ";
    cin >> codigo;

    // Buscamos manualmente (porque LinkedList no tiene buscar por string)
    Nodo<Curso>* aux = cursos.getCabeza();
    while (aux != NULL) {
        if (aux->dato.codigo == codigo) {
            aux->dato.mostrar();
            return;
        }
        aux = aux->sig;
    }
    cout << "Curso no encontrado.\n";
}

void Gestor::eliminarCurso() {
    string codigo;
    cout << "Codigo del curso: ";
    cin >> codigo;

    Nodo<Curso>* aux = cursos.getCabeza();
    Nodo<Curso>* anterior = NULL;

    while (aux != NULL) {
        if (aux->dato.codigo == codigo) {
            cursos.eliminarNodo(aux, anterior);
            cout << "Curso eliminado.\n";
            return;
        }
        anterior = aux;
        aux = aux->sig;
    }
    cout << "Curso no encontrado.\n";
}

//// ======== Inscripciones ========
void Gestor::inscribirAlumno() {
    int id;
    string codigo;
    cout << "ID alumno: "; cin >> id;
    cout << "Codigo curso: "; cin >> codigo;

    Alumno* a = alumnos.buscarPorId(id);
    if (a == NULL) {
        cout << "Alumno no existe.\n";
        return;
    }

    // Validamos curso
    Nodo<Curso>* aux = cursos.getCabeza();
    Curso* cursoPtr = NULL;
    while (aux != NULL) {
        if (aux->dato.codigo == codigo) {
            cursoPtr = &aux->dato;
            break;
        }
        aux = aux->sig;
    }
    if (cursoPtr == NULL) {
        cout << "Curso no existe.\n";
        return;
    }

    // Validar carrera
    if (cursoPtr->carrera != a->carrera) {
        cout << "Alumno no puede inscribirse en otra carrera.\n";
        return;
    }

    Inscripcion ins(id, codigo);
    inscripciones.agregar(ins);
    cout << "Inscripcion realizada.\n";
}

void Gestor::eliminarInscripcion() {
    int id;
    string codigo;
    cout << "ID alumno: "; cin >> id;
    cout << "Codigo curso: "; cin >> codigo;

    Nodo<Inscripcion>* aux = inscripciones.getCabeza();
    Nodo<Inscripcion>* anterior = NULL;

    while (aux != NULL) {
        if (aux->dato.alumnoId == id && aux->dato.cursoCodigo == codigo) {
            inscripciones.eliminarNodo(aux, anterior);
            cout << "Inscripcion eliminada.\n";
            return;
        }
        anterior = aux;
        aux = aux->sig;
    }
    cout << "No existe inscripcion con esos datos.\n";
}

//// ======== Mostrar ========
void Gestor::mostrarAlumnos() {
    alumnos.mostrarTodos();
}

void Gestor::mostrarCursos() {
    cursos.mostrarTodos();
}

void Gestor::mostrarInscripciones() {
    inscripciones.mostrarTodosInscripciones();
}

//// ======== Menu ========
void Gestor::menu() {
    int opcion;
    do {
        cout << "\n==== MENU ====\n";
        cout << "1. Agregar Alumno\n";
        cout << "2. Buscar Alumno\n";
        cout << "3. Eliminar Alumno\n";
        cout << "4. Agregar Curso\n";
        cout << "5. Buscar Curso\n";
        cout << "6. Eliminar Curso\n";
        cout << "7. Inscribir Alumno en Curso\n";
        cout << "8. Eliminar Inscripcion\n";
        cout << "9. Mostrar Alumnos\n";
        cout << "10. Mostrar Cursos\n";
        cout << "11. Mostrar Inscripciones\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarAlumno(); break;
        case 2: buscarAlumno(); break;
        case 3: eliminarAlumno(); break;
        case 4: agregarCurso(); break;
        case 5: buscarCurso(); break;
        case 6: eliminarCurso(); break;
        case 7: inscribirAlumno(); break;
        case 8: eliminarInscripcion(); break;
        case 9: mostrarAlumnos(); break;
        case 10: mostrarCursos(); break;
        case 11: mostrarInscripciones(); break;
        case 0: cout << "Saliendo...\n"; break;
        default: cout << "Opcion invalida\n";
        }
    } while (opcion != 0);
}
