#include <stdio.h>

// Definición de las funciones
void suma(int *a, int b) {
    *a = *a + b;
}

void resta(int *a, int b) {
    *a = *a - b;
}

void multiplica(int *a, int b) {
    *a = *a * b;
}

void divide(int *a, int b) {
    if (b != 0) {
        *a = *a / b;
    } else {
        printf("Error: División por cero\n");
    }
}

int main() {
    int matriz[2][2] = {{1, 2}, {3, 4}};
    int i, j;

    // Realizar las operaciones en cada elemento de la matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            suma(&matriz[i][j], 1);
            resta(&matriz[i][j], 1);
            multiplica(&matriz[i][j], 2);
            divide(&matriz[i][j], 2);
        }
    }

    // Imprimir la matriz
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

