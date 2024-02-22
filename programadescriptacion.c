#include <stdio.h>
#include <ctype.h>

// Constantes
#define MAX 100
#define ASCII_A 65
#define ASCII_a 97
#define LONGITUD_ALFABETO 26

// Función que calcula el módulo positivo
int modulo(int a, int b) {
    int r = a % b;
    return r < 0 ? r + b : r;
}

// Función que cifra una cadena usando el método César
void cifrar(char cadena[], int rotaciones) {
    int i = 0;
    while (cadena[i] != '\0') {
        // Si el carácter no es una letra, lo ignoramos
        if (!isalpha(cadena[i])) {
            i++;
            continue;
        }
        // Convertimos el carácter a su código ASCII
        int ascii = (int) cadena[i];
        // Determinamos si es mayúscula o minúscula
        int base = isupper(cadena[i]) ? ASCII_A : ASCII_a;
        // Aplicamos la fórmula del cifrado César
        int nuevo_codigo = base + modulo(ascii - base + rotaciones, LONGITUD_ALFABETO);
        // Convertimos el nuevo código a carácter y lo guardamos en la cadena
        cadena[i] = (char) nuevo_codigo;
        // Avanzamos al siguiente carácter
        i++;
    }
}

// Función que descifra una cadena usando el método César
void descifrar(char cadena[], int rotaciones) {
    // Para descifrar, basta con cifrar con el negativo de las rotaciones
    cifrar(cadena, -rotaciones);
}

// Función principal
int main() {
    // Declaramos una cadena de tamaño máximo
    char cadena[MAX];
    // Pedimos al usuario que introduzca el mensaje a cifrar
    printf("Introduce el mensaje a cifrar:\n");
    // Leemos la cadena usando fgets, que es más seguro que scanf
    fgets(cadena, MAX, stdin);
    // Pedimos al usuario que introduzca el número de rotaciones
    int rotaciones;
    printf("Introduce el número de rotaciones:\n");
    scanf("%d", &rotaciones);
    // Ciframos la cadena
    cifrar(cadena, rotaciones);
    // Mostramos el resultado
    printf("El mensaje cifrado es:\n%s\n", cadena);
    // Desciframos la cadena
    descifrar(cadena, rotaciones);
    // Mostramos el resultado
    printf("El mensaje descifrado es:\n%s\n", cadena);
    return 0;
}
