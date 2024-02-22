//realizar un programa en lenguaje c llamado vendedores cree un array de 18x10 e indican que poseemos una empresa de 18 vendedores cada uno de los cuales vende 10 producto. El array
//almacena los ingresos obtenidos por cada vendedor en cada producto, de modo que un menu permite almacenar los ingresos, revisar al total de cada vendedor y obtener los ingresos 
//totales.
//1- Sumar la cantidad de articulos por vendedor y almacenarlo en un vector. 
//2- Cual fue el vendedor que obtuvo la menor venta de articulos.
//3- Validar cada una de las opciones e imprimir el resultado de cada actividad. 
//4) Validar en caso que la opcion sea incorrecta. 

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define VENDEDORES 18 // Número de vendedores
#define PRODUCTOS 10 // Número de productos

int main() {
  // Declarar las variables
  float ingresos[VENDEDORES][PRODUCTOS]; // Matriz para almacenar los ingresos de cada vendedor por cada producto
  float total[VENDEDORES]; // Vector para almacenar el total de ingresos de cada vendedor
  int opcion; // Variable para almacenar la opción del menú
  int i, j; // Variables para iterar
  int vendedor; // Variable para almacenar el número de vendedor
  float menor; // Variable para almacenar el menor total de ingresos
  int menor_vendedor; // Variable para almacenar el número del vendedor con el menor total de ingresos

  // Inicializar la matriz y el vector en cero
  for (i = 0; i < VENDEDORES; i++) {
    for (j = 0; j < PRODUCTOS; j++) {
      ingresos[i][j] = 0;
    }
    total[i] = 0;
  }

  // Mostrar el menú hasta que se elija la opción 0
  do {
    printf("Menu de opciones:\n");
    printf("1. Almacenar los ingresos\n");
    printf("2. Revisar el total de cada vendedor\n");
    printf("3. Obtener los ingresos totales\n");
    printf("4. Obtener el vendedor con la menor venta de articulos\n");
    printf("0. Salir\n");
    printf("Introduce tu opcion: ");
    scanf("%d", &opcion);

    // Validar la opción elegida
    if (opcion < 0 || opcion > 4) {
      printf("Opcion invalida.\n");
    } else {
      // Ejecutar la opción elegida
      switch (opcion) {
        case 1:
          // Almacenar los ingresos
          printf("Introduce el numero de vendedor (1 a %d): ", VENDEDORES);
          scanf("%d", &vendedor);
          // Validar el número de vendedor
          if (vendedor < 1 || vendedor > VENDEDORES) {
            printf("Número de vendedor invalido.\n");
          } else {
            // Pedir los ingresos por cada producto
            for (j = 0; j < PRODUCTOS; j++) {
              printf("Introduce el ingreso por el producto %d: ", j + 1);
              scanf("%f", &ingresos[vendedor - 1][j]);
            }
            printf("Ingresos almacenados correctamente.\n");
          }
          break;
        case 2:
          // Revisar el total de cada vendedor
          printf("Introduce el número de vendedor (1 a %d): ", VENDEDORES);
          scanf("%d", &vendedor);
          // Validar el número de vendedor
          if (vendedor < 1 || vendedor > VENDEDORES) {
            printf("Número de vendedor inválido.\n");
          } else {
            // Calcular el total de ingresos del vendedor
            total[vendedor - 1] = 0;
            for (j = 0; j < PRODUCTOS; j++) {
              total[vendedor - 1] += ingresos[vendedor - 1][j];
            }
            // Mostrar el total de ingresos del vendedor
            printf("El total de ingresos del vendedor %d es: %.2f\n", vendedor, total[vendedor - 1]);
          }
          break;
        case 3:
          // Obtener los ingresos totales
          // Mostrar los ingresos de cada vendedor por cada producto
          printf("Ingresos de cada vendedor por cada producto:\n");
          for (i = 0; i < VENDEDORES; i++) {
            printf("Vendedor %d: ", i + 1);
            for (j = 0; j < PRODUCTOS; j++) {
              printf("%.2f ", ingresos[i][j]);
            }
            printf("\n");
          }
          // Mostrar el total de ingresos de cada vendedor
          printf("Total de ingresos de cada vendedor:\n");
          for (i = 0; i < VENDEDORES; i++) {
            printf("Vendedor %d: %.2f\n", i + 1, total[i]);
          }
          break;
        case 4:
          // Obtener el vendedor con la menor venta de artículos
          // Inicializar el menor total de ingresos con el primer vendedor
          menor = total[0];
          menor_vendedor = 1;
          // Recorrer el vector de totales para encontrar el menor
          for (i = 1; i < VENDEDORES; i++) {
            if (total[i] < menor) {
              menor = total[i];
              menor_vendedor = i + 1;
            }
          }
          // Mostrar el vendedor con la menor venta de artículos
          printf("El vendedor con la menor venta de artículos es el %d con %.2f de ingresos.\n", menor_vendedor, menor);
          break;
        case 0:
          // Salir
          printf("Gracias por usar el programa.\n");
          break;
      }
    }
  } while (opcion != 0);

  return 0;
}
