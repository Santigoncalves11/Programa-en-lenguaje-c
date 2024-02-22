//En una elección realizada en un municipio, se presentaron tres candidatos: Pedro, María y Juan. Por cada votante se elaboró un registro así: 
//Cédula de Identidad y el valor del voto. 
//El voto puede desarrollarse de la siguiente manera: 
//Se pide: 
//Si votó por Pedro su valor es uno. 
//Si votó por María su valor es dos. Si votó por Juan su valor es tres. 
//A) Cuantos votos obtuvo cada candidatos. 
//B) Cuántos votos son nulos (voto nulo cualquier otro dígito).
//c) Quien gano las elecciones.

#include <stdio.h>
#include <windows.h>
#include <conio.h>

int main(){
	int cedula, voto, pedro = 0, maria = 0, juan = 0, nulos = 0;
    char respuesta;

    do {
        printf("Ingrese la cedula de identidad: ");
        scanf("%d", &cedula);
        printf("Ingrese el valor del voto (1 para Pedro, 2 para Maria, 3 para Juan): ");
        scanf("%d", &voto);

        switch (voto) {
            case 1:
                pedro++;
                break;
            case 2:
                maria++;
                break;
            case 3:
                juan++;
                break;
            default:
                nulos++;
                break;
        }

        printf("¿Desea ingresar otro voto? (S/N): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 'S' || respuesta == 's');

    printf("Votos para Pedro: %d\n", pedro);
    printf("Votos para Maria: %d\n", maria);
    printf("Votos para Juan: %d\n", juan);
    printf("Votos nulos: %d\n", nulos);

    if (pedro > maria && pedro > juan) {
        printf("Pedro gano las elecciones.\n");
    } else if (maria > pedro && maria > juan) {
        printf("Maria gano las elecciones.\n");
    } else if (juan > pedro && juan > maria) {
        printf("Juan gano las elecciones.\n");
    } else {
        printf("Hubo un empate.\n");
    }

    return 0;
}

