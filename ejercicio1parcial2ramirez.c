// Costar letra repetivas, crear un programa en lenguaje c que cree un array de 50 letras mayusculas aleatorias y que cueste cuantas veces aparece las letras en el array.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int i = 0;

int main() {
    
    // Generar números aleatorios
    
    srand(time(NULL));

    // Crear un array de 50 letras mayúsculas aleatorias
    
    char letras[50];

    for (i = 0; i < 50; i++) { // Recorrer el array de letras
        letras[i] = 'A' + rand() % 26; // Genera una letra aleatoria entre 'A' y 'Z'
    }

    // Imprimir el array de letras
    
    printf("Array de letras: ");
    for (i = 0; i < 50; i++) { // Recorrer el array de letras.
        printf("%c ", letras[i]); // Imprimir la letra.
    }
    printf("\n");
    
    // Contar la frecuencia de cada letra.

    int frecuencia[26] = {0}; // Inicializar el array de frecuencia a 0 en todas las posiciones.

    for (i = 0; i < 50; i++) { // Recorrer el array de letras.
        char letra = letras[i]; // Obtener la letra actual.
        frecuencia[letra - 'A']++; // Incrementar la frecuencia de la letra correspondiente en el array de frecuencia.
    }

    // Imprimir la frecuencia de cada letra.
    
    printf("Frecuencia de cada letra:\n"); // Imprimir la frecuencia de cada letra.
    for (i = 0; i < 26; i++) { // Recorrer el array de frecuencia. 
        printf("%c: %d\n", 'A' + i, frecuencia[i]); // Imprimir la letra y su frecuencia.
    }

    system("pause>nul"); // Pausar el programa antes de salir
    
    return 0;
}

