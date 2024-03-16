//Luis David Castro Coché  carnet: 2290-23-3698
//Yeferson Joj Cuy  Carnet:2290-23-15600
//María Natividad Velásquez Sequec  carnet : 2290 - 23 - 20536

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
    string nombre;   // getline(con>> ws, nuevoPaciente.telefono)
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

int main(){
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
                            system("color 0");
                             system("pause");
                             break;
                         case 2:
                             system("cls");
                             verListaPacientes();
                             system("color 0");
                             system("pause");
                             break;
                         case 3:

                             break;
                         case 4:
                             system("cls");
                             gotoxy(30, 10);cout << "Saliendo del programa.";
                             system("color 0");
                             system("pause");
                             break;
                         default:
                             system("cls");
                             gotoxy(30,10); cout << "Opcion invalida. Por favor, ingrese una opcion valida.";
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
            system("cls");
            realizarTratamiento();
            system("pause");
            break;
        case 6: 
            system("cls");
            realizarPago();
            system("pause");
            break;

        case 7:
            system("cls");
            gotoxy(30, 10);cout << "Saliendo del programa.";
            system("pause");
            break;
        default:
            system("cls");
            gotoxy(30, 10);cout << "Opcion invalida. Por favor, ingrese una opcion valida.";
            system("pause");
            break;
        }


    } while (op!=7);


    return 0;
}

void menuPrincipal() {
    system("color 1");
    gotoxy(30, 10);cout << "\aMENU PRINCIPAL:";
    gotoxy(30, 12);cout << "1. Registrar Paciente";
    gotoxy(30, 13);cout << "2. Programar cita";
    gotoxy(30, 14);cout << "3. registrar historial medico";
    gotoxy(30, 15);cout << "4. Realizar diagnostico";
    gotoxy(30, 16);cout << "5. registrar tratamiento";
    gotoxy(30, 17);cout << "6. realizar pago: ";
    gotoxy(30, 18);cout << "7. salir: ";
    gotoxy(30, 19);cout << "Ingrese una opcion: ";

}

void supMenuResgistrarPaciente() {
    system("color 2");
    gotoxy(30, 10);cout << "\aSUB_MENU_REGISTRAR:";
    gotoxy(30, 12);cout << "1. Registrar Paciente";
    gotoxy(30, 13);cout << "2. Ver Lista de Pacientes";
    gotoxy(30, 14);cout << "3. Eliminar Paciente";
    gotoxy(30, 15);cout << "4. Salir";
    gotoxy(30, 16);cout << "Ingrese una opcion: ";

}

// Función para registrar un nuevo paciente
void registrarPaciente() {
    system("color 3");
    ofstream archivo("pacientes.txt", ios::app);
    if (archivo.is_open()) {
        Paciente nuevoPaciente;
        gotoxy(30, 10);cout << "1. \aRegistrar Paciente";
        gotoxy(30, 12);cout << "Ingrese el nombre del paciente: ";
        getline(cin >> ws, nuevoPaciente.nombre);           
        gotoxy(30, 13);cout << "Ingrese la edad del paciente: ";
        cin >> nuevoPaciente.edad;
        gotoxy(30, 14);cout << "Ingrese la direccion del paciente: ";
        getline(cin >> ws, nuevoPaciente.direccion);
        gotoxy(30, 15);cout << "Ingrese el telefono del paciente: ";
        getline(cin >> ws, nuevoPaciente.telefono);

        archivo << nuevoPaciente.nombre << "," << nuevoPaciente.edad << "," << nuevoPaciente.direccion << "," << nuevoPaciente.telefono;

        gotoxy(30, 17);cout << "Paciente registrado correctamente.";
        archivo.close();
    }
    else {
        gotoxy(30, 17);cout << "Error al abrir el archivo.";
    }
}

// Función para ver la lista de pacientes
void verListaPacientes() {
    system("color 4");
    ifstream archivo("pacientes.txt");

    if (archivo.is_open()) {
        string linea;
        int posY = 10; // Posición vertical inicial
        gotoxy(30, posY);cout << "\aLista de Pacientes:";
        while (getline(archivo, linea)) {
            gotoxy(30, ++posY);cout << linea;
        }
        archivo.close();
    }
    else {
        gotoxy(30, 12);cout << "No se pudo abrir el archivo.";
    }
}

void supMenuProgramarCita() {
    system("color 5");
    gotoxy(30, 10);cout << "\aSUB_MENU_PROGRAMAR_CITA:";
    gotoxy(30, 12);cout << "1. Programar cita";
    gotoxy(30, 13);cout << "2. Ver Lista citas programadas";
    gotoxy(30, 14);cout << "3. Eliminar citas";
    gotoxy(30, 15);cout << "4. Salir";
    gotoxy(30, 16);cout << "Ingrese una opcion: ";

}

// Función para programar una cita
void programarCita() {
    system("color 6");
    Paciente nuevoPaciente;
    gotoxy(30, 10);cout << "\a1. Programar cita";
    // Solicitar detalles de la cita
    gotoxy(30, 12);cout << "Ingrese el nombre del paciente: ";
    getline(cin >> ws, nuevoPaciente.nombre);

    gotoxy(30, 13);cout << "Ingrese la fecha de la cita (dd/mm/aaaa): ";
    getline(cin, nuevoPaciente.fecha);

    gotoxy(30, 14);cout << "Ingrese la hora de la cita (hh:mm): ";
    getline(cin, nuevoPaciente.hora);

    // Abrir el archivo de citas en modo de adjuntar
    ofstream archivo("citas.txt", ios::app);
    if (archivo.is_open()) {
        // Escribir los detalles de la cita en el archivo
        archivo << "Paciente: " << nuevoPaciente.nombre << ", Fecha: " << nuevoPaciente.fecha << ", Hora: " << nuevoPaciente.hora;
        archivo.close();
        gotoxy(30, 16);cout << "Cita programada correctamente para el paciente " << nuevoPaciente.nombre << " el " <<
            nuevoPaciente.fecha << " a las " << nuevoPaciente.hora << ".";
    }
    else {
        gotoxy(30, 16);cout << "Error: No se pudo abrir el archivo de citas.";
    }
}

void verCitasProgramadas() {
    system("color B");
    ifstream archivo("citas.txt");
    if (archivo.is_open()) {
        string linea;
        int posY = 10; // Posición vertical inicial
        gotoxy(30, posY);cout << "\aCitas programadas:";
        while (getline(archivo, linea)) {
            
            
                gotoxy(30, ++posY);cout << linea;
            
            
        }
        archivo.close();
    }
    else {
        gotoxy(30, 12);cout << "No hay citas programadas actualmente.";
    }
}

void menuHistorial() {
    system("color 9");
    gotoxy(30, 10);cout << "\aSUB_MENU_HISTORIAL_MEDICO:";
    gotoxy(30, 12);cout << "1.Registrar historial medico  ";
    gotoxy(30, 13);cout << "2. Ver Lista de historiales medicos ";
    gotoxy(30, 14);cout << "3. Eliminar historial medico";
    gotoxy(30, 15);cout << "4. Salir";
    gotoxy(30, 16);cout << "Ingrese una opcion: ";
}

void historialMedico() {
    system("color A");
    Paciente nuevoHistorial;
    gotoxy(30, 10);cout << "\aingrese la fecha del historla medico: ";
    cin.ignore();
    getline(cin, nuevoHistorial.fecha);
    gotoxy(30, 12);cout << "ingrese el diagnosticos: ";
    getline(cin, nuevoHistorial.diagnostico);
    gotoxy(30, 13);cout << "Ingrese el tratamiento: ";
    getline(cin, nuevoHistorial.tratamiento);

    // Mostrar el historial médico ingresado
    gotoxy(30, 15);cout << "Historial medico registrado exitosamente:";
    gotoxy(30, 16);cout << "Fecha: " << nuevoHistorial.fecha;
    gotoxy(30, 17);cout << "Diagnodstico: " << nuevoHistorial.diagnostico;
    gotoxy(30, 18);cout << "Tratamiento: " << nuevoHistorial.tratamiento;
}

void realizarDiagnostico() {
    system("color C");
    Paciente diagnostico;
    gotoxy(30, 10);cout << "\aingrese los sintomas del paciente: ";
    cin.ignore();
    getline(cin, diagnostico.sintomas);
    gotoxy(30, 12);cout << "ingrese la conclusion del diagnostico: ";
    getline(cin, diagnostico.conclusion);

    //mostrar el diagnostico realizado 

    gotoxy(30, 15);cout << "Diagnostico relizado exitosamente: ";
    gotoxy(30, 16);cout << "Sintomas: " << diagnostico.sintomas;
    gotoxy(30, 17);cout << "Conclusion: " << diagnostico.conclusion;

}

void realizarTratamiento() {
    system("color D");
    Paciente tratamiento;
    gotoxy(30, 10);cout << "\aIngrese el nombre del tratamiento: ";
    cin.ignore();
    getline(cin, tratamiento.nombre);
    gotoxy(30, 12);cout << "Ingrese la describcion del tratamiento: ";
    getline(cin, tratamiento.descripcion);
    gotoxy(30, 13); cout << "Ingrese el costo del tratamiento: ";
    cin >> tratamiento.costo;

    //mostara el tratamiento registrado 
    gotoxy(30, 14);cout << "Tratamiento registrado exitosamente: ";
    gotoxy(30, 15);cout << "nombre: " << tratamiento.nombre;
    gotoxy(30, 16);cout << "Descripcion: " << tratamiento.descripcion;
    gotoxy(30, 17);cout << "costo: Q" << tratamiento.costo;
}

void realizarPago() {
    system("color E");
    Paciente pago;
    gotoxy(30, 10);cout << "\aingresa la fecha del pago: ";
    getline(cin, pago.fecha);
    gotoxy(30, 12);cout << "ingrese el concepto del pago: ";
    getline(cin, pago.consepto);
    gotoxy(30, 13);cout << "Ingrese le motno del pago: ";
    cin >> pago.monto;

    //mostar el pago realizado;

    gotoxy(30, 15);cout << "Pago realizado exitosamente";
    gotoxy(30, 16);cout << "Fecha: " << pago.fecha;
    gotoxy(30, 17);cout << "Concepto: " << pago.consepto;
    gotoxy(30, 18);cout << "monto: Q" << pago.monto;

}



