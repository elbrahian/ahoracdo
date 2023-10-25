#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include "palabrasAhorcado.cpp"

using namespace std;

struct Jugador {
    string nombre;
    int puntajeGlobal;
    int rondasGanadas;
    int comodinDefinicion;
    int comodinSinonimoAntonimo;
    stack<char> letrasIngresadas;  // Nueva estructura para almacenar letras ingresadas
    list<pair<string, string>> palabrasAdivinadas;  // Nueva estructura para almacenar palabras adivinadas
};

struct Comodin {
    string tipo;
    int valor;
};

struct Palabra {
    string palabra;
    string definicion;
    string sinonimo;
    string antonimo;
};

struct Juego {
    string palabraSecreta;
    string palabraAdivinada;
    int intentosRestantes;
    int puntuacion;
    stack<char> letrasIngresadas;
    list<pair<string, string>> palabrasAdivinadas; // (Palabra, Definici�n)
};

bool usarComodin(Jugador& jugador, vector<Comodin>& comodines) {
    cout << "Comodines disponibles:" << endl;
    cout << "1. Definici�n (Resta " << comodines[0].valor << " puntos)" << endl;
    cout << "2. Sin�nimo/Ant�nimo (Resta " << comodines[1].valor << " puntos)" << endl;
    cout << "Elije un comod�n (0 para continuar sin usar): ";
    int eleccionComodin;
    cin >> eleccionComodin;

    if (eleccionComodin == 1) {
        if (jugador.comodinDefinicion > 0) {
            jugador.comodinDefinicion--;
            jugador.puntajeGlobal -= comodines[0].valor;
            // Aqu� deber�as implementar la l�gica para mostrar la definici�n.
            return true;
        } else {
            cout << "No tienes comodines de definici�n disponibles." << endl;
            return false;
        }
    } else if (eleccionComodin == 2) {
        if (jugador.comodinSinonimoAntonimo > 0) {
            jugador.comodinSinonimoAntonimo--;
            jugador.puntajeGlobal -= comodines[1].valor;
            // Aqu� deber�as implementar la l�gica para mostrar sin�nimos o ant�nimos.
            return true;
        } else {
            cout << "No tienes comodines de sin�nimo/ant�nimo disponibles." << endl;
            return false;
        }
    }
    return false;
}

void mostrarComodines(Jugador& jugador, vector<Comodin>& comodines) {
    cout << "Comodines de " << jugador.nombre << ":" << endl;
    cout << "Definici�n: " << jugador.comodinDefinicion << endl;
    cout << "Sin�nimo/Ant�nimo: " << jugador.comodinSinonimoAntonimo << endl;
}

bool jugarRonda(Jugador& jugador, Palabra& palabra, vector<Comodin>& comodines) {
    Juego juego;
    juego.palabraSecreta = palabra.palabra;
    juego.palabraAdivinada = string(palabra.palabra.length(), '_');
    juego.intentosRestantes = 6;
    juego.puntuacion = 0;

    while (juego.intentosRestantes > 0) {
        cout << "Palabra a adivinar: " << juego.palabraAdivinada << endl;
        cout << "Intentos restantes: " << juego.intentosRestantes << endl;

        char letra;
        cout << "Ingresa una letra: ";
        cin >> letra;

        // Comprueba si el jugador tiene comodines disponibles
        if (jugador.comodinDefinicion <= 0 && jugador.comodinSinonimoAntonimo <= 0) {
            cout << "No tienes comodines disponibles." << endl;
            continue;
        }

        bool letraAdivinada = false;
        for (size_t i = 0; i < juego.palabraSecreta.length(); i++) {
            if (juego.palabraSecreta[i] == letra) {
                juego.palabraAdivinada[i] = letra;
                letraAdivinada = true;
            }
        }

        if (!letraAdivinada) {
            juego.intentosRestantes--;
        }

        // Muestra la cantidad de comodines disponibles
        cout << "Comodines disponibles:" << endl;
        cout << "Definici�n: " << jugador.comodinDefinicion << endl;
        cout << "Sin�nimo/Ant�nimo: " << jugador.comodinSinonimoAntonimo << endl;

        bool usoComodin = usarComodin(jugador, comodines);
        if (usoComodin) {
            // Muestra la cantidad de comodines disponibles
            cout << "Comodines disponibles:" << endl;
            cout << "Definici�n: " << jugador.comodinDefinicion << endl;
            cout << "Sin�nimo/Ant�nimo: " << jugador.comodinSinonimoAntonimo << endl;
        }
    }

    if (juego.palabraAdivinada == juego.palabraSecreta) {
        juego.puntuacion = 10; // Puntuaci�n arbitraria para cuando se adivina correctamente
        jugador.rondasGanadas++;
        jugador.puntajeGlobal += juego.puntuacion;
    }

    // Guardar historial de letras ingresadas y palabras adivinadas
    juego.letrasIngresadas.swap(jugador.letrasIngresadas); // Copiar letras a historial global
    jugador.palabrasAdivinadas.splice(jugador.palabrasAdivinadas.end(), juego.palabrasAdivinadas); // Agregar palabras adivinadas a historial global

    return juego.puntuacion > 0;
}


int main() {
    Jugador jugador;
    jugador.nombre = "Nombre"; // Asigna un nombre al jugador
    jugador.puntajeGlobal = 0;
    jugador.rondasGanadas = 0;
    jugador.comodinDefinicion = 2; // Por ejemplo, iniciar con 2 comodines de definici�n
    jugador.comodinSinonimoAntonimo = 3; // Por ejemplo, iniciar con 3 comodines de sin�nimo/ant�nimo

    vector<Comodin> comodines = { {"Definici�n", 5}, {"Sin�nimo/Ant�nimo", 3} };

    Palabra palabra;
    palabra.palabra = "prueba"; // Asigna una palabra para la prueba
    palabra.definicion = "Una prueba";
    palabra.sinonimos.push_back("test");
    palabra.antonimos.push_back("error");

    if (jugarRonda(jugador, palabra, comodines)) {
        cout << "�Has adivinado la palabra!" << endl;
    } else {
        cout << "Se acabaron los intentos. La palabra era: " << palabra.palabra << endl;
    }

    // Mostrar historial de letras ingresadas
    cout << "Letras ingresadas: ";
    while (!jugador.letrasIngresadas.empty()) {
        cout << jugador.letrasIngresadas.top() << " ";
        jugador.letrasIngresadas.pop();
    }
    cout << endl;

    // Mostrar historial de palabras adivinadas
    cout << "Palabras adivinadas:" << endl;
    for (auto& par : jugador.palabrasAdivinadas) {
        cout << "Palabra: " << par.first << ", Definici�n: " << par.second << endl;
    }

    cout << "Puntaje Global: " << jugador.puntajeGlobal << endl;
    cout << "Rondas Ganadas: " << jugador.rondasGanadas << endl;

    return 0;
}
