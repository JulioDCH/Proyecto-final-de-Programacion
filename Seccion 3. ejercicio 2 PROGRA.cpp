#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void inicializarJuego(char palabra[], char adivinadas[], int &intentos) {
    int len = strlen(palabra);
    for (int i = 0; i < len; i++) {
        adivinadas[i] = '_';
    }
    adivinadas[len] = '\0'; 
    intentos = 6; 
}

void mostrarEstado(char adivinadas[], int intentos) {
    cout << "Palabra: " << adivinadas << endl;
    cout << "Intentos restantes: " << intentos << endl;
}

bool procesarAdivinanza(char palabra[], char adivinadas[], char letra) {
    bool acierto = false;
    int len = strlen(palabra);
    for (int i = 0; i < len; i++) {
        if (tolower(palabra[i]) == tolower(letra)) {
            adivinadas[i] = palabra[i];
            acierto = true;
        }
    }
    return acierto;
}

bool juegoTerminado(char palabra[], char adivinadas[], int intentos) {
    if (strcmp(palabra, adivinadas) == 0) {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabra << endl;
        return true;
    }
    if (intentos <= 0) {
        cout << "Has perdido. La palabra era: " << palabra << endl;
        return true;
    }
    return false;
}

int main() {
    char palabra[100];
    cout << "Jugador 1, ingrese la palabra secreta: ";
    cin >> palabra;

    char adivinadas[100];
    int intentos;
    inicializarJuego(palabra, adivinadas, intentos);

    char letra;
    bool terminado = false;

    while (!terminado) {
        mostrarEstado(adivinadas, intentos);
        cout << "Jugador 2, adivina una letra: ";
        cin >> letra;

        if (!procesarAdivinanza(palabra, adivinadas, letra)) {
            intentos--;
        }

        terminado = juegoTerminado(palabra, adivinadas, intentos);
    }

    return 0;
}

