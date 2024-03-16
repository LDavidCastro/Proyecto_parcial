#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Definición de la estructura para los datos del paciente
struct Paciente {
    string nombre;
    int edad;
    string direccion;
    string telefono;
    // Agrega más campos según tus necesidades
};



// Función para registrar un nuevo paciente
void registrarPaciente() {
    ofstream archivo("pacientes.txt", ios::app);
    if (archivo.is_open()) {
        Paciente nuevoPaciente;
        cout << "Ingrese el nombre del paciente: ";
        getline(cin >> ws, nuevoPaciente.nombre);
        cout << "Ingrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;
        cout << "Ingrese la direccion del paciente: ";
        getline(cin >> ws, nuevoPaciente.direccion);
        cout << "Ingrese el telefono del paciente: ";
        getline(cin >> ws, nuevoPaciente.telefono);

        archivo << nuevoPaciente.nombre << "," << nuevoPaciente.edad << "," << nuevoPaciente.direccion << "," << nuevoPaciente.telefono << endl;

        cout << "Paciente registrado correctamente." << endl;
        archivo.close();
    }
    else {
        cout << "Error al abrir el archivo." << endl;
    }
}

// Función para ver la lista de pacientes
void verListaPacientes() {
    ifstream archivo("pacientes.txt");
    if (archivo.is_open()) {
        string linea;
        cout << "Lista de Pacientes:" << endl;
        while (getline(archivo, linea)) {      
            cout << linea << endl;
        }
        archivo.close();
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Función para eliminar un paciente
void eliminarPaciente() {
    string nombrePaciente;
    cout << "Ingrese el nombre del paciente que desea eliminar: ";
    getline(cin >> ws, nombrePaciente);

    ifstream archivoEntrada("pacientes.txt");
    ofstream archivoTemporal("temporal.txt");

    if (archivoEntrada.is_open() && archivoTemporal.is_open()) {
        string linea;
        bool pacienteEncontrado = false;
        while (getline(archivoEntrada, linea)) {
            // Si la línea no contiene el nombre del paciente, la escribimos en el archivo temporal
            if (linea.find(nombrePaciente) == string::npos) {
                archivoTemporal << linea << endl;
            }
            else {
                pacienteEncontrado = true;
            }
        }
        archivoEntrada.close();
        archivoTemporal.close();

        // Eliminamos el archivo original y renombramos el temporal
        remove("pacientes.txt");
        rename("temporal.txt", "pacientes.txt");

        if (pacienteEncontrado) {
            cout << "El paciente fue eliminado correctamente." << endl;
        }
        else {
            cout << "No se encontró ningún paciente con ese nombre." << endl;
        }
    }
    else {
        cout << "Error al abrir los archivos." << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "MENU:" << endl;
        cout << "1. Registrar Paciente" << endl;
        cout << "2. Ver Lista de Pacientes" << endl;
        cout << "3. Eliminar Paciente" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;                                                       

        switch (opcion) {
        case 1:
            registrarPaciente();
            break;
        case 2:
            verListaPacientes();
            break;
        case 3:
            eliminarPaciente();
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            break;
        }
    } while (opcion != 4);

    return 0;
}

