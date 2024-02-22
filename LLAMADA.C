#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
int main() {
    char nombre[50];
    char numero[20];
    int minutos;
    int costo_por_minuto = 8;
    int costo_total;

    // Solicitar los datos al usuario
    printf("Introduce el nombre: ");
    scanf("%s", nombre);
    printf("Introduce el numero telefonico: ");
    scanf("%s", numero);
    printf("Introduce la cantidad de minutos: ");
    scanf("%d", &minutos);
    
    // Calcular el costo total de la llamada
    costo_total = minutos * costo_por_minuto;

    // Imprimir el nombre de la persona y el costo de la llamada
    printf("El costo de la llamada de %s es %d Bs Digitales\n", nombre, costo_total);

    return 0;
}

