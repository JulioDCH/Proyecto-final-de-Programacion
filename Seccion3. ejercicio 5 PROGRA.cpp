#include <iostream>
using namespace std;
// Función para leer una matriz
void leerMatriz(int* matriz, int filas, int columnas) {
    cout << "Introduce los elementos de la matriz:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> *(matriz + i * columnas + j);
        }
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(int* matriz1, int filas1, int columnas1, int* matriz2, int filas2, int columnas2, int* resultado) {
    for (int i = 0; i < filas1; i++) {
        for (int j = 0; j < columnas2; j++) {
            *(resultado + i * columnas2 + j) = 0; // Inicializar el elemento de la matriz resultado
            for (int k = 0; k < columnas1; k++) {
                *(resultado + i * columnas2 + j) += *(matriz1 + i * columnas1 + k) * *(matriz2 + k * columnas2 + j);
            }
        }
    }
}

// Función para imprimir una matriz
void imprimirMatriz(int* matriz, int filas, int columnas) {
    cout << "Matriz resultante:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << *(matriz + i * columnas + j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int filas1, columnas1, filas2, columnas2;

    cout << "Introduce las dimensiones de la primera matriz (filas y columnas): ";
    cin >> filas1 >> columnas1;

    cout << "Introduce las dimensiones de la segunda matriz (filas y columnas): ";
    cin >> filas2 >> columnas2;

    // Verificar si las matrices se pueden multiplicar
    if (columnas1 != filas2) {
        cout << "No se pueden multiplicar las matrices." << endl;
        return 1;
    }

    // Reservar memoria para las matrices
    int* matriz1 = new int[filas1 * columnas1];
    int* matriz2 = new int[filas2 * columnas2];
    int* resultado = new int[filas1 * columnas2];

    // Leer las matrices
    cout << "Matriz 1:" << endl;
    leerMatriz(matriz1, filas1, columnas1);

    cout << "Matriz 2:" << endl;
    leerMatriz(matriz2, filas2, columnas2);

    // Multiplicar las matrices
    multiplicarMatrices(matriz1, filas1, columnas1, matriz2, filas2, columnas2, resultado);

    // Imprimir la matriz resultante
    imprimirMatriz(resultado, filas1, columnas2);

    // Liberar la memoria reservada
    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;

    return 0;
}

