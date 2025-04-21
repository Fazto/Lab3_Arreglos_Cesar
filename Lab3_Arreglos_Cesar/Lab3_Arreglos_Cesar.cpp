#include <iostream>
using namespace std;

void ingresarNumeros(int arr[], int tam) {
    cout << "Ingresa " << tam << " numeros enteros:\n";
    for (int i = 0; i < tam; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }
}

float calcularPromedio(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return static_cast<float>(suma) / tam;
}

int copiarMayoresAlPromedio(int origen[], int tam, float promedio, int destino[]) {
    int j = 0;
    for (int i = 0; i < tam; i++) {
        if (origen[i] > promedio) {
            destino[j++] = origen[i];
        }
    }
    return j;
}

void imprimirArreglo(int arr[], int tam, string mensaje) {
    cout << mensaje;
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ordenarDescendente(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    const int TAM = 15;
    int numeros[TAM];
    int mayores[TAM];
    int cantidadMayores;

    ingresarNumeros(numeros, TAM);
    float promedio = calcularPromedio(numeros, TAM);
    cantidadMayores = copiarMayoresAlPromedio(numeros, TAM, promedio, mayores);
    ordenarDescendente(mayores, cantidadMayores);

    imprimirArreglo(numeros, TAM, "\nArreglo original: ");
    cout << "Promedio: " << promedio << endl;
    imprimirArreglo(mayores, cantidadMayores, "Valores mayores al promedio (ordenados): ");

    return 0;
}
