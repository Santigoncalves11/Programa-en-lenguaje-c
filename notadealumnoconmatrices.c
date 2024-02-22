//Realizar un programa en lenguaje c, que gestiona 4 notas de una clase de 5 alumnos de los cuales deben ingresar por teclado el nombre y la nota. El
//programa deben ser capaz de:

//A) Cargar simultaneamente los nombre de los alumnos en un vector y la cantidad de notas por alumno en una matriz. 
//B) Buscar un alumno.
//C) Modificar su nota.
//D) Realizar la media de todas las notas. 
//E) Realizar la media de las notas menores de 5. 
//F) Mostrar el alumno que mmejores notas ha sacado.
//G) Mostrar el alumno que peores notas ha sacado.
//H) Sacar el promedio de notas de todos los alumnos y almacenarlo en un vector. //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int buscar_alumno(char nombres[][50], int cantidad_alumnos, char alumno_buscar[50]);
void modificar_nota(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], float nota_nueva);
float calcular_media(float notas[], int cantidad_notas);
float calcular_media_menor_a_cinco(float notas[], int cantidad_notas);
void mostrar_mejores_y_peores_notas(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]);
void calcular_promedio_notas_alumnos(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]);

int main() {
    int cantidad_alumnos = 5;
    int cantidad_notas = 4;
    char nombres[5][50];
    float matriz_notas[5][4];
    float promedios[5];

    // A) Cargar simultaneamente los nombre de los alumnos en un vector y la cantidad de notas por alumno en una matriz.
    for(int i = 0; i < cantidad_alumnos; i++) {
        printf("Ingrese el nombre del alumno %d: ", i+1);
        scanf("%s", nombres[i]);
        for(int j = 0; j < cantidad_notas; j++) {
            printf("Ingrese la nota %d del alumno %s: ", j+1, nombres[i]);
            scanf("%f", &matriz_notas[i][j]);
        }
    }

    // B) Buscar un alumno.
    char alumno_buscar[50];
    printf("Ingrese el nombre del alumno a buscar: ");
    scanf("%s", alumno_buscar);
    int indice_alumno = buscar_alumno(nombres, cantidad_alumnos, alumno_buscar);

    // C) Modificar su nota.
    if(indice_alumno != -1) {
        float nota_nueva;
        printf("Ingrese la nueva nota para el alumno %s: ", nombres[indice_alumno]);
        scanf("%f", &nota_nueva);
        modificar_nota(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, alumno_buscar, nota_nueva);
    }

    // D) Realizar la media de todas las notas.
    float media_todas_notas = calcular_media(matriz_notas[0], cantidad_alumnos * cantidad_notas);
    printf("La media de todas las notas es: %.2f\n", media_todas_notas);

    // E) Realizar la media de las notas menores de 5.
    float media_notas_menores_a_cinco = calcular_media_menor_a_cinco(matriz_notas[0], cantidad_alumnos * cantidad_notas);
    printf("La media de las notas menores de 5 es: %.2f\n", media_notas_menores_a_cinco);

    // F) Mostrar el alumno que mmejores notas ha sacado.
    // G) Mostrar el alumno que peores notas ha sacado.
    mostrar_mejores_y_peores_notas(nombres, cantidad_alumnos, cantidad_notas, matriz_notas);

    // H) Sacar el promedio de notas de todos los alumnos y almacenarlo en un vector.
    calcular_promedio_notas_alumnos(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);

    // I) Mostrar los promedios de notas de todos los alumnos.
    for(int i = 0; i < cantidad_alumnos; i++) {
        printf("El promedio de notas del alumno %s es: %.2f\n", nombres[i], promedios[i]);
    }

    return 0;
}

int buscar_alumno(char nombres[][50], int cantidad_alumnos, char alumno_buscar[50]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            return i;
        }
    }
    return -1;
}

void modificar_nota(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], float nota_nueva) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            for(int j = 0; j < cantidad_notas; j++) {
                matriz_notas[i][j] = nota_nueva;
            }
            break;
        }
    }
}

float calcular_media(float notas[], int cantidad_notas) {
    float suma = 0;
    for(int i = 0; i < cantidad_notas; i++) {
        suma += notas[i];
    }
    return suma / cantidad_notas;
}

float calcular_media_menor_a_cinco(float notas[], int cantidad_notas) {
    int contador = 0;
    float suma = 0;
    for(int i = 0; i < cantidad_notas; i++) {
        if(notas[i] < 5) {
            suma += notas[i];
            contador++;
        }
    }
    if(contador > 0) {
        return suma / contador;
    } else {
        return 0;
    }
}

    void mostrar_mejores_y_peores_notas(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]) {
    float mejor_nota = matriz_notas[0][0];
    float peor_nota = matriz_notas[0][0];
    int indice_mejor_nota = 0;
    int indice_peor_nota = 0;

    for(int i = 0; i < cantidad_alumnos; i++) {
        float promedio_actual = calcular_media(matriz_notas[i], cantidad_notas);
        if(promedio_actual > mejor_nota) {
            mejor_nota = promedio_actual;
            indice_mejor_nota = i;
        }
        if(promedio_actual < peor_nota) {
            peor_nota = promedio_actual;
            indice_peor_nota = i;
        }
    }
    
    printf("El alumno que mejor nota ha sacado es %s con una media de %.2f.\n", nombres[indice_mejor_nota], mejor_nota);
    printf("El alumno que peor nota ha sacado es %s con una media de %.2f.\n", nombres[indice_peor_nota], peor_nota);
}

void calcular_promedio_notas_alumnos(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        promedios[i] = calcular_media(matriz_notas[i], cantidad_notas);
    }
}

int buscar_alumno(char nombres[][50], int cantidad_alumnos, char alumno_buscar[50]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrar_alumno(char nombres[][50], int cantidad_alumnos, int indice_alumno) {
    printf("El alumno con índice %d es %s.\n", indice_alumno, nombres[indice_alumno]);
}

void mostrar_alumnos(char nombres[][50], int cantidad_alumnos) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        printf("El alumno con índice %d es %s.\n", i, nombres[i]);
    }
}

void mostrar_matriz_notas(float matriz_notas[][4], int cantidad_alumnos, int cantidad_notas) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        for(int j = 0; j < cantidad_notas; j++) {
            printf("%.2f ", matriz_notas[i][j]);
        }
        printf("\n");
    }
}

void modificar_nota(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], float nota_nueva) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            for(int j = 0; j < cantidad_notas; j++) {
                matriz_notas[i][j] = nota_nueva;
            }
            break;
        }
    }
}

void calcular_media_menor_a_cinco(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        float media = calcular_media_menor_a_cinco(matriz_notas[i], cantidad_notas);
        printf("La media de notas menores a 5 del alumno %s es: %.2f\n", nombres[i], media);
    }
}

void calcular_media_menor_a_seis(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        float media = calcular_media_menor_a_cinco(matriz_notas[i], cantidad_notas);
        printf("La media de notas menores a 6 del alumno %s es: %.2f\n", nombres[i], media);
    }
}

void mostrar_matriz_notas_y_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]) {
    printf("Nombres\t\t\t\t\tNotas\t\t\t\tPromedios\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        printf("%s\t\t\t\t", nombres[i]);
        for(int j = 0; j < cantidad_notas; j++) {
            printf("%.2f ", matriz_notas[i][j]);
        }
        printf("\t\t%.2f\n", promedios[i]);
    }
}

float calcular_media(float notas[], int cantidad_notas) {
    float suma = 0;
    for(int i = 0; i < cantidad_notas; i++) {
        suma += notas[i];
    }
    return suma / cantidad_notas;
}

float calcular_media_menor_a_cinco(float notas[], int cantidad_notas) {
    int contador = 0;
    float suma = 0;
    for(int i = 0; i < cantidad_notas; i++) {
        if(notas[i] < 5) {
            suma += notas[i];
            contador++;
        }
    }
    if(contador > 0) {
        return suma / contador;
    } else {
        return -1;
    }
}

float calcular_media_menor_a_seis(float notas[], int cantidad_notas) {
    int contador = 0;
    float suma = 0;
    for(int i = 0; i < cantidad_notas; i++) {
        if(notas[i] < 6) {
            suma += notas[i];
            contador++;
        }
    }
    if(contador > 0) {
        return suma / contador;
    } else {
        return -1;
    }
}

void calcular_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        promedios[i] = calcular_media(matriz_notas[i], cantidad_notas);
    }
}

void cambiar_nota_y_calcular_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], int posicion_nota, float nota_nueva, float promedios[]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(str }
}

void calcular_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]) {
    forcmp(nombres[i], alumno_buscar) == 0) {
            matriz_notas[i][posicion_nota] = nota_nueva;
            break;
        }
    }
    calcular_promedios(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);
}

void imprimir_matriz_notas(char nombres[][50], int cantidad_alumn(int i = 0; i < cantidad_alumnos; i++) {
        promedios[i] = calcular_media(matos, int cantidad_notas, float matriz_notas[][4]) {
    printf("Nombres\t\t\t\t\tNotas\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        printf("%s\t\t\t\t", nombres[i]);
        for(int j = 0; j < cantidad_notas; j++) {
            printf("%.2f ", matriz_notas[i][j]);
        }
        printf("\n");
    }
riz_notas[i], cantidad_notas);
    }
}

void eliminar_notas_menores_a_cinco(char nombres[][}

void modificar_nota(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], int posicion_nota, float nota_nueva) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            matriz_notas[i][posicion_nota] = nota_nueva;
            break;
        }
   50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]) {
    for(int i = 0 }
}

void modificar_nota_y_calcular_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], int posicion_nota, float nota_nueva, float promedios[]) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            matriz_notas[i][posicion_nota] = nota_nueva;
            break; i < cantidad_alumnos; i++) {
        for(int j = 0; j < cantidad_notas; j++) {
            if(;
        }
    }
    calcular_promedios(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);
}

void modificar_todas_las_notas(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], float nota_nueva) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
matriz_notas[i][j] < 5) {
                matriz_notas[i][j] = 0;
            }
        }
    }
}

void eliminar_notas_menores_a_seis(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4]) {
    for(int i = 0; i <            for(int j = 0; j < cantidad_notas; j++) {
                matriz_notas[i][j] = nota_nueva;
            }
            break;
        }
    }
}

void modificar_todas_las_notas_y_calcular_promedios(char nombres[][50], int cantidad cantidad_alumnos; i++) {
        for(int j = 0; j < cantidad_notas; j++) {
            if(matriz_notas[i][j] < 6) {
                matriz_notas[i][j] = 0;
            }
        }
    }
}

void mostrar_alumnos_reprobados(char nombres[][50], int cantidad_alumnos, float promedios[]) {
    printf("Los alumnos reprobados son:\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(promedios[i] < 5) {
            printf("%s\n", nombres[i]);
        }
    }
}

void mostrar_alumnos_aprobados(char nombres[][50], int cantidad_alumnos, float promedios[]) {
    printf("Los alumnos aprobados son:\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(promedios[i] >= 5) {
            printf("%s\n", nombres[i]);
        }
    }
}

void recalcular_promedios(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], float promedios[]) {
    eliminar_notas_menores_a_cinco(nombres, cantidad_alumnos, cantidad_notas, matriz_notas);
    calcular_promedios(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);
}

void modificar_nota_por_alumno(char nombres[][50], int cantidad_alumnos, int cantidad_notas, float matriz_notas[][4], char alumno_buscar[50], float nota_nueva) {
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(strcmp(nombres[i], alumno_buscar) == 0) {
            for(int j = 0; j < cantidad_notas; j++) {
                matriz_notas[i][j] = nota_nueva;
            }
            break;
        }
    }
}

void mostrar_alumnos_desaprobados(char nombres[][50], int cantidad_alumnos, float promedios[]) {
    printf("Los alumnos desaprobados son:\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(promedios[i] < 5) {
            printf("%s\n", nombres[i]);
        }
    }
}

void mostrar_alumnos_aprobados(char nombres[][50], int cantidad_alumnos, float promedios[]) {
    printf("Los alumnos aprobados son:\n");
    for(int i = 0; i < cantidad_alumnos; i++) {
        if(promedios[i] >= 5) {
            printf("%s\n", nombres[i]);
        }
    }
}

int main() {
    int cantidad_alumnos = 3;
    int cantidad_notas = 4;

    char nombres[3][50] = {"Juan", "María", "Pedro"};

    float matriz_notas[3][4] = {{5, 4, 7, 9},
                                {3, 4, 5, 7},
                                {9, 10, 10, 10}};

    float promedios[3];

    mostrar_matriz_notas(nombres, cantidad_alumnos, cantidad_notas, matriz_notas);

    eliminar_notas_menores_a_cinco(nombres, cantidad_alumnos, cantidad_notas, matriz_notas);

    calcular_promedios(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);

    mostrar_promedios(nombres, cantidad_alumnos, promedios);

    mostrar_alumnos_reprobados(nombres, cantidad_alumnos, promedios);

    mostrar_alumnos_aprobados(nombres, cantidad_alumnos, promedios);

    recalcular_promedios(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, promedios);

    mostrar_promedios(nombres, cantidad_alumnos, promedios);

    modificar_nota_por_alumno(nombres, cantidad_alumnos, cantidad_notas, matriz_notas, "María", 6);

    mostrar_matriz_notas(nombres, cantidad_alumnos, cantidad_notas, matriz_notas);

    return 0;
}