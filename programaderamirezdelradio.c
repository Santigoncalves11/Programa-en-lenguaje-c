//Realiza un programa en lenguaje c que calcule o ingrese por teclado el radio de un circulo y calcule su radio.

#include <stdio.h>

int main() {
    float area, radio;
    printf("Introduzca el radio: ");
    scanf("%f",&radio);
    area = 3.141592 * radio * radio;
    printf("El area del circulo es: %.2f", area);
    return 0;
}
