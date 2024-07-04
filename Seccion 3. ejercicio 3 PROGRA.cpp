#include <iostream>
using namespace std;

// Definici�n de constantes para el tama�o m�ximo de la matriz
const int MAX_FILAS = 10;
const int MAX_COLUMNAS = 10;

// Funci�n para encontrar y mostrar el punto de silla
void encontrarPuntoSilla(float matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas) {
    bool puntoSillaEncontrado = false;

    // Recorrer cada fila de la matriz
    for (int i = 0; i < filas; i++) {
        // Encontrar el �ndice del menor elemento de la fila
        int minColumna = 0;
        for (int j = 1; j < columnas; j++) {
            if (matriz[i][j] < matriz[i][minColumna]) {
                minColumna = j;
            }
        }

        // Verificar si el menor elemento de la fila es el mayor en su columna
        bool esMayorEnColumna = true;
        for (int k = 0; k < filas; k++) {
            if (matriz[k][minColumna] > matriz[i][minColumna]) {
                esMayorEnColumna = false;
                break;
            }
        }

        // Si se encuentra un punto de silla, mostrar la posici�n y terminar la b�squeda
        if (esMayorEnColumna) {
            cout << "Punto de silla encontrado en la posicion (" << i << ", " << minColumna << ") con valor " << matriz[i][minColumna] << endl;
            puntoSillaEncontrado = true;
            break;
        }
    }

    // Si no se encontr� ning�n punto de silla
    if (!puntoSillaEncontrado) {
        cout << "No se encontro ningun punto de silla en la matriz." << endl;
    }
}

int main() {
    int filas, columnas;
    float matriz[MAX_FILAS][MAX_COLUMNAS];

    // Solicitar al usuario el n�mero de filas y columnas
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    // Validar que el tama�o de la matriz no exceda los l�mites
    if (filas > MAX_FILAS || columnas > MAX_COLUMNAS) {
        cout << "El tama�o de la matriz excede los limites permitidos." << endl;
        return 1;
    }

    // Solicitar al usuario los elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }

    // Encontrar y mostrar el punto de silla
    encontrarPuntoSilla(matriz, filas, columnas);

    return 0;
}


