#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* Funci�n que calcula la transpuesta de una matriz cuadrada de tama�o n.
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
/* Funci�n que verifica si una matriz cuadrada de tama�o n es sim�trica.
Esta matriz es sim�trica si es igual a su transpuesta, o sea, si
A[i][j] es igual a A[j][i] para todos los elementos.
Se recorre toda la matriz comparando cada elemento con su correspondiente en la
posici�n transpuesta. */
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
/* Funci�n que verifica si una matriz cuadrada de tama�o n es antisim�trica.
Una matriz es antisim�trica si es igual a la negaci�n de su transpuesta,
o sea, si A[i][j] es igual a -A[j][i] para todos los elementos. Se
recorre toda la matriz comparando cada elemento con el negativo de su
correspondiente en la posici�n transpuesta. */
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
/* Se verifica si una matriz cuadrada de tama�o n es triangular superior.
Una matriz es triangular superior si todos los elementos por debajo de la
diagonal principal son cero, es decir, si A[i][j] es igual a 0 para todos los
i > j. Se recorre solo la parte inferior de la matriz para verificar esta condici�n.
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
/* A verificar si una matriz cuadrada de tama�o n es triangular inferior.
Una matriz es triangular inferior si todos los elementos por encima de la
diagonal principal son cero, es decir, si A[i][j] es igual a 0 para todos los
i < j.
Se recorre solo la parte superior de la matriz para verificar esta condici�n.
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
 cout << "Men� de opciones:" << endl;
 cout << "1. Transpuesta de A (At)" << endl;
 cout << "2. A es sim�trica o antisim�trica" << endl;
 cout << "3. A es una matriz triangular superior o triangular inferior" << endl;
 cout << "4. Salir" << endl;
 cout << "Ingrese una opci�n: ";
 cin >> opcion;
 /*
 Se pide el tama�o de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Calcula la transpuesta de la matriz utilizando la funci�n 'transpuesta'.
 Libera la memoria asignada.
 */
 if (opcion == 1) {
 int n;
 cout << "Ingrese el tama�o de la matriz nxn: ";
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
 Solicita el tama�o de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Verifica si la matriz es sim�trica o antisim�trica utilizando las funciones
'esSimetrica' y 'esAntisimetrica'.
 Muestra el resultado en consola.
 */
 else if (opcion == 2) {
 int n;
 cout << "Ingrese el tama�o de la matriz nxn: ";
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
 cout << "A es sim�trica." << endl;
 } else if (esAntisimetrica(A, n)) {
 cout << "A es antisim�trica." << endl;
 } else {
 cout << "A no es sim�trica ni antisim�trica." << endl;
 }
 delete[] A;
 }
 /*
 Solicita el tama�o de la matriz nxn al usuario y asigna memoria a la matriz.
 Llena la matriz con valores aleatorios entre 1 y 10 y la imprime en la consola.
 Verifica si la matriz es triangular superior o triangular inferior utilizando las
funciones 'esTriangularSuperior' y 'esTriangularInferior'.
 Muestra el resultado.
 */
 else if (opcion == 3) {
 int n;
 cout << "Ingrese el tama�o de la matriz nxn: ";
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
 cout << "Opci�n no v�lida." << endl;
 }
 }
 return 0;
}
