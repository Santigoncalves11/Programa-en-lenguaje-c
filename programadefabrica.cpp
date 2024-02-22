// Los empleados de una fabrica trabajan en dos tumos: diumo y noctumo. Se desea ca!cular e! jorna! diario de acuerdo al siguiente baremo: A) Las horas diumas se pagan a 1000 Bsf.
// B)Las horas nocturas se pagan a 1600 Bsf.. C) En caso de ser domingo, la tarifa se incrementará en 400 Bsf. el tumo diumo

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

#define LDC 11

#define ctrlZ 26
#define ENTER 13
#define ESC 27
#define BORRAR 8
#define SPACE 32

//* -> contenido de la variable, & -> dirección de la variable

//prototipo 
void validar(char *p_letras[LDC]);
void gotoxy(int x, int y);


int main() {
  // Declaramos las variables y las constantes
  int horas, turno, dia; // Horas trabajadas, turno (1 para diurno, 2 para nocturno), dia (1 para domingo, 0 para otro dia)
  float jornal; // Jornal diario
  const float TARIFA_DIURNA = 1000.0; // Tarifa por hora diurna
  const float TARIFA_NOCTURNA = 1600.0; // Tarifa por hora nocturna
  const float INCREMENTO_DOMINGO_DIURNO = 400.0; // Incremento por hora diurna en domingo
  const float INCREMENTO_DOMINGO_NOCTURNO = 600.0; // Incremento por hora nocturna en domingo

  // Pedimos los datos al usuario
  printf("Introduce las horas trabajadas: ");
  scanf("%d", &horas);
  printf("Introduce el turno (1 para diurno, 2 para nocturno): ");
  scanf("%d", &turno);
  printf("Introduce el dia (1 para domingo, 0 para otro dia): ");
  scanf("%d", &dia);

  // Calculamos el jornal diario según el turno y el dia
  if (turno == 1) {
    // Turno diurno
    jornal = horas * TARIFA_DIURNA;
    if (dia == 1) {
      // Domingo
      jornal += horas * INCREMENTO_DOMINGO_DIURNO;
    }
  } else if (turno == 2) {
    // Turno nocturno
    jornal = horas * TARIFA_NOCTURNA;
    if (dia == 1) {
      // Domingo
      jornal += horas * INCREMENTO_DOMINGO_NOCTURNO;
    }
  } else {
    // Turno inválido
    printf("Turno no valido\n");
    return 1; // Terminamos el programa con un codigo de error
  }
  
  // Mostramos el resultado
  printf("El jornal diario es %.2f Bsf\n", jornal);

  return 0; // Terminamos el programa con éxito
}
