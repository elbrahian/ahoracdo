#include "palabrasAhorcado.cpp"
#include "RegistroUsuarios.cpp"
#include "Reglas.cpp"
#include "juego.cpp"
#include <iostream>

using namespace std;

int main() {
    int opc;

    do {
        cout << "====MENU====" << endl;
        cout << "1. usuarios " << endl;
        cout << "2. palabras del juego " << endl;
        cout << "3. ver reglas " << endl;
        cout << "4. jugar Ahorcado" << endl;
        cout << "5. salir" << endl;
        cout << "============" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                int opcuser;
                cout << "====USUARIOS====" << endl;
                cout << "1. crear usuario" << endl;
                cout << "2. ver usuarios" << endl;
                cout << "Ingrese una opcion: ";
                cout << "================" << endl;
                cin >> opcuser;
                switch (opcuser) {
                    case 1: {
                        string nombre;
                        cout << "Ingrese nombre: ";
                        cin >> nombre;
                        crearUsuario("HistorialUsuarios.txt", nombre, 0);
                        break;
                    }
                    case 2: {
                        mostrarUsuario("HistorialUsuarios.txt");
                        break;
                    }
                    default: {
                        cout << "Opción inválida" << endl;
                    }
                }
                break;
            }
            case 2: {
                int opcpal;
                cout << "====PALABRAS====" << endl;
                cout << "1. crear palabra" << endl;
                cout << "2. mostrar palabras" << endl;
                cout << "Ingrese una opcion: ";
                cout << "================" << endl;
                cin >> opcpal;
                switch (opcpal) {
                    case 1: {
                        CrearPalabra word;
                        crearWord("PalabrasAhorcado.txt", word);
                        break;
                    }
                    case 2: {
                        mostrarWord("PalabrasAhorcado.txt");
                        break;
                    }
                    default: {
                        cout << "Opción inválida" << endl;
                    }
                }
                break;
            }
            case 3: {
                int opcre;
                cout << "====REGLAS====" << endl;
                cout << "1. Crear Regla nueva" << endl;
                cout << "2. Mostrar las reglas" << endl;
                cout << "Ingrese una opcion: ";
                cout << "==============" << endl;
                cin >> opcre;

                switch (opcre) {
                    case 1: {
                        crearRegla("Reglas.txt");
                        break;
                    }
                    case 2: {
                        mostrarReglas("Reglas.txt");
                        break;
                    }
                    default: {
                        cout << "Opción inválida" << endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "4. jugar Ahorcado" << endl;
                break;
            }
            case 5: {
                cout << "Saliendo..." << endl;
                break;
            }
            default: {
                cout << "Opción incorrecta" << endl;
            }
        }
    } while (opc != 5);

    return 0;
}
