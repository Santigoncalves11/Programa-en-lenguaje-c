//Ingrese por teclado los siguientes datos de producto de una llamada telefonica nombre,numero,telefonico y cantidad de minutos como entero se pide:
//calcular el costo de la llamada telefonica el precio es de 8bs digitales implimir en pantalla el nombre de las personas con el costo de la llamada.

#include <stdio.h>
#include <conio.h>

int main() {
    char name[20];
    int minutos;
    float costantes, saldo, opcion;
     
    printf("Bienvenido su linea telefonico.\n");
    printf("Su saldo actual es de %0.8f bolivares fuertes.\n",saldo);

    do {
        printf("Ingrese una opcion:\n");
        printf("1. Consulta saldo.\n");
        printf("2. Mensaje.\n");
        printf("3. Deposito.\n");
        printf("4. LLamada.\n");
        printf("5. Salir.\n");
    }
    
    printf("Introduce el numero de la persona:");
    scanf("%s",nombre);

    printf("Ingrese el n�mero de minutos de la llamada telef�nica:");
    scanf("%d", &minutes);

    costantes = minutes* 8.0;

    printf("%sEl costo de la llamada telef�nica es %.8f bol�vares digitales.\n", nombre, costantes);
      
    return 0;
}
