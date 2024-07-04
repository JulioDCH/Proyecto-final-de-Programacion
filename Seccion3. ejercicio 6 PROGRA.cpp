#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* Función que calcula la transpuesta de una matriz cuadrada de tamaño n.
Se intercambian los elementos por encima y por debajo de la diagonal principal.
Esto se hace utilizando un bucle anidado que recorre
solo los elementos por encima de la diagonal principal y los intercambia con
los correspondientes elementos por debajo de esta. */
void transpuesta(int* A, int n) {
 cout << "Matriz At:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 cout << *(A + j * n + i) << " ";
 }
 cout << endl;
 }
}
/* Función que verifica si una matriz cuadrada de tamaño n es simétrica.
Esta matriz es simétrica si es igual a su transpuesta, o sea, si
A[i][j] es igual a A[j][i] para todos los elementos.
Se recorre toda la matriz comparando cada elemento con su correspondiente en la
posición transpuesta. */
bool esSimetrica(int* A, int n) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if (*(A + i * n + j) != *(A + j * n + i)) {
 return false;
 }
 }
 }
 return true;
}
/* Función que verifica si una matriz cuadrada de tamaño n es antisimétrica.
Una matriz es antisimétrica si es igual a la negación de su transpuesta,
o sea, si A[i][j] es igual a -A[j][i] para todos los elementos. Se
recorre toda la matriz comparando cada elemento con el negativo de su
correspondiente en la posición transpuesta. */
bool esAntisimetrica(int* A, int n) {
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 if ((A + i * n + j) != -(A + j * n + i)) {
 return false;
 }
 }
 }
 return true;
}
/* Se verifica si una matriz cuadrada de tamaño n es triangular superior.
Una matriz es triangular superior si todos los elementos por debajo de la
diagonal principal son cero, es decir, si A[i][j] es igual a 0 para todos los
i > j. Se recorre solo la parte inferior de la matriz para verificar esta condición.
*/
bool esTriangularSuperior(int* A, int n) {
 for (int i = 1; i < n; i++) {
 for (int j = 0; j < i; j++) {
 if (*(A + i * n + j) != 0) {
 return false;
 }
 }
 }
 return true;
}
/* A verificar si una matriz cuadrada de tamaño n es triangular inferior.
Una matriz es triangular inferior si todos los elementos por encima de la
diagonal principal son cero, es decir, si A[i][j] es igual a 0 para todos los
i < j.
Se recorre solo la parte superior de la matriz para verificar esta condición.
 */
bool esTriangularInferior(int* A, int n) {
 for (int i = 0; i < n; i++) {
 for (int j = i + 1; j < n; j++) {
 if (*(A + i * n + j) != 0) {
 return false;
 }
 }
 }
 return true;
}
int main() {
 srand(time(0)); // Generamos numeros aleatorios
 int opcion;
 while (true) {
 cout << "Menú de opciones:" << endl;
 cout << "1. Transpuesta de A (At)" << endl;
 cout << "2. A es simétrica o antisimétrica" << endl;
 cout << "3. A es una matriz triangular superior o triangular inferior" << endl;
 cout << "4. Salir" << endl;
 cout << "Ingrese una opción: ";
 cin >> opcion;
 /*
 Se pide el tamaño de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Calcula la transpuesta de la matriz utilizando la función 'transpuesta'.
 Libera la memoria asignada.
 */
 if (opcion == 1) {
 int n;
 cout << "Ingrese el tamaño de la matriz nxn: ";
 cin >> n;
 int* A = new int[n * n];
 cout << "Matriz A:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 *(A + i * n + j) = rand() % 10 + 1;
 cout << *(A + i * n + j) << " ";
 }
 cout << endl;
 }
 transpuesta(A, n);
 delete[] A;
 }
 /*
 Solicita el tamaño de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Verifica si la matriz es simétrica o antisimétrica utilizando las funciones
'esSimetrica' y 'esAntisimetrica'.
 Muestra el resultado en consola.
 */
 else if (opcion == 2) {
 int n;
 cout << "Ingrese el tamaño de la matriz nxn: ";
 cin >> n;
 int* A = new int[n * n];
 cout << "Matriz A:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 *(A + i * n + j) = rand() % 10 + 1;
 cout << *(A + i * n + j) << " ";
 }
 cout << endl;
 }
 if (esSimetrica(A, n)) {
 cout << "A es simétrica." << endl;
 } else if (esAntisimetrica(A, n)) {
 cout << "A es antisimétrica." << endl;
 } else {
 cout << "A no es simétrica ni antisimétrica." << endl;
 }
 delete[] A;
 }
 /*
 Solicita el tamaño de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Verifica si la matriz es triangular superior o triangular inferior utilizando las
funciones 'esTriangularSuperior' y 'esTriangularInferior'.
 Muestra el resultado.
 */
 else if (opcion == 3) {
 int n;
 cout << "Ingrese el tamaño de la matriz nxn: ";
 cin >> n;
 int* A = new int[n * n];
 cout << "Matriz A:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 *(A + i * n + j) = rand() % 10 + 1;
 cout << *(A + i * n + j) << " ";
 }
 cout << endl;
 }
 if (esTriangularSuperior(A, n)) {
 cout << "A es una matriz triangular superior." << endl;
 } else if (esTriangularInferior(A, n)) {
 cout << "A es una matriz triangular inferior." << endl;
 } else {
 cout << "A no es una matriz triangular." << endl;
 }
 delete[] A;
 } else if (opcion == 4) {
 break;
 } else {
 cout << "Opción no válida." << endl;
 }
 }
 return 0;
}
