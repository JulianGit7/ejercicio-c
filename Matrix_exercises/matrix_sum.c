#include <stdio.h>

int main() {
    // Declaramos una matriz de enteros de 2x2
    int matrix[2][2] = {{5, 12}, {7, 3}};
    int sum = 0;

    // Recorremos la matriz usando nombres claros en inglés
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 2; col++) {
            sum += matrix[row][col]; // Vamos sumando cada elemento
        }
    }

    // Mostramos el resultado
    printf("The sum of all elements in the matrix is: %d\n", sum);

    return 0;
}