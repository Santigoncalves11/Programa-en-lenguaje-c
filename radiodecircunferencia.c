#include <stdio.h>

int main() {
    float Pi = 3.14, area, circuferencia, radio;
    
    // Solicite al usuario que ingrese el radio del círculo.
    printf("Introduzca el radio del círculo: ");
    
    // Almacene la entrada del usuario en un radio variable.
    scanf("%f", &radio);
    
    // Calcula e imprime el área del círculo.
    area = Pi * radio * radio;
    printf("El area del círculo es: %f\n", area);
    
    // Calcular e imprimir la circunferencia del círculo.
    circunferencia = 2 * Pi * radio;
    printf(" circunferencia del círculo es: %f\n", circunferencia);
    
    return 0;
}
