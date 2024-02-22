//Escribir un programa en C que me permita leer un número decimal que representa una cantidad de grados Celsius y convierta dicho valorar la cantidad equivalente en grados 
//Fahrenheit. La salida de programa puede ser de la forma siguiente: 100 grados Celsius son 212 grados Fahrenheit (investigar fórmula de conversión) ojo hacer todas las 
//validaciones en el programa y usar el ciclo white con respuesta al operador.

#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main() {
    float celsius, fahrenheit;
    char respuesta = 's';

    while (respuesta == 's') {
        printf("Ingrese la cantidad de grados Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 9 / 5) + 32;

        printf("%.2f grados Celsius son %.2f grados Fahrenheit\n", celsius, fahrenheit);

        printf("¿Desea ingresar otra cantidad? (s/n): ");
        scanf(" %c", &respuesta);
    }

    return 0;
}
