#include <stdio.h>

int main() {
    int numeros[10];
    int i, suma = 0, resta, multiplicacion = 1;
    float division;

    // Leer los 10 números por teclado y almacenarlos en el array
    for (i = 0; i < 10; i++) {
        printf("Introduce el numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

    // Calcular la suma, resta, multiplicación y división de los números
    for (i = 0; i < 10; i++) {
        suma += numeros[i];
        multiplicacion *= numeros[i];
    }
    resta = numeros[0];
    for (i = 1; i < 10; i++) {
        resta -= numeros[i];
    }
    division = (float)numeros[0];
    for (i = 1; i < 10; i++) {
        division /= numeros[i];
    }

    // Mostrar los resultados
    printf("La suma de los numeros es: %d\n", suma);
    printf("La resta de los numeros es: %d\n", resta);
    printf("La multiplicacion de los numeros es: %d\n", multiplicacion);
    printf("La division de los numeros es: %f\n", division);

    return 0;
}
