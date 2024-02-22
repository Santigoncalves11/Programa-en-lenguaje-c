//En una tienda de artículos para caballeros al final del día se carga en lacomputadora las boletas que confeccionaron los distintos vendedores para saber cuánto fue la comisión del día
//de cada uno de ellos. Los datos que se ingresan (por boleta) son: el número del vendedor y el importe. Cuando no hay más boletas para cargar se ingresa 0. Teniendo en cuenta que el
//negocio tiene 3 vendedores y que el porcentaje sobre las ventas es del 5%, indicar cuánto ganó cada vendedor al día.

#include <stdio.h>

int main() {
  // Declarar las variables
  int num_vendedor; // Número del vendedor
  float importe; // Importe de la boleta
  float comision; // Comisión del vendedor
  float ventas[3]; // Arreglo para almacenar las ventas de cada vendedor
  int i; // Variable para iterar

  // Inicializar el arreglo de ventas en cero
  for (i = 0; i < 3; i++) {
    ventas[i] = 0;
  }

  // Pedir los datos al usuario hasta que se ingrese 0
  printf("Introduce el número del vendedor y el importe de la boleta (0 para terminar): ");
  scanf("%d %f", &num_vendedor, &importe);

  while (num_vendedor != 0) {
    // Validar que el número del vendedor sea válido
    if (num_vendedor < 1 || num_vendedor > 3) {
      printf("Número de vendedor inválido.\n");
    } else {
      // Acumular el importe en el arreglo de ventas según el número de vendedor
      ventas[num_vendedor - 1] += importe;
    }

    // Pedir los datos al usuario nuevamente
    printf("Introduce el número del vendedor y el importe de la boleta (0 para terminar): ");
    scanf("%d %f", &num_vendedor, &importe);
  }

  // Calcular y mostrar la comisión de cada vendedor
  for (i = 0; i < 3; i++) {
    // Calcular la comisión como el 5% de las ventas
    comision = ventas[i] * 0.05;
    // Mostrar el resultado con dos decimales
    printf("El vendedor %d ganó %.2f de comisión.\n", i + 1, comision);
  }

  return 0;
}
