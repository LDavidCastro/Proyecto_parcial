#include <iostream>
#include <fstream>
#include <string>
#include<Windows.h>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Definición de la estructura para los datos del paciente
struct Paciente {
    string nombre;
    int edad;
    string direccion;
    string telefono;
    string fecha;
    string hora;
    string diagnostico;
    string tratamiento;
    string  consepto;
    double monto;
    double saldo;
    string sintomas;
    string conclusion;
    string descripcion;
    double costo;

};

void menuPrincipal();
void supMenuResgistrarPaciente();
void registrarPaciente();
void verListaPacientes();
void supMenuProgramarCita();
void programarCita();
void verCitasProgramadas();
void menuHistorial();
void historialMedico();
void realizarDiagnostico();
void realizarTratamiento();
void realizarPago();

int main() {
    int op;
    do {
        system("cls");
        menuPrincipal();

        cin >> op;

        switch (op) {
        case 1:
            int opRegistrar;
            do {
                system("cls");
                supMenuResgistrarPaciente();
                cin >> opRegistrar;

                switch (opRegistrar) {
                case 1:
                    system("cls");
                    registrarPaciente();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    verListaPacientes();
                    system("pause");
                    break;
                case 3:

                    break;
                case 4:
                    system("cls");
                    gotoxy(30, 10);cout << "Saliendo del programa." << endl;
                    system("pause");
                    break;
                default:
                    system("cls");
                    gotoxy(30, 10); cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
                    system("pause");
                    break;
                }
            } while (opRegistrar != 4);

            break;
        case 2:
            int opProgramar;
            do {
                system("cls");
                supMenuProgramarCita();
                cin >> opProgramar;
                switch (opProgramar) {
                case 1:
                    system("cls");
                    programarCita();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    verCitasProgramadas();
                    system("pause");
                    break;
                case 3:

                    break;
                case 4:
                    system("cls");
                    gotoxy(30, 10);cout << "Saliendo del programa." << endl;
                    system("pause");
                    break;
                default:
                    system("cls");
                    gotoxy(30, 10);cout << "Opción invalida. Por favor, ingrese una opcion valida." << endl;
                    system("pause");
                    break;
                }
            } while (opProgramar != 4);

            break;
        case 3:
            int opHistorial;
            do {
                system("cls");
                menuHistorial();
                cin >> opHistorial;
                switch (opHistorial) {
                case 1:
                    system("cls");
                    historialMedico();
                    system("pause");

                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:
                    system("cls");
                    cout << "Saliendo del programa." << endl;
                    system("pause");
                    break;
                default:
                    system("cls");
                    cout << "Opción invalida. Por favor, ingrese una opcion valida." << endl;
                    system("pause");
                    break;
                }
            } while (opHistorial != 4);

            break;
        case 4:
            system("cls");
            realizarDiagnostico();
            system("pause");
            break;
        case 5:
            realizarTratamiento();

        case 6:
            system("cls");
            realizarPago();
            system("pause");
            break;

        case 10:
            system("cls");
            gotoxy(30, 10);cout << "Saliendo del programa." << endl;
            system("pause");
            break;
        default:
            system("cls");
            gotoxy(30, 10);cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
            system("pause");
            break;
        }


    } while (op != 10);


    return 0;
}

void menuPrincipal() {
    gotoxy(30, 10);cout << "MENU PRINCIPAL:" << endl;
    gotoxy(30, 12);cout << "1. Registrar Paciente" << endl;
    gotoxy(30, 13);cout << "2. Programar cita" << endl;
    gotoxy(30, 14);cout << "3. registrar historial medico" << endl;
    gotoxy(30, 15);cout << "4. Realizar diagnostico" << endl;
    gotoxy(30, 16);cout << "5. registrar tratamiento" << endl;
    gotoxy(30, 17);cout << "6. realizar pago: " << endl;
    gotoxy(30, 18);cout << "Ingrese una opcion: ";

}

void supMenuResgistrarPaciente() {
    gotoxy(30, 10);cout << "SUB_MENU_REGISTRAR:" << endl;
    gotoxy(30, 12);cout << "1. Registrar Paciente" << endl;
    gotoxy(30, 13);cout << "2. Ver Lista de Pacientes" << endl;
    gotoxy(30, 14);cout << "3. Eliminar Paciente" << endl;
    gotoxy(30, 15);cout << "4. Salir" << endl;
    gotoxy(30, 16);cout << "Ingrese una opcion: ";

}

// Función para registrar un nuevo paciente
void registrarPaciente() {
    ofstream archivo("pacientes.txt", ios::app);
    if (archivo.is_open()) {
        Paciente nuevoPaciente;
        gotoxy(30, 10);cout << "1. Registrar Paciente" << endl;
        gotoxy(30, 12);cout << "Ingrese el nombre del paciente: ";
        getline(cin >> ws, nuevoPaciente.nombre);
        gotoxy(30, 13);cout << "Ingrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;
        gotoxy(30, 14);cout << "Ingrese la direccion del paciente: ";
        getline(cin >> ws, nuevoPaciente.direccion);
        gotoxy(30, 15);cout << "Ingrese el telefono del paciente: ";
        getline(cin >> ws, nuevoPaciente.telefono);

        archivo << nuevoPaciente.nombre << "," << nuevoPaciente.edad << "," << nuevoPaciente.direccion << "," << nuevoPaciente.telefono << endl;

        gotoxy(30, 17);cout << "1. Registrar Paciente" << endl;cout << "Paciente registrado correctamente." << endl;
        archivo.close();
    }
    else {
        gotoxy(30, 17);cout << "1. Registrar Paciente" << endl;cout << "Error al abrir el archivo." << endl;
    }
}

// Función para ver la lista de pacientes
void verListaPacientes() {
    ifstream archivo("pacientes.txt");

    if (archivo.is_open()) {
        string linea;
        gotoxy(30, 10);cout << "Lista de Pacientes:" << endl;
        while (getline(archivo, linea)) {
            gotoxy(30, 12 + 1);cout << linea << endl;
        }
        archivo.close();
    }
    else {
        gotoxy(30, 12);cout << "No se pudo abrir el archivo." << endl;
    }
}

void supMenuProgramarCita() {
    gotoxy(30, 10);cout << "SUB_MENU_PROGRAMAR_CITA:";
    gotoxy(30, 12);cout << "1. Programar cita";
    gotoxy(30, 13);cout << "2. Ver Lista citas programadas";
    gotoxy(30, 14);cout << "3. Eliminar citas";
    gotoxy(30, 15);cout << "4. Salir";
    gotoxy(30, 16);cout << "Ingrese una opcion: ";

}

// Función para programar una cita
void programarCita() {
    Paciente nuevoPaciente;
    gotoxy(30, 10);cout << "1. Programar cita";cout << "1. Programar cita";
    // Solicitar detalles de la cita
    gotoxy(30, 12);cout << "1. Programar cita";cout << "Ingrese el nombre del paciente: ";
    getline(cin >> ws, nuevoPaciente.nombre);

    gotoxy(30, 13);cout << "1. Programar cita";cout << "Ingrese la fecha de la cita (dd/mm/aaaa): ";
    getline(cin, nuevoPaciente.fecha);

    gotoxy(30, 14);cout << "1. Programar cita";cout << "Ingrese la hora de la cita (hh:mm): ";
    getline(cin, nuevoPaciente.hora);

    // Abrir el archivo de citas en modo de adjuntar
    ofstream archivo("citas.txt", ios::app);
    if (archivo.is_open()) {
        // Escribir los detalles de la cita en el archivo
        archivo << "Paciente: " << nuevoPaciente.nombre << ", Fecha: " << nuevoPaciente.fecha << ", Hora: " << nuevoPaciente.hora << endl;
        archivo.close();
        gotoxy(30, 16);cout << "1. Programar cita";cout << "Cita programada correctamente para el paciente " << nuevoPaciente.nombre << " el " <<
            nuevoPaciente.fecha << " a las " << nuevoPaciente.hora << "." << endl;
    }
    else {
        gotoxy(30, 16);cout << "1. Programar cita";cout << "Error: No se pudo abrir el archivo de citas." << endl;
    }
}


void verCitasProgramadas() {
    ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        string linea;
        gotoxy(30, 10);cout << "Citas programadas:" << endl;
        while (getline(archivo, linea)) {
            gotoxy(30, 12 + 2);cout << linea << endl;
        }
        archivo.close();
    }
    else {
        gotoxy(30, 1);cout << "No hay citas programadas actualmente." << endl;
    }
}

void menuHistorial() {
    cout << "MENU:" << endl;
    cout << "1.Registrar historial medico  " << endl;
    cout << "2. Ver Lista de historiales medicos " << endl;
    cout << "3. Eliminar historial medico" << endl;
    cout << "4. Salir" << endl;
    cout << "Ingrese una opcion: ";
}

void historialMedico() {
    Paciente nuevoHistorial;
    cout << "ingrese la fecha del historla medico: ";
    cin.ignore();
    getline(cin, nuevoHistorial.fecha);
    cout << "ingrese el diagnosticos: ";
    getline(cin, nuevoHistorial.diagnostico);
    cout << "Ingrese el tratamiento: ";
    getline(cin, nuevoHistorial.tratamiento);

    // Mostrar el historial médico ingresado
    cout << "\nHistorial medico registrado exitosamente:" << endl;
    cout << "Fecha: " << nuevoHistorial.fecha << endl;
    cout << "Diagnodstico: " << nuevoHistorial.diagnostico << endl;
    cout << "Tratamiento: " << nuevoHistorial.tratamiento << endl;
}

void realizarDiagnostico() {
    Paciente diagnostico;
    cout << "ingrese los sintomas del paciente: ";
    cin.ignore();
    getline(cin, diagnostico.sintomas);
    cout << "ingrese la conclusion del diagnostico: ";
    getline(cin, diagnostico.conclusion);

    //mostrar el diagnostico realizado 

    cout << "\nDiagnostico relizado exitosamente: " << endl;
    cout << "Sintomas: " << diagnostico.sintomas << endl;
    cout << "Conclusion: " << diagnostico.conclusion << endl;

}

void realizarPago() {
    Paciente pago;
    cout << "ingresa la fecha del pago: ";
    getline(cin, pago.fecha);
    cout << "ingrese el concepto del pago: ";
    getline(cin, pago.consepto);
    cout << "Ingrese le motno del pago: ";
    cin >> pago.monto;

    //mostar el pago realizado;

    cout << "\nPago realizado exitosamente: " << endl;
    cout << "Fecha: " << pago.fecha << endl;
    cout << "Concepto: " << pago.consepto << endl;
    cout << "monto: Q" << pago.monto << endl;

}

void realizarTratamiento() {
    Paciente tratamiento;
    cout << "Ingrese el nombre del tratamiento: ";
    cin.ignore();
    getline(cin, tratamiento.nombre);
    cout << "Ingrese la describcion del tratamiento: ";
    getline(cin, tratamiento.descripcion);
    cout << "Ingrese el costo del tratamiento: ";
    cin >> tratamiento.costo;

    //mostara el tratamiento registrado 
    cout << "\nTratamiento registrado exitosamente: " << endl;
    cout << "nombre: " << tratamiento.nombre << endl;
    cout << "Descripcion: " << tratamiento.descripcion << endl;
    cout << "costo: Q" << tratamiento.costo << endl;
}

