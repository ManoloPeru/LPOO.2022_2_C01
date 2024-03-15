#include <iostream>

using namespace std;

/* Maximo, 40 numeros de Fibonacci */
const int MAX = 40;

// Funci�n para generar los primeros 100 n�meros de Fibonacci
void generarFibonacci(int fib[]) {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAX; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Funci�n para ordenar un array en orden ascendente
void reOrdenarCreciente(int arregloNumero[], int n, char palabra[]) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arregloNumero[j] < arregloNumero[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int numero = arregloNumero[i];
            arregloNumero[i] = arregloNumero[minIndex];
            arregloNumero[minIndex] = numero;
            
            char caracter = palabra[i];
            palabra[i] = palabra[minIndex];
            palabra[minIndex] = caracter;
        }
    }
}

// Funci�n para imprimir un array de n�meros
void imprimirNumeros(int arregloNumero[], int n) {
    cout << "Array de numeros: ";
    for (int i = 0; i < n; ++i) {
        cout << arregloNumero[i] << " ";
    }
    cout << endl;
}

// Funci�n para imprimir un array de caracteres
void imprimirPalabra(char palabra[], int n, int arregloNumero[]) {
    int fibonacci[MAX];
    int j = 0;

    // Generar los primeros 100 n�meros de Fibonacci
    generarFibonacci(fibonacci);

    cout << "La palabra decodificada es: ";
    for (int i = 1; i <= MAX; ++i) {
        if (fibonacci[i] == arregloNumero[j])
        {
            if (j > n)
            {
                break; //Terminamos
            }
            cout << palabra[j];
            j++;
        }
        else
        {
            cout << " ";
        }
    }
    cout << endl;
}

// Funci�n para decodificar la palabra
void decodificarPalabra(int numeros[], int n, char palabra[]) {
    // Ordenar los n�meros de Fibonacci y la palabra a decodificar
    reOrdenarCreciente(numeros, n, palabra);
    // Imprimir el array de n�meros
    imprimirNumeros(numeros, n);
    // Imprimir la palabra
    imprimirPalabra(palabra, n, numeros);
}

int main() {
    int n;
    cout << "Ingrese la cantidad de numeros de Fibonacci: ";
    cin >> n;

    // Leer los n�meros de Fibonacci
    int numeros[100]; // Suponemos que habr� como m�ximo 100 n�meros
    cout << "Ingrese los " << n << " numeros de Fibonacci: ";
    for (int i = 0; i < n; ++i) {
        cin >> numeros[i];
    }

    // Leer la palabra codificada
    char palabra[100]; // Suponemos que habr� como m�ximo 100 caracteres
    cout << "Ingrese la palabra codificada (use '*' para indicar el fin de la palabra): ";
    char c;
    int index = 0;
    while (cin >> c && c != '*') {
        palabra[index++] = c;
    }
    palabra[index] = '\0'; // Agregar el car�cter nulo al final del array

    // Decodificar y mostrar la palabra
    decodificarPalabra(numeros, n, palabra);

    return 0;
}
