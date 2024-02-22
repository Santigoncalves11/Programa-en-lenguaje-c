#include <stdio.h> 
#include <conio.h>
#include <windows.h>
#include <string.h>

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

main () {
	
	int i;
	char contenido[LDC]; //cadena
	char *p_letras[LDC]; //*p_letra -> letra
	
	for(i=0; i<LDC; i++) {
		p_letras[i]=&contenido[i]; //Apuntando a todos las direcciones
	}
		
	validar(p_letras);
	printf("\nFinalizado!"); 
	printf("\n%s",contenido); getch();
	
	return 0;
}

void validar(char *p_letras[LDC]) {
	
	int i=0;
	int x=0,y=0; //coordenadas
		
	do {
		
		fflush(stdin);
		gotoxy(x+i,y); *p_letras[i]=(getch());  //getch almacena un único caracter!
		if(*p_letras[i]==ENTER && i>0) {
			
			i=LDC+1; //Romper el bucle
			
		} else if(*p_letras[i]==BORRAR && i>0) { 
		
			i--; gotoxy(x+i,y); printf(" ");
			
		} else if(i<LDC-1 && *p_letras[i]!=ESC && *p_letras[i]!=ENTER && *p_letras[i]!=BORRAR && *p_letras[i]!=ctrlZ && isdigit(*p_letras[i])==0) {
			printf("%.1s",p_letras[i]); i++;
			
		}
		
	} while (i<LDC+1); //Limite De Caracter

}

 void gotoxy(int x, int y) {

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD dwPos; 

	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);

}
