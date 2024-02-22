//Escribe un programa para determinar si un ateta es seleccionado para correr //una maratón. Para seleccionar'a un corredor, debe haber terminado una //maratón anterior en un 
//determinado tiempo. Los tiempos de calificación son //150 minutos para hombres menores de 40 años, 175 minutos para hombres //mayores de 40 años, y 180 minutos para mujeres.
//Los datos a introducir son: sexo (HM), edad y tiempo efectuado en su anterior maratón. el programa visualizará ei mensaje "Seleccionado" o "No seleccionado.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

int main() {
  // Declarar las variables
  char nombre[50]; // Nombre del atleta
  char sexo; // Sexo del atleta (H o M)
  int edad; // Edad del atleta
  int tiempo; // Tiempo efectuado en la anterior maratón (en minutos)
  int limite; // Tiempo límite para calificar (en minutos)

  // Pedir los datos al usuario
  printf("Introduce el nombre del atleta: ");
  scanf("%s", nombre);
  printf("Introduce el sexo del atleta (H o M): ");
  scanf(" %c", &sexo);
  printf("Introduce la edad del atleta: ");
  scanf("%d", &edad);
  printf("Introduce el tiempo efectuado en la anterior maraton (en minutos): ");
  scanf("%d", &tiempo);

  // Determinar el tiempo límite segun el sexo y la edad
  if (sexo == 'H') {
    // Si es hombre
    if (edad < 40) {
      // Si es menor de 40 años
      limite = 150;
    } else {
      // Si es mayor o igual de 40 años
      limite = 175;
    }
  } else {
    // Si es mujer
    limite = 180;
  }

  // Comparar el tiempo efectuado con el tiempo limite
  if (tiempo <= limite) {
    // Si el tiempo es menor o igual al limite
    printf("%s es seleccionado para correr la maraton.\n", nombre);
  } else {
    // Si el tiempo es mayor al límite
    printf("%s no es seleccionado para correr la maraton.\n", nombre);
  }

  return 0;
}
