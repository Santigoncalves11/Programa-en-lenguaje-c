#include <stdio.h>

int main() {
    float Pi = 3.14, area, circuferencia, radio;
    
    // Solicite al usuario que ingrese el radio del c�rculo.
    printf("Introduzca el radio del c�rculo: ");
    
    // Almacene la entrada del usuario en un radio variable.
    scanf("%f", &radio);
    
    // Calcula e imprime el �rea del c�rculo.
    area = Pi * radio * radio;
    printf("El area del c�rculo es: %f\n", area);
    
    // Calcular e imprimir la circunferencia del c�rculo.
    circunferencia = 2 * Pi * radio;
    printf(" circunferencia del c�rculo es: %f\n", circunferencia);
    
    return 0;
}
