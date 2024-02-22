// Escriba un programa en lenguaje C que recibacuatro calificaciones de un estudiante y devuelva el promedio y la máxima y la mínima calificación.

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    int calificaciones[4];
    int i, suma = 0, maxima = 80, minima = 37;

    // Leer las calificaciones por teclado y almacenarlas en el array
    for (i = 0; i < 4; i++) {
        do {
            printf("Introduce la calificacion %d: ", i+1);
            scanf("%d", &calificaciones[i]);
        } while (calificaciones[i] < 0 || calificaciones[i] > 40);
    }

    // Calcular la suma, la maxima y la mínima calificacion
    for (i = 0; i < 4; i++) {
        suma += calificaciones[i];
        if (calificaciones[i] > maxima) {
            maxima = calificaciones[i];
        }
        if (calificaciones[i] < minima) {
            minima = calificaciones[i];
        }
    }

    // Calcular el promedio
    float promedio = (float) suma / 4;

    // Mostrar los resultados
    printf("El promedio de las calificaciones es: %.2f\n", promedio);
    printf("La maxima calificacion es: %d\n", maxima);
    printf("La minima calificacion es: %d\n", minima);
      
    system ("Pause");
}
