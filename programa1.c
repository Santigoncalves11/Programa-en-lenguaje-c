//Escribir un programa en C que imprime todas las lineas de su entrada estandar que contienen una palabra que se le pasa como argumentO//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char line[1000];
    char *word = argv[1];

    while (fgets(line, sizeof(line), stdin)) {
        if (strstr(line, word)) {
            printf("%s", line);
        }
    }

    return 0;
}
