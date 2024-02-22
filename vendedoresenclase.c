// Dado el siguiente programa en lenguaje c
//A) Cargar simultáneamente los nombres de los vendedores en un vector y la cantidad de artículos vendida por vendedor en una matriz
//B) Sumar la cantidad de artículos por vendedor y almacenarlos en un vector.                 
//C) Cual fue el vendedor que mas obtuvo menor venta de artículos.                                                     
//D) Copiar la cantidad de los artículos en un vector.                                                                 
//E) Utilizar el ciclo while con respuesta al operador.                                                                     
//F) Validar todas las variables e imprimir los requerimientos anteriores.
// A continuación se presenta el programa en lenguaje C que resuelve los requerimientos planteados:

#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_VENDEDORES 18
#define MAX_ARTICULOS 10

int main() {
    char vendedores[MAX_VENDEDORES][18];
    int articulos[MAX_VENDEDORES][MAX_ARTICULOS];
    int total_articulos[MAX_VENDEDORES];
    int i, j, max_articulos, min_articulos, vendedor_max, vendedor_min;
    int copia_articulos[MAX_VENDEDORES];

    // Cargar nombres de vendedores y cantidad de artículos vendidos por vendedor
    printf("Ingrese los nombres de los vendedores y la cantidad de articulos vendidos por vendedor:\n");
    for (i = 0; i < MAX_VENDEDORES; i++) {
        printf("Vendedor %d: ", i+1);
        scanf("%s", vendedores[i]);
        for (j = 0; j < MAX_ARTICULOS; j++) {
            printf("Cantidad de articulos vendidos por %s en el articulo %d: ", vendedores[i], j+1);
            scanf("%d", &articulos[i][j]);
        }
    }

    // Sumar cantidad de articulos por vendedor y almacenarlos en un vector
    for (i = 0; i < MAX_VENDEDORES; i++) {
        total_articulos[i] = 0;
        for (j = 0; j < MAX_ARTICULOS; j++) {
            total_articulos[i] += articulos[i][j];
        }
    }

    // Encontrar vendedor con mayor cantidad de articulos vendidos y menor venta de artículos
    max_articulos = total_articulos[0];
    min_articulos = total_articulos[0];
    vendedor_max = 0;
    vendedor_min = 0;
    for (i = 1; i < MAX_VENDEDORES; i++) {
        if (total_articulos[i] > max_articulos) {
            max_articulos = total_articulos[i];
            vendedor_max = i;
        }
        if (total_articulos[i] < min_articulos) {
            min_articulos = total_articulos[i];
            vendedor_min = i;
        }
    }

    // Copiar cantidad de articulos en un vector
    memcpy(copia_articulos, total_articulos, sizeof(total_articulos));

    // Utilizar ciclo while con respuesta al operador
    char respuesta;
    do {
        printf("¿Desea ver la cantidad de articulos vendidos por cada vendedor? (s/n): ");
        scanf(" %c", &respuesta);
        if (respuesta == 's') {
            for (i = 0; i < MAX_VENDEDORES; i++) {
                printf("El vendedor %s vendio %d articulos\n", vendedores[i], total_articulos[i]);
            }
        }
    } while (respuesta != 'n');

    // Imprimir resultados
    printf("El vendedor que mas articulos vendió fue %s con %d articulos vendidos\n", vendedores[vendedor_max], max_articulos);
    printf("El vendedor que menos articulos vendió fue %s con %d articulos vendidos\n", vendedores[vendedor_min], min_articulos);
    printf("Copia de la cantidad de articulos vendidos por vendedor:\n");
    for (i = 0; i < MAX_VENDEDORES; i++) {
        printf("%d ", copia_articulos[i]);
    }
    printf("\n");

    return 0;
}
