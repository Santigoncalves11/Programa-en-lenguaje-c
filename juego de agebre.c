// Realizar un juego de agebre en lenguaje con todas sus piezas y su movimientos.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>      
#include <string.h>       
#include <ctype.h>        
#include <conio.h>
#include <time.h>

 int gamer=1;
 void GuardarMove(int fila , int columna , int indice); 
 int ValidarNumero(char array[], int opcion);                    
 int* MoverFicha(int jugador,int ficha, int fila, int columna, int re[2] ,int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16]);                        
 int PostJaque(int jugador,int fila2, int columna2, int ficha2,int ficha, int fila, int columna, int playerX, int playerY, int re[2] ,int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16]);
 int Jaque(int jugador, int ficha, int fila, int columna, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16]);
 int RecorrerArreglo(int p,int fila, int columna,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe2[16]);
 int* ValidarMovilidad(int ficha2,int playerX, int playerY, int peligro, int jugador,int ficha,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe2[16]);
 int ValidarAtaque(int num1, int num2, int *re2, int *qu2, int *al2, int *to2, int *ca2, int *pe2);
 int DestinoValidar(int p,int num1, int num2, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int *re2, int *qu2, int *al2, int *to2, int *ca2, int *pe100);
 int* alfil(int peligro, int varx, int vary, int fila, int columna, int b, int *n1,int *n2, int *n3, int *n4,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);
 int* peon(int peligro, int varx, int vary, int fila, int columna,int b,int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *p7, int *p8,int *p9, int *p10, int *p11, int *p12, int *p13, int *p14, int *p15, int *p16,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);
 int* caballo(int peligro, int varx, int vary, int fila, int columna,int b,int *c1, int *c2, int *c3, int *c4, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);
 int* torre(int peligro, int varx, int vary, int fila, int columna,int b,int *t1, int *t2, int *t3, int *t4, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);
 int* reina(int peligro, int varx, int vary, int fila, int columna,int b,int *qu1, int *qu3,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);
 int* rey(int peligro, int varx, int vary, int fila, int columna,int b,int *re1, int *re3,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100);

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 main()
 {
 	system("COLOR 2");
 	// Tiempo actual
	//time_t ti = time(NULL);
//	struct tm tiempoLocal = *localtime(&ti);
	  // El lugar en donde se pondrá la fecha y hora formateadas
	  //char fechaHora[70];
	  // El formato. Mira más en https://en.cppreference.com/w/c/chrono/strftime
	  //char *formato = " %H:%M:%S";
	  // Intentar formatear
	  //int bytesEscritos =strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
 	int i,t,p=1,m=1,x=0,y=0, menu=1, valor=1, jugador=1, *validar, dato[7]={0,0,0,0,0,0,0}, ficha2=0, ficha1=0, ficha=0, jaque1, jaque2, peligro=0, peligro2;
 	int player1X, player1Y, player2X, player2Y, varx, vary;
 	validar=dato;
 	char a[9][3]={"T1", "C1", "A1","Q1", "R1", "P1"}, nombre[4];
 	char b[9][3]={"T2", "C2", "A2","Q2", "R2", "P2"};
 	//Jugador 1
 	int al[4]={1,3,1,6}, to[4]={1,1,1,8}, ca[4]={1,2,1,7}, re[2]={1,5}, qu[2]={1,4}, pe[16]={2,1,2,2,2,3,2,4,2,5,2,6,2,7,2,8};
	int *alfiles, *torres, *caballos, *reinas, *reyes, *peones;
	alfiles=al;
	torres=to;
	caballos=ca;
	reinas=qu;
	reyes=re;
	peones=pe;
	
	//Jugador 2
	int al2[4]={8,3,8,6}, to2[4]={8,1,8,8}, ca2[4]={8,2,8,7}, re2[2]={8,4}, qu2[2]={8,5}, pe2[16]={7,1,7,2,7,3,7,4,7,5,7,6,7,7,7,8};
	int *alfiles2, *torres2, *caballos2, *reinas2, *reyes2, *peones2;
	alfiles2=al2;
	torres2=to2;
	caballos2=ca2;
	reinas2=qu2;
	reyes2=re2;
	peones2=pe2;
	volver:
	volver2:
  while(menu==1)
  {
  	jaque2=0;
  	jaque1=0;
  	varx=0;
  	vary=0;
 	i=0, t=0, p=1, m=1;
 	for(i=0; i<=8; i++)
 	{ 
	  for(t=0; t<=8; t++)
 	    { 
 	        
 	    	gotoxy(15+t*6,5+i*3);
 	           //Reyes
	 	        if(i==re[0] && t==re[1])
	 	    	 {
	 	    	 	printf("%s ", a[4]);
	 	    	 }
	 	        //Reinas
	 	        if(i==qu[0] && t==qu[1])
	 	    	 {
	 	    	 	printf("%s", a[3]);
	 	    	 }
			  //Torres
			    if((i==to[0] && t==to[1]) || (i==to[2] && t==to[3]))
 	    	 	 {
 	    	 	    printf("%s", a[0]);
 	    	     }
			   //Caballos
			  if((i==ca[0] && t==ca[1]) || (i==ca[2] && t==ca[3]))
	 	    	 {
	 	    	 	printf("%s", a[1]);
	 	    	 }
	 	    	 
			 //Alfiles
	 	      if((i==al[0] && t==al[1]) || (i==al[2] && t==al[3]))
	 	    	{
	 	    	   printf("%s", a[2]);
	 	        }
 	    	 if((i==pe[0] && t==pe[1]) || (i==pe[2] && t==pe[3]) || (i==pe[4] && t==pe[5]) || (i==pe[6] && t==pe[7]) || (i==pe[8] && t==pe[9]) || (i==pe[10] && t==pe[11]) || (i==pe[12] && t==pe[13]) || (i==pe[14] && t==pe[15]))
 	    	 {
 	    	 	printf("%s", a[5]);
 	    	 }
 	    	                    //Jugador 2
 	    	 //Reyes
	 	        if(i==re2[0] && t==re2[1])
	 	    	 {
	 	    	 	printf("%s", b[4]);
	 	    	 }
	 	        //Reinas
	 	        if(i==qu2[0] && t==qu2[1])
	 	    	 {
	 	    	 	printf("%s", b[3]);
	 	    	 }
			  //Torres
			    if((i==to2[0] && t==to2[1]) || (i==to2[2] && t==to2[3]))
 	    	 	 {
 	    	 	    printf("%s", b[0]);
 	    	     }
			   //Caballos
			  if((i==ca2[0] && t==ca2[1]) || (i==ca2[2] && t==ca2[3]))
	 	    	 {
	 	    	 	printf("%s", b[1]);
	 	    	 }
	 	    	 
			 //Alfiles
	 	      if((i==al2[0] && t==al2[1]) || (i==al2[2] && t==al2[3]))
	 	    	{
	 	    	   printf("%s", b[2]);
	 	        }
 	    	 //Peones
 	    	 if((i==pe2[0] && t==pe2[1]) || (i==pe2[2] && t==pe2[3]) || (i==pe2[4] && t==pe2[5]) || (i==pe2[6] && t==pe2[7]) || (i==pe2[8] && t==pe2[9]) || (i==pe2[10] && t==pe2[11]) || (i==pe2[12] && t==pe2[13]) || (i==pe2[14] && t==pe2[15]))
 	    	 {
 	    	 	printf("%s", b[5]);
 	    	 }
		     if(i==0 && t>0)
	 	    	{  
	
	 	    		printf("%d",p);
	 	    		p++;
				}
			 if(t==0 && i>0)
			 {
			    printf("%d", m );
 	    		m++;
			 }
		 }
		 
    }
       
	 	if(jugador==1)
	 	{
	 		inicio:
	 		  
			  
			/*  if (bytesEscritos != 0) {
			    // Si no hay error, los bytesEscritos no son 0
			    printf("Fecha y hora: %s", fechaHora);
			  } else {
			    printf("Error formateando fecha");
			  }
			  */
			  
	 		printf("\n\n      Ingrese el nombre de la pieza Jugador_1= "); //  gotoxy(15+9*12,6); 
			scanf("%s", nombre);
            fflush(stdin);
		 	if(strcmp(nombre,"A1")==0)
		 	{    ficha=3;
			    validar=ValidarMovilidad(ficha2,player2X, player2Y,peligro, jugador, ficha ,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 	       alfiles=alfil(peligro, varx, vary, x,y,jugador,&al[0], &al[1], &al[2], &al[3], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	    }else
		 	    {
		 	    	printf("\n No tiene movimientos validos");
		 	    	getch();
		 	    	system("cls");
		 	    	goto volver;
		 	    }
		 	    
		 	}
		 	if(strcmp(nombre,"P1")==0)
		 	{   ficha=6;
		 		validar=ValidarMovilidad(ficha2,player2X, player2Y,peligro,  jugador, ficha,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
			    peones=peon(peligro, varx, vary, x,y,jugador,&pe[0],&pe[1],&pe[2],&pe[3],&pe[4],&pe[5],&pe[6],&pe[7],&pe[8],&pe[9],&pe[10],&pe[11],&pe[12],&pe[13],&pe[14],&pe[15],re,qu,al,to, ca,pe, re2, qu2, al2, to2,ca2,pe2);
		        }else
		        {  
				printf("\n No tiene movimientos validos");
				getch();
		 	    	system("cls");
		 	    goto volver;
		 	    }
		 	}
		 	if(strcmp(nombre,"C1")==0)
		 	{   ficha=5;
		 		validar=ValidarMovilidad(ficha2, player2X, player2Y,peligro, jugador, ficha ,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		caballos=caballo(peligro, varx, vary, x,y,jugador,&ca[0], &ca[1], &ca[2], &ca[3], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	   }else
		 	   { 
				printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver;
		 	    }
		 	}
		 	if(strcmp(nombre,"T1")==0)
		 	{   ficha=4;
		 		validar=ValidarMovilidad(ficha2,player2X, player2Y,peligro,  jugador, ficha ,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    torres=torre(peligro, varx, vary,x,y,jugador,&to[0], &to[1], &to[2], &to[3], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	    }else
		 	    { 
				 printf("\n No tiene movimientos validos");
				 getch();
		 	    	system("cls");
		 	    goto volver;
		 	    }
		 	}
		 	if(strcmp(nombre,"Q1")==0)
		 	{   ficha=2;
		 		validar=ValidarMovilidad(ficha2,player2X, player2Y,peligro,  jugador, ficha ,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    reinas=reina(peligro, varx, vary, x,y,jugador,&qu[0], &qu[1], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    getch();
		 	    	system("cls");
		 	    goto volver;
		 	    }
		 	}
		 	if(strcmp(nombre,"R1")==0)
		 	{   ficha=1;
		 		validar=ValidarMovilidad(ficha2,player2X, player2Y,peligro,  jugador, ficha ,re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2 );
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    reyes=rey(peligro, varx, vary, x,y,jugador,&re[0], &re[1], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    getch();
		 	    	system("cls");
		 	    goto volver;
		 	    }
		 	}
		 	if(strcmp(nombre,"A1")!=0 && strcmp(nombre,"P1")!=0 && strcmp(nombre,"C1")!=0 && strcmp(nombre,"T1")!=0 && strcmp(nombre,"Q1")!=0 && strcmp(nombre,"R1")!=0)
		 	{
		 		printf("\n Ingrese las iniciales de la ficha correspondiente");
		 		goto inicio;
		 	}
		 	//Validar Jaque
		 	if(ficha==1)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha, re[*(validar+3)] , re[*(validar+4)], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==1)
		 	   peligro=1;
		 	   player1X=re[*(validar+3)];
		 	   player1Y=re[*(validar+4)];
		 	   ficha2=ficha;
		    }
		 	if(ficha==2)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha , qu[*(validar+3)] , qu[*(validar+4)], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==3)
		 	   peligro=1;
		 	   player1X=qu[*(validar+3)];
		 	   player1Y=qu[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==3)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha, al[*(validar+3)] , al[*(validar+4)],re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==1)
		 	   peligro=1;
		 	   player1X=al[*(validar+3)];
		 	   player1Y=al[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==4)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha, to[*(validar+3)] , to[*(validar+4)], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==1)
		 	   peligro=1;
		 	   player1X=to[*(validar+3)];
		 	   player1Y=to[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==5)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha , ca[*(validar+3)] , ca[*(validar+4)],re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==1)
		 	   peligro=1;
		 	   player1X=ca[*(validar+3)];
		 	   player1Y=ca[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==6)
		 	{		 	
		 	 jaque1=Jaque(jugador, ficha , pe[*(validar+3)] , pe[*(validar+4)], re, qu, al, to,ca,pe, re2, qu2, al2, to2,ca2,pe2);
		 	 if(jaque1==1)
		 	   peligro=1;
		 	   player1X=pe[*(validar+3)];
		 	   player1Y=pe[*(validar+4)];
		 	   ficha2=ficha;
		    }
		 	jugador=0;
	    }else
	    {
	    	
	    	inicio2:
	    	printf("\n\n\bIngrese el nombre de la pieza jugador_2= ");
            scanf("%s", nombre);
            fflush(stdin);
	    	if(strcmp(nombre,"A2")==0)
		 	{       ficha=3;
		 		    validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    alfiles2=alfil(peligro, varx, vary, x,y,jugador, &al2[0], &al2[1], &al2[2], &al2[3], re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	}
		 	if(strcmp(nombre,"P2")==0)
		 	{       ficha=6;
		 			validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
			        peones2=peon(peligro, varx, vary, x,y,jugador,&pe2[0],&pe2[1],&pe2[2],&pe2[3],&pe2[4],&pe2[5],&pe2[6],&pe2[7],&pe2[8],&pe2[9],&pe2[10],&pe2[11],&pe2[12],&pe2[13],&pe2[14],&pe2[15],re2,qu2,al2,to2, ca2,pe2, re, qu, al, to,ca,pe);
		        }else
		        { 
		        printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	}
		 	if(strcmp(nombre,"C2")==0)
		 	{       ficha=5;
		 			validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    caballos2=caballo(peligro, varx, vary, x,y,jugador,&ca2[0], &ca2[1], &ca2[2], &ca2[3], re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	    }else 
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	}
		 	if(strcmp(nombre,"T2")==0)
		 	{       ficha=4;
		 			validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		   torres2=torre(peligro, varx, vary, x,y,jugador,&to2[0], &to2[1], &to2[2], &to2[3], re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	}
		 	if(strcmp(nombre,"Q2")==0)
		 	{       ficha=2;
		 			validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 	    	reinas2=reina(peligro, varx, vary, x,y,jugador,&qu2[0], &qu2[1], re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	}
		 	if(strcmp(nombre,"R2")==0)
		 	{       ficha=1;
		 			validar=ValidarMovilidad(ficha2,player1X, player1Y,peligro,  jugador, ficha , re2, qu2, al2, to2,ca2,pe2,re, qu, al, to,ca,pe);
		 	    if(*(validar+2)==1)
		 	    {
		 	    	x=*(validar);
		 	    	y=*(validar+1);
		 	    	if(peligro==1)
		 	    	{
		 	    		varx=*(validar+3);
		 	    		vary=*(validar+4);
		 	    	}
		 		    reyes2=rey(peligro, varx, vary, x,y,jugador,&re2[0], &re2[1], re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	    }else
		 	    { 
		 	    printf("\n No tiene movimientos validos");
		 	    getch();
		 	    	system("cls");
		 	    goto volver2;
		 	    }
		 	    
		 	}//Validar nombre de la ficha
	    	if(strcmp(nombre,"A2")!=0 && strcmp(nombre,"P2")!=0 && strcmp(nombre,"C2")!=0 && strcmp(nombre,"T2")!=0 && strcmp(nombre,"Q2")!=0 && strcmp(nombre,"R2")!=0)
		 	{
		 		printf("\n Ingrese las iniciales de la ficha correspondiente");
		 		goto inicio2;
		 	}
		 	//Validar Jaque
		 	if(ficha==1)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha, re2[*(validar+3)] , re2[*(validar+4)],  re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==1)
		 	   peligro=1;
		 	   player2X=re2[*(validar+3)];
		 	   player2Y=re2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		 	if(ficha==2)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha , qu2[*(validar+3)] , qu2[*(validar+4)],  re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==3)
		 	   peligro=1;
		 	   player2X=qu2[*(validar+3)];
		 	   player2Y=qu2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==3)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha, al2[*(validar+3)] , al2[*(validar+4)],   re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==1)
		 	   peligro=1;
		 	   player2X=al2[*(validar+3)];
		 	   player2Y=al2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==4)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha, to2[*(validar+3)] , to2[*(validar+4)],   re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==1)
		 	   peligro=1;
		 	   player2X=to2[*(validar+3)];
		 	   player2Y=to2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==5)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha , ca2[*(validar+3)] , ca2[*(validar+4)],   re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==1)
		 	   peligro=1;
		 	   player2X=ca2[*(validar+3)];
		 	   player2Y=ca2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		    if(ficha==6)
		 	{		 	
		 	 jaque2=Jaque(jugador, ficha , pe2[*(validar+3)] , pe2[*(validar+4)],   re2, qu2, al2, to2,ca2,pe2, re, qu, al, to,ca,pe);
		 	 if(jaque2==1)
		 	   peligro=1;
		 	   player2X=pe2[*(validar+3)];
		 	   player2Y=pe2[*(validar+4)];
		 	   ficha2=ficha;
		    }
		 	
	    	jugador=1;
	    }
	    
	 	getch();
	 	system("cls");
  }
 	
    system("PAUSE");
 	system("cls");
 	getch();
 }
  int* rey(int peligro, int varx, int vary,int fila, int columna, int b,int *re1, int *re3,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	int  fila2, columna2, valor=0,i=0,t=0, aux1,aux2, aux3,aux4,p, k; 
	char fil[256], col[256];
  	static int rey[2];
  
       iniciore:
       rangore:
	   moverey: 
	   jaque:  
	   reg:	
       printf(" \n Ingrese destino");
       //FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	   
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	   
        fflush(stdin);
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango destino
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rangore;
         }
         //Validar que no sea coordenada de otra ficha
         p=0;
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     if(valor==1)
  	     { 
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto iniciore;
  	     }
  	     //Validar movimiento del rey
  	     if(((fila+1)!=fila2 || (columna+1)!=columna2) && ((fila+1)!=fila2 || (columna-1)!=columna2) && ((fila+1)!=fila2 || columna!=columna2) && 
		   (fila!=fila2 || (columna+1)!=columna2) && (fila!=fila2 || (columna-1)!=columna2) && ((fila-1)!=fila2 || (columna-1)!=columna2) && ((fila-1)!=fila2 || (columna+1)!=columna2) && ((fila-1)!=fila2 || columna!=columna2))
  	     {
  	     	printf("\n Movimiento invalido");
  	     	goto moverey;
  	     }
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     for(t=1; t<=8; t++)
  	     {
  	     	
  	     }
  	     if(b==1 || b==0)
         {
         	ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100);
         }
         GuardarMove(aux3 , aux4 , 4);
  	     if(aux1==*re1 && aux2==*re3)
	  	 {
	  	    *re1=aux3;
	  	    *re3=aux4;
	  	 }
	  	 rey[0]=*re1;
	     rey[1]=*re3;
	  	 return rey;
  }
  int* reina(int peligro, int varx, int vary,int fila, int columna, int b,int *qu1, int *qu3,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	int fila2, columna2, valor=0,i=0,t=0, aux1,aux2, aux3,aux4,p,k;
  	char fil[256], col[256];
  	static int reina[2];
  	
       inicioqu:
       rangoqu:
       	volverqu:
       	volverqu2:
		volverqu3: 
		jaque:  	
		reg:
       printf(" \n Ingrese destino");
  	 	//FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	    
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	    
        fflush(stdin);
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango destino
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rangoqu;
         }
         //Validar que no sea coordenada de otra ficha
         p=0;
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe, re2, qu2,al2, to2, ca2, pe100);
  	     if(valor==1)
  	     {
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto inicioqu;
  	     }
  	     //Validar moviiento de la reina
  	     if(fila-fila2!=columna-columna2 && fila2-fila!=columna-columna2 && fila!=fila2 && columna!=columna2)
  	     {
  	     	printf("\nMovimiento invalido");
  	     	goto volverqu;
  	     }
  	     //Validar ficha en la horizontal izquierda
  	     if(fila==fila2 && columna>columna2)
  	     {   
  	     	for(i=columna-1; i>columna2; i--){
  	     		p=1;
  	     		valor=DestinoValidar(p,fila2,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la horizontal izquierda");
  	     			goto volverqu2;
  	     		}  
  	     	}
		  }
  	     //Validar ficha en la horizontal derecha
  	     if(fila==fila2 && columna<columna2)
  	     {   
  	     	for(i=columna+1; i<columna2; i++){
  	     		p=1;
  	     		valor=DestinoValidar(p,fila2,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la horizontal derecha");
  	     			goto volverqu2;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     //Validar ficha en la vertical inferior
  	     if(columna==columna2 && fila<fila2)
  	     {   
  	     	for(i=fila+1; i<fila2; i++){
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la vertical inferior");
  	     			goto volverqu2;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     //Validar ficha en la vertical superior
  	     if(columna==columna2 && fila>fila2)
  	     {   
  	     	for(i=fila-1; i>fila2; i--){
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la vertical superior");
  	     			goto volverqu2;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     //Validar diagonal superior izquierda
  	     if(fila>fila2 && columna>columna2)
  	     {
  	     	for(i=fila-1; i>fila2; i--){
  	     		columna--;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volverqu3;
  	     		}
  	     		  
  	     	} 
  	     }
		   //Validar diagonal superior derecha
		   if(fila>fila2 && columna<columna2)
  	     {
  	     	for(i=fila-1; i>fila2; i--){
  	     		columna++;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volverqu3;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }//Validar diagonal inferior izquierda
  	     if(fila<fila2 && columna>columna2)
  	     {
  	     	for(i=fila+1; i<fila2; i++){
  	     		columna--;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volverqu3;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }
  	      //Validar diagonal inferior derecha
  	      if(fila<fila2 && columna<columna2)
  	     {
  	     	for(i=fila+1; i<fila2; i++){
  	     		columna++;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volverqu3;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }
         if(b==1|| b==0)
         {
         	ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100 );
         }
         GuardarMove(aux3 , aux4 , 3);
  	     if(aux1==*qu1 && aux2==*qu3)
	  	 {
	  	    *qu1=aux3;
	  	    *qu3=aux4;
	  	 }
	  	 reina[0]=*qu1;
	     reina[1]=*qu3;
	  	 return reina;
  }
  int* torre(int peligro, int varx, int vary,int fila, int columna, int b,int *t1, int *t2, int *t3, int *t4, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	int fila2, columna2, valor=0,i=0,t=0, aux1,aux2, aux3,aux4,p,k;
  	char fil[256],col[256];
  	static int torre[4];
  	
       inicioto:
       rangoto:
       volverto:
       moveto:
       	jaque:
       	reg:
       printf(" \n Ingrese destino");
  	 	//FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	   
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	    
        fflush(stdin);
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango destino
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rangoto;
         }
         //Validar que no sea coordenada de otra ficha
         p=0;
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     if(valor==1)
  	     {
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto inicioto;
  	     }
  	     //Validar movimiento horizontal y vertical 
  	     if(fila!=fila2 && columna!=columna2)
  	     {
  	     	printf("\n Movimiento invalido");
  	     	goto moveto;
  	     }
  	     //Validar ficha en la horizontal izquierda
  	     if(fila==fila2 && columna>columna2)
  	     {   
  	     	for(i=columna-1; i>columna2; i--){
  	     		p=1;
  	     		valor=DestinoValidar(p,fila2,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la horizontal izquierda");
  	     			goto volverto;
  	     		}
  	     		  
  	     	}
		  }
  	     //Validar ficha en la horizontal derecha
  	     if(fila==fila2 && columna<columna2)
  	     {   
  	     	for(i=columna+1; i<columna2; i++){
  	     		p=1;
  	     		valor=DestinoValidar(p,fila2,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la horizontal derecha");
  	     			goto volverto;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     //Validar ficha en la vertical inferior
  	     if(columna==columna2 && fila<fila2)
  	     {   
  	     	for(i=fila+1; i<fila2; i++){
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la vertical inferior");
  	     			goto volverto;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     //Validar ficha en la vertical superior
  	     if(columna==columna2 && fila>fila2)
  	     {   
  	     	for(i=fila-1; i>fila2; i--){
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la vertical superior");
  	     			goto volverto;
  	     		}
  	     		  
  	     	} 
		   	
  	     }
  	     
  	     if(b==1|| b==0)
         {
         	ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100 );
         }
         GuardarMove(aux3 , aux4 , 0);
	  	 if(aux1==*t1 && aux2==*t2)
	  	 {
	  	    *t1=aux3;
	  	    *t2=aux4;
	  	    
	  	 }//Segunda ficha
	  	 if(aux1==*t3 && aux2==*t4)
	  	 {
	  	 	*t3=aux3;
	  	    *t4=aux4;	
	  	 }
	  	 torre[0]=*t1;
	     torre[1]=*t2;
		 torre[2]=*t3;
		 torre[3]=*t4;
	  	 return torre;
  	     
  }
  int* caballo(int peligro, int varx, int vary,int fila, int columna, int b,int *c1, int *c2, int *c3, int *c4, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	int fila2, columna2, valor=0,i=0,t=0, aux1,aux2, aux3,aux4, p,k;
  	char fil[256], col[256];
  	static int caballo[4];
  
       inicioca:
       move:
       rangoca:
       	jaque:
       reg:
       printf(" \n Ingrese destino");
  	 	//FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	    
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	   
        fflush(stdin);
        //Si estoy en jaque
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango destino
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rangoca;
         }
        //Validar que no sea coordenada de otra fich
         p=0;
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe, re2,qu2,al2,to2,ca2,pe100);
  	     if(valor==1)
  	     {  
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto inicioca;
  	     }
       
       // Valdar movimiento del caballo en L
       if(((fila+2)!=fila2 || (columna-1)!=columna2) && ((fila+2)!=fila2 || (columna+1)!=columna2) && ((fila-2)!=fila2 || (columna-1)!=columna2) && ((fila-2)!=fila2 || (columna+1)!=columna2)
	      && ((columna+2)!=columna2 || (fila+1)!=fila2) && ((columna+2)!=columna2 || (fila-1)!=fila2) && ((columna-2)!=columna2 || (fila-1)!=fila2) && ((columna-2)!=columna2 || (fila+1)!=fila2))
       {
       	 printf("\n Movimiento invalido del caballo");
       	 goto move;
       }
       if(b==1 || b==0)
         {
         	ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100 );
         }
         GuardarMove(aux3 , aux4 , 1);
  	  if(aux1==*c1 && aux2==*c2)
  	 {
  	    *c1=aux3;
  	    *c2=aux4;
  	    
  	 }//Segunda ficha
  	 if(aux1==*c3 && aux2==*c4)
  	 {
  	 	*c3=aux3;
  	    *c4=aux4;	
  	 }
  	 caballo[0]=*c1;
     caballo[1]=*c2;
	 caballo[2]=*c3;
	 caballo[3]=*c4;
  	 return caballo;
  }
  
  
  int* peon(int peligro, int varx, int vary,int fila, int columna, int b,int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *p7, int *p8,int *p9, int *p10, int *p11, int *p12, int *p13, int *p14, int *p15, int *p16,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	int fila2, columna2, valor=0,i=0,t=0, move=0, aux1,aux2, aux3,aux4,ComerFicha=0, p,k;
  	char fil[256], col[256];
  	static int peon[16];
         jugar:
         iniciope:
         mover1:
		 volverpe2:	
		 validado:
		 jaque:
		 rangope:
		 reg:
     	printf(" \n Ingrese destino");
  	 	//FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	    
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	    
        fflush(stdin);
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango destino
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rangope;
         }
         
        //Validar que no sea coordenada de otra ficha
          if(((fila+1)!=fila2 || (columna+1)!=columna2) && ((fila+1)!=fila2 || (columna-1)!=columna2) && ((fila-1)!=fila2 || (columna+1)!=columna2) && ((fila-1)!=fila2 || (columna-1)!=columna2))
            {
            p=1;
  	        valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe, re2,qu2,al2,to2,ca2,pe100);
  	        }
  	     if(valor==1)
  	     {
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto iniciope;
  	     }
  	     //Validar movimiento del peon jugador 1
  	     if(b==1)
  	     { // Validar movimientos posibles del peon
        	if(((fila+2)!=fila2 || columna!=columna2)  && ((fila+1)!=fila2 || columna!=columna2) && ((fila+1)!=fila2 || (columna+1)!=columna2) && ((fila+1)!=fila2 || (columna-1)!=columna2))
        	{
        		printf("\nEl peon de mueve hacia adelante");
        		goto mover1;
        	}
			//Validar ficha en la fila siguiente
        	if((fila+2)==fila2)
			{   p=1;
				valor=DestinoValidar(p,fila+1, columna, re, qu, al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
				if(valor==1)
				{
					printf("\n Hay una ficha en la fila siguiente");
					
					goto validado;
				}
			}	
         }//Validar movimiento del peon jugador 2
         if(b==0)
         {
         	if(((fila-2)!=fila2 || columna!=columna2)  && ((fila-1)!=fila2 || columna!=columna2) && ((fila-1)!=fila2 || (columna+1)!=columna2) && ((fila-1)!=fila2 || (columna-1)!=columna2))
        	{
        		printf("\nEl peon de mueve hacia adelante");
        		goto mover1;
        	}
        	//Validar ficha en la fila siguiente
        	if((fila-2)==fila2)
			{   p=1;
				valor=DestinoValidar(p,fila-1, columna, re, qu, al, to, ca, pe,re2,qu2,al2,to2,ca2,pe100);
				if(valor==1)
				{
					printf("\n Hay una ficha en la fila siguiente");
					
					goto validado;
				}
			}	
         }
         if((b==1 || b==0) || ((fila+1)==fila2 && (columna+1)==columna2) || ((fila+1)==fila2 && (columna-1)==columna2) || ((fila-1)==fila2 && (columna+1)==columna2) || ((fila-1)==fila2 && (columna-1)==columna2)) 
         {
         	ComerFicha=ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100);
         }
         if(ComerFicha!=1 && ((columna-1)==columna2 || (columna+1)==columna2))
         {
         	printf("\nMovimiento no valido");
         	goto jugar;
         }
         
        //Guardar en txt
		GuardarMove(aux3, aux4, 5); 
         
      //Reasignar coordenadas 
     if(aux1==*p1 && aux2==*p2)    
     {    if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p1=aux3;
        *p2=aux4;
     }
     if(aux1==*p3 && aux2==*p4)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p3=aux3;
        *p4=aux4;
     }
     if(aux1==*p5 && aux2==*p6)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p5=aux3;
        *p6=aux4;
     }
     if(aux1==*p7 && aux2==*p8)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p7=aux3;
        *p8=aux4;
     }
     if(aux1==*p9 && aux2==*p10)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p9=aux3;
        *p10=aux4;
     }
     if(aux1==*p11 && aux2==*p12)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p11=aux3;
        *p12=aux4;
     }
     if(aux1==*p13 && aux2==*p14)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p13=aux3;
        *p14=aux4;
     }
	 if(aux1==*p15 && aux2==*p16)    
     {   if(fila>2 && (fila+2)==fila2){
     	    printf("\nMovimiento no valido");
     	    goto volverpe2;
        } 
        *p15=aux3;
        *p16=aux4;
     }
     
     peon[0]=*p1;   peon[1]=*p2;   peon[2]=*p3;   peon[3]=*p4;  peon[4]=*p5;   peon[5]=*p6;
	 peon[6]=*p7;   peon[7]=*p8;   peon[8]=*p9;   peon[9]=*p10; peon[10]=*p11; peon[11]=*p12;   
	 peon[12]=*p13;   peon[13]=*p14;   peon[14]=*p15;  peon[15]=*p16; 
	 return peon;  
  }
 int* alfil(int peligro, int varx, int vary,int fila, int columna, int b, int *n1, int *n2, int *n3, int *n4,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16],int *re2,int *qu2,int *al2,int *to2,int *ca2,int *pe100)
  {
  	
  	int fila2, columna2, valor=0,i=0,t=0, aux1,aux2, aux3,aux4,p,k;
  	char fil[256], col[256];
  	static int alfil[4];
  
       rango:
       inicioal:
       volveral:
       	volver2al:
       	jaque:
        reg:
       printf(" \n Ingrese destino");
  	   //FILA
  	 	printf("\n Fila= ");  scanf("%s", fil);
  	 	k=ValidarNumero(fil, 1);
	    if(k==0){
	    	goto reg;
	    }
	    fila2=atoi(fil);
	    
  	 	//COLUMNA
  	 	printf("\n Columna= ");  scanf("%s", col);
  	 	k=ValidarNumero(col, 1);
	    if(k==0){
	    	goto reg;
	    }
	    columna2=atoi(col);
	   
        fflush(stdin);
        if(peligro==1)
        {
        	if((fila2!=varx && columna2!=vary))
        	{
        		printf("Protege al rey");
        		goto jaque;
        	}
        }
        aux1=fila;
        aux2=columna;
        aux3=fila2;
        aux4=columna2;
        // Validar rango
         if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
         {
         	printf("\nCoordenada invalida");
         	goto rango;
         }
         
         //Validar que no sea coordenada de otra ficha
         p=0;
  	     valor=DestinoValidar(p,fila2, columna2, re, qu,al, to, ca, pe, re2,qu2,al2,to2,ca2,pe100);
  	     if(valor==1)
  	     {
  	     	printf("\nEn la coordenada hay una ficha");
  	     	goto inicioal;
  	     }
         //Validar movimiento del alfil en diagonal
  	     if(fila-fila2!=columna-columna2 && fila2-fila!=columna-columna2)
  	     {
  	     	printf("\nEl alfil se mueve diagonalmente");
  	     	goto volveral;
  	     }
  	     //Validar diagonal superior izquierda
  	     if(fila>fila2 && columna>columna2)
  	     {
  	     	for(i=fila-1; i>fila2; i--){
  	     		columna--;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		//Aqui llamo a otra funcion para compara con las cordenadas validas
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volver2al;
  	     		}
  	     		  
  	     	} 
  	     }
		   //Validar diagonal superior derecha
		   if(fila>fila2 && columna<columna2)
  	     {
  	     	for(i=fila-1; i>fila2; i--){
  	     		columna++;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volver2al;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }//Validar diagonal inferior izquierda
  	     if(fila<fila2 && columna>columna2)
  	     {
  	     	for(i=fila+1; i<fila2; i++){
  	     		columna--;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volver2al;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }
  	      //Validar diagonal inferior derecha
  	      if(fila<fila2 && columna<columna2)
  	     {
  	     	for(i=fila+1; i<fila2; i++){
  	     		columna++;
  	     		p=1;
  	     		valor=DestinoValidar(p,i,columna,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			printf("Hay una ficha en la diagonal");
  	     			goto volver2al;
  	     		}
  	     		  
  	     	}
  	     	  
  	     }
  	     if(b==1 || b==0)
         {
         	ValidarAtaque(fila2, columna2, re2,qu2,al2,to2,ca2,pe100 );
         }
         GuardarMove(aux3 , aux4 , 2);
  	   //Pimera ficha  
  	 if(aux1==*n1 && aux2==*n2)
  	 {
  	    *n1=aux3;
  	    *n2=aux4;
  	    
  	 }//Segunda ficha
  	 if(aux1==*n3 && aux2==*n4)
  	 {
  	 	*n3=aux3;
  	    *n4=aux4;	
  	 }
  	 alfil[0]=*n1;
     alfil[1]=*n2;
	 alfil[2]=*n3;
	 alfil[3]=*n4;
  	 return alfil;
  }
  int DestinoValidar(int p, int num1, int num2, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int *re2, int *qu2, int *al2, int *to2, int *ca2, int *pe100)
  {
    int i=0,t=0, n=0,aux[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},validar, aux1=0,aux2=0;
  
  	for(i=0; i<12; i++)
  	   {  
  	   if(p==1 || p==0)
  	     {
  	   	  if(i==0){
  	   	  	for(n=1; n<=2; n++)
  	   	  	  aux[n]=re[n-1];
  	   	     }
  	   	  if(i==1){                
  	   	    for(n=1; n<=2; n++)
  	   	  	  aux[n]=qu[n-1];
  	   	    }
  	   	     if(i==2){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=al[n-1];
  	   	     }  
  	   	     if(i==3){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=to[n-1];
  	   	     }  
  	   	     if(i==4){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=ca[n-1];
  	   	     }  
  	   	     if(i==5){
  	   	     	for(n=1; n<=16; n++)
  	   	  	  aux[n]=pe[n-1];
				  }
		  }
		   if(p==1)
		   {
		   
			 if(i==6){
  	   	  	for(n=1; n<=2; n++)
  	   	  	  aux[n]=*(re2+n-1);
  	   	     }
  	   	     if(i==7){                
  	   	    for(n=1; n<=2; n++)
  	   	  	  aux[n]=*(qu2+n-1);
  	   	     }
  	   	     if(i==8){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(al2+n-1);
  	   	     }  
  	   	     if(i==9){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(to2+n-1);
  	   	     }  
  	   	     if(i==10){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(ca2+n-1);
  	   	     }  
  	   	     if(i==11){
  	   	     	for(n=1; n<=16; n++)
  	   	  	   aux[n]=*(pe100+n-1);
				  }	
		   }
				    //Revisar ejecutar primero
  	   	    
	  	   	    for(t=1; t<sizeof(aux)/sizeof(aux[1]); t++)
	  	   	  {
	  	   	  	   if(aux[t+1]==num2 && (t+1)%2==0)
	  	   	  	   {
	  	   	  	   	 aux1=1;
	  	   	  	   }
	  	   	  	   if(aux[t]==num1 && t%2!=0)
	  	   	  	   {
	  	   	  	   	 aux2=1;
	  	   	  	   }
	  	   	  	   if(aux1==1 && aux2==1)
	  	   	  	   {
	  	   	  	   	return 1;
	  	   	  	   }
	  	   	  	   aux1=0;
	  	   	  	   aux2=0;
	  	   	  	   
	  	   	  }
  	   	  
  	   }
  	   return 0;
 }
 
 int ValidarAtaque(int num1, int num2, int *re2, int *qu2, int *al2, int *to2, int *ca2, int *pe2)
 {
 	int i=0,t=0, n=0,aux[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},validar, aux1=0,aux2=0;
 	int ficha;
   
  	for(i=0; i<6; i++)
  	   {
  	   	  if(i==0){
  	   	  	for(n=1; n<=2; n++)
  	   	  	  aux[n]=*(re2+n-1);
  	   	  	  ficha=1;
  	   	     }
  	   	  if(i==1){                
  	   	    for(n=1; n<=2; n++)
  	   	  	  aux[n]=*(qu2+n-1);
  	   	  	  ficha=2;
  	   	    }
  	   	     if(i==2){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(al2+n-1);
  	   	  	  ficha=3;
  	   	     }  
  	   	     if(i==3){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(to2+n-1);
  	   	  	  ficha=4;
  	   	     }  
  	   	     if(i==4){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=*(ca2+n-1);
  	   	  	  ficha=5;
  	   	     }  
  	   	     if(i==5){
  	   	     	for(n=1; n<=16; n++)
  	   	  	   aux[n]=*(pe2+n-1);
  	   	  	  ficha=6;
				  }  //Revisar ejecutar primero
  	   	    
	  	   	    for(t=1; t<sizeof(aux)/sizeof(aux[1]); t++)
		  	   	  {
		  	   	  	   if(aux[t+1]==num2 && (t+1)%2==0)
		  	   	  	   {
		  	   	  	     aux1=1;
		  	   	  	   }
		  	   	  	   if(aux[t]==num1 && t%2!=0)
		  	   	  	   {
		  	   	  	   	 aux2=1;
		  	   	  	   }
		  	   	  	   if(aux1==1 && aux2==1)
		  	   	  	   {
		  	   	  	   	if(ficha==1)
		  	   	  	   	{
		  	   	  	   		*(re2+t-1)=110;
		  	   	  	   		*(re2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	}
		  	   	  	   	if(ficha==2)
		  	   	  	   	{
		  	   	  	   		*(qu2+t-1)=110;
		  	   	  	   		*(qu2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	}
		  	   	  	   	if(ficha==3)
		  	   	  	   	{
		  	   	  	   		*(al2+t-1)=110;
		  	   	  	   		*(al2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	} 
		  	   	  	   	if(ficha==4)
		  	   	  	   	{
		  	   	  	   		*(to2+t-1)=110;
		  	   	  	   		*(to2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	}
		  	   	  	   	if(ficha==5)
		  	   	  	   	{
		  	   	  	   		*(ca2+t-1)=110;
		  	   	  	   		*(ca2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	}
		  	   	  	   	if(ficha==6)
		  	   	  	   	{
		  	   	  	   	    
		  	   	  	   		*(pe2+t-1)=110;
		  	   	  	   		*(pe2+t)=110;
		  	   	  	   		return 1;
		  	   	  	   	}
		  	   	  	   }
		  	   	  	   aux1=0;
		  	   	  	   aux2=0;
		  	   	  	   
		  	   	  }
  	   	  
         }
 	
 }
 
 int *ValidarMovilidad(int ficha2,int playerX,int playerY, int peligro, int jugador,int ficha,int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe2[16]) 
 {
 	int i=0, p=1, n=0, aux[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, d=1, t=3, r=1;
 	int fila,columna, q=0,w=0, salir=0, aux1,aux2, contador=0, contador2, clave=0, fila2,columna2, valor;
 	static int datos[6];
 	char fil[256], col[256];
 	int k;
    
    origen:
    reg:
    printf("\n ingrese las coordenadas de origen");
    //FILA
  	printf("\n Fila= "); scanf("%s", fil); fflush(stdin);
    k=ValidarNumero(fil, 1);
    if(k==0){
    	goto reg;
    }
    fila=atoi(fil);
   reg2:
    //COLUMNA
  	printf("\n Columna= "); scanf("%s", col); fflush(stdin);
  	k=ValidarNumero(col, 1);
    if(k==0){
    	goto reg2;
    }
    columna=atoi(col);
  
  	// Validar rango
         if(fila<1 || fila>8 || columna<1 || columna>8)
         {
         	printf("\nCoordenada invalida");
         	goto origen;
         }
    //Validar que sea el origen  
    if(ficha==1)
    {
    	if(fila!=re[0] || columna!=re[1]){
     	printf("\n Ingrese la coordenada correspondiente");
     	goto origen;
       }
       	datos[3]=0;
    	datos[4]=1;
    }
    if(ficha==2)
    {
    	if(fila!=qu[0] || columna!=qu[1]){
     	printf("\n Ingrese la coordenada correspondiente");
     	goto origen;
       }
       datos[3]=0;
       datos[4]=1;
    }
	if(ficha==3)
	{
	   if((fila!=al[0] || columna!=al[1]) && (fila!=al[2] || columna!=al[3])){
	     	printf("\n Ingrese la coordenada correspondiente");
	     	goto origen;
       }
       if(fila==al[0] && columna==al[1])
       {
        datos[3]=0;
    	datos[4]=1;
       }
       if(fila==al[2] && columna==al[3])
       {
        datos[3]=2;
    	datos[4]=3;
       }
    }
    if(ficha==4)
	{ 
	   if((fila!=to[0] || columna!=to[1]) && (fila!=to[2] || columna!=to[3])){
     	printf("\n Ingrese la coordenada correspondiente");
     	goto origen;
       }
       if(fila==to[0] && columna==to[1])
       {
        datos[3]=0;
    	datos[4]=1;
       }
       if(fila==to[2] && columna==to[3])
       {
        datos[3]=2;
    	datos[4]=3;
       }
    }
    if(ficha==5)
	{
	   if((fila!=ca[0] || columna!=ca[1]) && (fila!=ca[2] || columna!=ca[3])){
     	printf("\n Ingrese la coordenada correspondiente");
     	goto origen;
       }
       if(fila==ca[0] && columna==ca[1])
       {
        datos[3]=0;
    	datos[4]=1;
       }
       if(fila==ca[2] && columna==ca[3])
       {
        datos[3]=2;
    	datos[4]=3;
       }
    }
    if(ficha==6)
    {
    	if((fila!=pe[0] || columna!=pe[1]) && (fila!=pe[2] || columna!=pe[3]) && (fila!=pe[4] || columna!=pe[5]) && (fila!=pe[6] || columna!=pe[7]) && (fila!=pe[8] || columna!=pe[9]) && (fila!=pe[10] || columna!=pe[11]) && (fila!=pe[12] || columna!=pe[13]) && (fila!=pe[14] || columna!=pe[15])){
     	printf("\n Ingrese la coordenada correspondiente");
     	goto origen;
       }
       if(fila==pe[0] && columna==pe[1])
       {
        datos[3]=0;
    	datos[4]=1;
       }
       if(fila==pe[2] && columna==pe[3])
       {
        datos[3]=2;
    	datos[4]=3;
       }
       if(fila==pe[4] && columna==pe[5])
       {
        datos[3]=4;
    	datos[4]=5;
       }
       if(fila==pe[6] && columna==pe[7])
       {
        datos[3]=6;
    	datos[4]=7;
       }
       if(fila==pe[8] && columna==pe[9])
       {
        datos[3]=8;
    	datos[4]=9;
       }
       if(fila==pe[10] && columna==pe[11])
       {
        datos[3]=10;
    	datos[4]=11;
       }
       if(fila==pe[12] && columna==pe[13])
       {
        datos[3]=12;
    	datos[4]=13;
       }
       if(fila==pe[14] && columna==pe[15])
       {
        datos[3]=14;
    	datos[4]=15;
       }
    }
         p=1;
        //Alfil, reina y rey
    	if(ficha==3 || ficha==1 || ficha==2)
    	{
    		for(q=1; q<=4; q++)
    		{
    			if(q==1)
    			{
    			fila2=fila+1;
    			columna2=columna+1;
    		    }
    		    if(q==2)
    		    {
    		    	fila2=fila-1;
    		    	columna2=columna+1;
    		    }
    		    if(q==3)
    		    {
    		    	fila2=fila+1;
    		    	columna2=columna-1;
    		    }
    		    if(q==4)
    		    {
    		    	fila2=fila-1;
    		    	columna2=columna-1;
    		    }
    		    clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		    if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				if((peligro==1 && clave==1) || (ficha==1 && clave==1))
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		// ficha rey
						  if(valor==1 && q<5)
    		      		{    
    		      		    datos[t]=fila2;
    		      		    datos[t+1]=columna2;
    		      			clave=0;
    		      			t=t+2;
    		      		}
    		      		if(ficha==1 && q>=5)
    		      		{
    		      			datos[0]=fila;
    		         	    datos[1]=columna;
    		      			datos[2]=1;
    		      			return datos;
    		      		}
    		      		//Otra ficha
    		      		 if(valor==0 && ficha!=1)
    		      		{
    		      			clave=0;
    		      		}
    		      		if(valor==1 && ficha!=1)
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      		
    		      	}
    		      if(clave==1)
    		      {
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }
    		    
    		}
    	}
    	//Torre, reina y rey
    	if(ficha==4 || ficha==1 || ficha==2)
    	{
    		for(q=1; q<=4; q++)
    		{
    			if(q==1)
    			{
    			fila2=fila;
    			columna2=columna+1;
    		    }
    		    if(q==2)
    		    {  
    		    	fila2=fila;
    		    	columna2=columna-1;
    		    }
    		    if(q==3)
    		    {   
    		    	fila2=fila+1;
    		    	columna2=columna;
    		    }
    		    if(q==4)
    		    {   
    		    	fila2=fila-1;
    		    	columna2=columna;
    		    }
    		    
    		     clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		     if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				  if((peligro==1 && clave==1) || (ficha==1 && clave==1))
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		 //ficha rey
    		      		  if(valor==1 && q<5)
    		      		{    
    		      		    datos[t]=fila2;
    		      		    datos[t+1]=columna2;
    		      			clave=0;
    		      			t=t+2;
    		      		}
    		      		
    		      		if(ficha==1 && q>=5)
    		      		{
    		      			datos[0]=fila;
    		         	    datos[1]=columna;
    		      			datos[2]=1;
    		      			return datos;
    		      		}
    		      		//Otra ficha
						  if(valor==0 && ficha!=1)
    		      		{
    		      			clave=0;
    		      		}
    		      		if(valor==1 && ficha!=1)
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
    		      if(clave==1)
    		      {
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }
    		    
    		}
    	}
    //Caballo	
    if(ficha==5)
    {
    	for(q=1; q<=8; q++)
    	{
    		if(q==1)
    		{
    			fila2=fila-2;
    			columna2=columna+1;
    		}
    		if(q==2)
    		{
    			fila2=fila-2;
    			columna2=columna-1;
    		}
    		if(q==3)
    		{
    			fila2=fila-1;
    			columna2=columna2+2;
    		}
    		if(q==4)
    		{
    			fila2=fila+1;
    			columna2=columna2+2;
    		}
    		if(q==5)
    		{
    			fila2=fila+2;
    			columna2=columna-1;
    		}
    		if(q==6)
    		{
    			fila2=fila+2;
    			columna2=columna+1;
    		}
    		if(q==7)
    		{
    			fila2=fila-1;
    			columna2=columna2-2;
    		}
    		if(q==8)
    		{
    			fila2=fila+1;
    			columna2=columna2-2;
    		}
    		clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				  if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
    		      if(clave==1)
    		      {
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }
    	}
    }
    //Peon jugador 1
    if(ficha==6 && jugador==1)
    {   
        // Validar de que haya una ficha contraria en la diagonal proxima
        p=2;
        for(q=1; q<=2; q++)
        {   
        	if(q==1)
        	{
        		fila2=fila+1;
        		columna2=columna+1;
        	}
        	if(q==2)
        	{
        		fila2=fila+1;
        		columna2=columna-1;
        	}
        	clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
        	if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
        	if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}
    		      		else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
        	if(clave==1)
        	{
        		datos[0]=fila;
		      	datos[1]=columna;
		      	datos[2]=1;
		      	return datos;
        	}
        	if(q>2 && clave==0)
        	 {
        	 	datos[2]=0;
        	 	return datos;
        	 }
        }
        
        d=1;
        if(fila==2)
          d=2;
          
         q=1;
         p=1;
    	for(q=1; q<=d; q++)
    	{
    		if(q==1)
    		{
    			fila2=fila+1;
    			columna2=columna;
    		}
    		if(q==2)
    		{
    			fila2=fila+2;
    			columna2=columna;
    		}
    		clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				if(peligro==1 && clave==1)
    		      	{
    		      		printf("Entro");
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
		      if(clave==1)
		      {
		      	datos[0]=fila;
		      	datos[1]=columna;
		      	datos[2]=1;
		      	return datos;
		      }
    	}
    	
    }
	    //Peon jugador 2
	    if(ficha==6 && jugador==0)
	    {  
		     p=2;
	        for(q=1; q<=2; q++)
	        {   
	        	if(q==1)
	        	{
	        		fila2=fila-1;
	        		columna2=columna+1;
	        	}
	        	if(q==2)
	        	{
	        		fila2=fila-1;
	        		columna2=columna-1;
	        	}
	        	clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
	        	if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
        	     if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
	        	if(clave==1)
	        	{
	        		datos[0]=fila;
			      	datos[1]=columna;
			      	datos[2]=1;
			      	return datos;
	        	}
	        }
		     
		     d=1;
	    	if(fila==7)
	        	d=2;
				 q=1;
		         p=1;
	         
	    	for(q=1; q<=1; q++)
	    	{
	    		if(q==1)
	    		{
	    			fila2=fila-1;
	    			columna2=columna;
	    		}
	    		if(q==2)
	    		{
	    			fila2=fila-2;
	    			columna2=columna;
	    		}
	    		clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
	    		if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0; 
				
				  if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
    		      if(clave==1)
    		      {
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }
		    }	    
			    			
		}
    	p=2;
		   //Peon jugador 1
      if(ficha==6 && jugador==1)
      {   q=1;
      	for(q=1; q<=2; q++)
      	{
      		if(q==1)
    		{
    			fila2==fila+1;
    			columna2=columna-1;
    			
				clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
				if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				  if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
    		      if(clave==1)
    		      {
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }		  
		    }
		  if(q==2)
		  {
		  	fila2==fila+1;
			columna2=columna+1;
		  	
			clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
			if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
				
		      if(clave==1)
		      {
		      	datos[0]=fila;
		      	datos[1]=columna;
		      	datos[2]=1;
		      	return datos;
		      }		  
		  }		  
				  
      }
     }
     if(ficha==6 && jugador==0)
     {
     	for(q=1; q<=2; q++)
      	{
      		if(q==1)
    		{
    			fila2==fila-1;
    			columna2=columna-1;
    			
				 clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
				 if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				  if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}
    		      	}
				
    		      if(clave==1)
    		      { 
				    
    		      	datos[0]=fila;
    		      	datos[1]=columna;
    		      	datos[2]=1;
    		      	return datos;
    		      }		  
		    }
		  if(q==2)
		  {
		  	fila2==fila-1;
			columna2=columna+1;
		  	
			clave=RecorrerArreglo( p, fila2, columna2,  re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
			if(fila2<1 || fila2>8 || columna2<1 || columna2>8)
				clave=0;
				
				if(peligro==1 && clave==1)
    		      	{
    		      		valor=PostJaque(jugador,fila2, columna2, ficha2,ficha, fila, columna,playerX, playerY, re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe2);
    		      		if(valor==0)
    		      		{
    		      			clave=0;
    		      		}else
    		      		{
    		      			datos[3]=fila2;
    		      			datos[4]=columna2;
    		      		}
    		      	}
			
		      if(clave==1)
		      {
		      	datos[0]=fila;
		      	datos[1]=columna;
		      	datos[2]=1;
		      	return datos;
		      }		  
		  }		  
				  
      }
     }
        
     datos[0]=fila;
   	 datos[1]=columna;
  	 datos[2]=0;
     return datos;
  }
  int RecorrerArreglo(int p, int fila, int columna, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe2[16])
  {
  	int i=0,t=0, n=0,aux[40]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},validar, aux1=0,aux2=0;
  
  	for(i=0; i<6; i++)
  	   {  n=1;
  	   if(p==1 || p==3)
  	     {
  	   	  if(i==0){
  	   	  	for(n=1; n<=2; n++)
  	   	  	  aux[n]=re[n-1];
  	   	     }
  	   	  if(i==1){                
  	   	    for(n=1; n<=2; n++)
  	   	  	  aux[n]=qu[n-1];
  	   	    }
  	   	     if(i==2){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=al[n-1];
  	   	     }  
  	   	     if(i==3){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=to[n-1];
  	   	     }  
  	   	     if(i==4){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=ca[n-1];
  	   	     }  
  	   	     if(i==5){
  	   	     	for(n=1; n<=16; n++)
  	   	  	  aux[n]=pe[n-1];
				  }
		  }
		   if(p==2 || p==3)
		   {
		   
			 if(i==0){
  	   	  	for(n=1; n<=2; n++)
  	   	  	  aux[n]=re2[n-1];
  	   	     }
  	   	     if(i==1){                
  	   	    for(n=1; n<=2; n++)
  	   	  	  aux[n]=qu2[n-1];
  	   	     }
  	   	     if(i==2){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=al2[n-1];
  	   	     }  
  	   	     if(i==3){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=to2[n-1];
  	   	     }  
  	   	     if(i==4){
  	   	     	for(n=1; n<=4; n++)
  	   	  	  aux[n]=ca2[n-1];
  	   	     }  
  	   	     if(i==5){
  	   	     	for(n=1; n<=16; n++)
  	   	  	   aux[n]=pe2[n-1];
				  }	
		   }
		  
				    //Revisar ejecutar primero
  	   	    
	  	   	    for(t=1; t<sizeof(aux)/sizeof(aux[1]); t++)
		  	   	  {
		  	   	  	   if(aux[t+1]==columna && (t+1)%2==0)
		  	   	  	   {
		  	   	  	   	 aux1=1;
		  	   	  	   }
		  	   	  	   if(aux[t]==fila && t%2!=0)
		  	   	  	   {
		  	   	  	   	 aux2=1;
		  	   	  	   }
		  	   	  	   if(aux1==1 && aux2==1)
		  	   	  	   {
		  	   	  	   	return 0;
		  	   	  	   }
		  	   	  	   aux1=0;
		  	   	  	   aux2=0;
		  	   	  	   
		  	   	  }
  	   	  
  	   }
  	   return 1;
  }
  
   int Jaque( int jugador, int ficha, int fila, int columna, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16])
   {   
     int p=1,r=1, i=0, *valor, q=1, columna2, aux1, aux2, a[4];
     valor=a;
     //Rey
     if(ficha==1)
     {
     	return 0;
     }
     //Alfil y reina
        valor=MoverFicha(jugador, ficha, fila, columna,re, qu, al, to, ca, pe, re2, qu2,al2,to2, ca2,pe100 );
 	    if(*(valor)==1)
		{
			for(p=1; p<=8; p++)
			{
				if(*(valor+r)==re2[0] && *(valor+r+1)==re2[1])
				{
					printf("\n Jaque"); 
		 			getch();
		 			return 1;
				}
				r=r+2;
			}

 		}
  	  
   	   return 0;
   }
  
  int PostJaque(int jugador, int fila2, int columna2, int ficha2,int ficha, int fila, int columna, int playerX, int playerY, int re[2],int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16])
  {
  	int i,valor, array[19],aux1, aux2, m=1,q=0,x,y, r, a[4], valor2, vp,t=1, b=1, w=1, p, l;
  	int *ValorRey=a;
  	
  	x=playerX;
	y=playerY;
  	      //La ficha que hace jaque es un alfil
  	   if(ficha2==3 || ficha2==2)
		 {
  	      //Validar diagonal superior izquierda
  	     if(playerX>re[0] && playerY>re[1])
  	     {
  	     	for(playerX ; playerX>re[0]; i--)
			 {
  	     		playerY--;
  	     		
  	     		array[t]=playerX;
  	     		array[t+1]=playerY;
  	     		
  	     		t=t+2;
  	     	 }	
  	     }
		   //Validar diagonal superior derecha
		   if(playerX>re[0] && playerY<re[0])
  	     {
  	     	for(playerX; playerX>re[0]; playerX--){
  	     		playerY++;
  	     	
			   	array[t]=playerX;
  	     		array[t+1]=playerY;
  	     		
  	     		t=t+2;  
  	     	}
  	     	  
  	     }//Validar diagonal inferior izquierda
  	     if(playerX<re[0] && playerY>re[1])
  	     {
  	     	for(playerX; playerX<re[0]; playerX++){
  	     		playerY--;
  	     		
  	     		array[t]=playerX;
  	     		array[t+1]=playerY;
  	     		
  	     		t=t+2;
  	     		
  	     	}
  	     	  
  	     }
  	      //Validar diagonal inferior derecha
  	      if(playerX<re[0] && playerY<re[1])
  	     {
  	     	for(playerX; playerX<re[0]; playerX++){
  	     		playerY++;
  	     		
  	     		array[t]=playerX;
  	     		array[t+1]=playerY;
  	     		
  	     		t=t+2;
  	     	}
  	     	  
  	     }
       }

	   
	   t=1;
       if(ficha2==2 || ficha2==4)
       {
       	 //Validar ficha en la horizontal izquierda
  	     if(x==re[0] && y>re[1])
  	     {   
  	     	for(y; y>re[1]; y--){
  	     		array[t]=x;
  	     		array[t+1]=y;
  	     		
  	     		t=t+2;  
  	     	}
		  }
  	     //Validar ficha en la horizontal derecha
  	     if(x==re[0] && y<re[1])
  	     {   
  	     	for(x; x<re[1]; x++){
  	     		array[t]=x;
  	     		array[t+1]=y;
  	     		
  	     		t=t+2; 
  	     	} 
		   	
  	     }
  	     //Validar ficha en la vertical inferior
  	     if(y==re[1] && x<re[0])
  	     {   
  	     	for(x; x<re[0]; x++){
  	     	      array[t]=x;
  	     	   	  array[t+1]=y;
  	     		
  	     		t=t+2; 
  	     		}	  
  	      } 
  	     
  	     //Validar ficha en la vertical superior
  	     if(y==re[1] && x>re[0])
  	     {   
  	     	for(x; x>re[0]; x--){
  	     		  array[t]=x;
  	     	   	  array[t+1]=y;
  	     		
  	     		  t=t+2; 
  	     		}	  
  	      } 
		   	
  	   }
  	   x=playerX;
  	   y=playerY;
  	   t=1;
  	   if(ficha2==5)
  	   {
  	   	  array[t]=x;
  	   	  array[t+1]=y;
  	   	
  	   }
  	   x=playerX;
  	   y=playerY;
  	   t=1;
  	   if(ficha2==6)
  	   {
  	   	  array[t]=x;
  	   	  array[t+1]=y;
  	   	
  	   }
  	   
  	   if(ficha2==1)
  	   {
  	   	 return 0;
  	   }
  	   
  	   if(jugador==1)
  	   {
  	   	jugador=2;
  	   }else 
  	   jugador=1;
  	          //Validar movilidad para prevenir el jaque con el REY
  	   if(ficha==1)
  	   {
  	   	 ValorRey=MoverFicha(jugador, 2, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	   	 if(*(ValorRey)==1)
  	   	 {
  	   	 	for(b=1; b<=8; b++)
  	   	 	{
  	   	 	  if((qu2[0]==*(ValorRey+w) && qu2[1]==*(ValorRey+w+1)) || (qu2[2]==*(ValorRey+w) && qu2[3]==*(ValorRey+w+1)))
  	   	 	  {
  	   	 	  	    printf("Jaque con la reina");
  	   	 	  	    getch();
  	   	 	  	    return 0;
  	   	 	  } 
  	   	 	  w=w+2;
  	   	    }
  	     }
  	     b=1;
  	     w=1;
  	     ValorRey=MoverFicha(jugador, 3, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	   	 if(*(ValorRey)==1 )
  	   	 {  printf("Nuevo");
  	   	 	for(b=1; b<=4; b++)
  	   	 	{
  	   	 	  if((al2[0]==*(ValorRey+w) && al2[1]==*(ValorRey+w+1)) || (al2[2]==*(ValorRey+w) && al2[3]==*(ValorRey+w+1)))
  	   	 	  {
  	   	 	  	    printf("Jaque con el alfil");
  	   	 	  	    getch();
  	   	 	  	    return 0;
  	   	 	  } 
  	   	 	  w=w+2;
  	   	    }
  	     }
  	     b=1;
  	     w=1;
  	   	 ValorRey=MoverFicha(jugador, 4, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	   	 if(*(ValorRey)==1 )
  	   	 {
  	   	 	  for(b=1; b<=4; b++)
	  	   	 	{
	  	   	 	  if((to2[0]==*(ValorRey+w) && to2[1]==*(ValorRey+w+1)) || (to2[2]==*(ValorRey+w) && to2[3]==*(ValorRey+w+1)))
	  	   	 	  {
	  	   	 	  	    printf("Jaque con torre");
	  	   	 	  	    getch();
	  	   	 	  	    return 0;
	  	   	 	  } 
	  	   	 	  w=w+2;
	  	   	    }
  	     }
  	     b=1;
  	     w=1;
  	     ValorRey=MoverFicha(jugador, 5, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	   	 if(*(ValorRey)==1 )
  	   	 {
  	   	 	  for(b=1; b<=4; b++)
	  	   	 	{
	  	   	 	  if((ca2[0]==*(ValorRey+w) && ca2[1]==*(ValorRey+w+1)) || (ca2[2]==*(ValorRey+w) && ca2[3]==*(ValorRey+w+1)))
	  	   	 	  {
	  	   	 	  	    printf("Jaque con el caballo");
	  	   	 	  	    getch();
	  	   	 	  	    return 0;
	  	   	 	  } 
	  	   	 	  w=w+2;
	  	   	    } 
  	     }
  	     b=1;
  	     w=1;
  	     ValorRey=MoverFicha(jugador, 6, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	   	 if(*(ValorRey)==1 )
  	   	 {
  	   	 	  for(b=1; b<=2; b++)
	  	   	 	{
	  	   	 	  if((pe100[0]==*(ValorRey+w) && pe100[1]==*(ValorRey+w+1)) || (pe100[2]==*(ValorRey+w) && pe100[3]==*(ValorRey+w+1)) || (pe100[4]==*(ValorRey+w) && pe100[5]==*(ValorRey+w+1)) || (pe100[6]==*(ValorRey+w) && pe100[7]==*(ValorRey+w+1)) || (pe100[8]==*(ValorRey+w) && pe100[9]==*(ValorRey+w+1)) || (pe100[10]==*(ValorRey+w) && pe100[11]==*(ValorRey+w+1)) || (pe100[12]==*(ValorRey+w) && pe100[13]==*(ValorRey+w+1)) || (pe100[14]==*(ValorRey+w) && pe100[15]==*(ValorRey+w+1)))
	  	   	 	  {
	  	   	 	  	    printf("Jaque con el peon");
	  	   	 	  	    getch();
	  	   	 	  	    return 0;
	  	   	 	  } 
	  	   	 	  w=w+2;
	  	   	    }
  	     }
  	     b=1;
  	     w=1;
  	     ValorRey=MoverFicha(jugador, 1, fila2, columna2 ,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
         if(*(ValorRey)==1 )
  	   	 {
  	   	 	  for(b=1; b<=8; b++)
	  	   	 	{
	  	   	 	  if((re2[0]==*(ValorRey+w) && re2[1]==*(ValorRey+w+1)))
	  	   	 	  {
	  	   	 	  	    printf("Jaque con el rey");
	  	   	 	  	    getch();
	  	   	 	  	    return 0;
	  	   	 	  } 
	  	   	 	  w=w+2;
	  	   	    }
  	     }
  	      return 1;
  	     
         }
  	
       r=1;
       aux1=fila2;
  	   aux2=columna2;
  	   q=1;
      if(ficha==5 || ficha==4 || ficha==3 || ficha==2 || ficha==6)
      {  l=sizeof(array)/sizeof(array[1]);
      	for(r=1; r<=l/2; r++)
      	{   
	 		   if(aux1==array[q] && aux2==array[q+1])
	 		   {
	 		   	  return 1;
	 		   }
			   q=q+2;		
     	   }      
		    return 0;
		    
      }
      
  }    
  int* MoverFicha(int jugador, int ficha, int fila, int columna, int re[2] ,int qu[2],int al[4],int to[4],int ca[4],int pe[16], int re2[2],int qu2[2],int al2[4],int to2[4],int ca2[4],int pe100[16])  
  {
  	int aux1, aux2, q=1, i, columna2, valor=0, t=1, p=1;
  	static int datos[20];
  	datos[0]=0;
  	
  	 p=1;
  	 aux1=fila;
  	 aux2=columna;
  	 //Validar diagonal superior izquierda
  	  if(ficha==2 || ficha==3)
		{
  	     	for(i=aux1-1; i>=1; i--){
  	     		aux2--;
	  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
	  	     		if(valor==1)
					{ 
					    
						datos[0]=1;
						datos[1]=i;
						datos[2]=aux2;	
						break;
	  	     	    }
	  	     	} 
  	     
  	     aux1=fila;
   	   	 aux2=columna;
		   //Validar diagonal superior derecha
		 	for(i=aux1-1; i>=1; i--){
  	     		aux2++;
  	     		
  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     		   datos[0]=1;
					datos[3]=i;
					datos[4]=aux2;
					break;
  	     		}
  	     	}
		   aux1=fila;
   	   	 aux2=columna;
		   //Validar diagonal inferior izquierda
  	     	for(i=aux1+1; i<=8; i++){
  	     		aux2--;
  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     			datos[0]=1;
					datos[5]=i;
					datos[6]=aux2;
					break;
  	     		}
  	     	}
  	     aux1=fila;
   	   	 aux2=columna;
  	      //Validar diagonal inferior derecha
  	     	for(i=aux1+1; i<=8; i++){
  	     		aux2++;
  	
  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     	    if(valor==1)
				{
  	     			datos[0]=1;
					datos[7]=i;
					datos[8]=aux2;
					break;
  	     		}
  	     	}
  	     	
     }
     valor=0;
     if(ficha==2 || ficha==4)
     {
     	 aux1=fila;
  	     aux2=columna;
  	        //Validar ficha en la horizontal izquierda
  	     	for(i=aux2-1; i>1; i--){
  	     		valor=DestinoValidar(p,aux1,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			if(ficha==2)
  	     			{
  	     				datos[0]=1;
						datos[9]=aux1;
						datos[10]=i;
						break;
  	     			}else
  	     			{
  	     			datos[0]=1;
					datos[1]=aux1;
					datos[2]=i;
					break;
				    }
  	     		}
  	     	}
		  aux1=fila;
  	        aux2=columna;
  	     //Validar ficha en la horizontal derecha  
  	     	for(i=aux2+1; i<8; i++){
  	     		valor=DestinoValidar(p,aux1,i,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			if(ficha==2)
  	     			{
  	     				datos[0]=1;
						datos[11]=aux1;
						datos[12]=i;
						break;
  	     			}else
  	     			{
  	     			datos[0]=1;
					datos[3]=aux1;
					datos[4]=i;
					break;
				    }
  	     		}
  	     	}
  	     	aux1=fila;
  	        aux2=columna;
  	     //Validar ficha en la vertical inferior 
  	     	for(i=aux1+1; i<8; i++){
  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			if(ficha==2)
  	     			{
  	     				datos[0]=1;
						datos[13]=aux1;
						datos[14]=i;
						break;
  	     			}else
  	     			{
  	     			datos[0]=1;
					datos[5]=aux1;
					datos[6]=i;
					break;
				    }
  	     		}
  	     		  
  	     	} 
  	     	aux1=fila;
  	        aux2=columna;
  	     //Validar ficha en la vertical superior
  	     	for(i=aux1-1; i>1; i--){
  	     		valor=DestinoValidar(p,i,aux2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1){
  	     			if(ficha==2)
  	     			{
  	     				datos[0]=1;
						datos[15]=aux1;
						datos[16]=i;
						break;
  	     			}else
  	     			{
  	     			datos[0]=1;
					datos[7]=aux1;
					datos[8]=i;
					break;
				    }
  	     		}  
  	     	}
     }
     //Caballo
     q=1;
     valor=0;
     t=1;
     if(ficha==5)
     {
     	aux1=fila;
  	    aux2=columna;
    	for(q=1; q<=8; q++)
    	{
    		aux1=fila;
   	   	    aux2=columna;
    		if(q==1)
    		{
    			i=aux1-2;
    			columna2=aux2+1;
    			 
    		}
    		if(q==2)
    		{
    			i=aux1-2;
    			columna2=aux2-1;
    		}
    		if(q==3)
    		{
    			i=aux1-1;
    			columna2=aux2+2;
    		}
    		if(q==4)
    		{
    			i=aux1+1;
    			columna2=aux2+2;
    		}
    		if(q==5)
    		{
    			i=aux1+2;
    			columna2=aux2-1;
    		}
    		if(q==6)
    		{
    			i=aux1+2;
    			columna2=aux2+1;
    		}
    		if(q==7)
    		{
    			i=aux1-1;
    			columna2=aux2-2;
    		}
    		if(q==8)
    		{
    			i=aux1+1;
    			columna2=aux2-2;
    		}
   
  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     			datos[0]=1;
					datos[t]=i;
					datos[t+1]=columna2;
					
  	     		}
  	     		t=t+2;
   	      }
   	   
     }
     //Peon jugador 1
     t=1;
   	   if(ficha==6 && jugador==1)
   	   {
   	   	 aux1=fila;
   	   	 aux2=columna;
   	   	  for(q=1; q<=2; q++)
   	   	  {
   	   	  	if(q==1)
   	   	  	{
   	   	  		i=aux1+1;
   	   	  		columna2=aux2+1;
   	   	  	}
   	   	  	if(q==2)
   	   	  	{
   	   	  		i=aux1+1;
   	   	  		columna2=aux2-1;
   	   	  	}

  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     			datos[0]=1;
					datos[t]=i;
					datos[t+1]=columna2;
				
  	     		}
  	     		t=t+2;
   	   	  }
   	   }
   	   q=1;
   	   t=1;
   	   //Peon jugador 2
   	   if(ficha==6 && jugador==0)
   	   {
   	   	
   	   	  for(q=1; q<=2; q++)
   	   	  {
   	   	  	 aux1=fila;
   	   	     aux2=columna;
   	   	  	if(q==1)
   	   	  	{
   	   	  		i=aux1-1;
   	   	  		columna2=aux2+1;
   	   	  	}
   	   	  	if(q==2)
   	   	  	{
   	   	  		i=aux1-1;
   	   	  		columna2=aux2-1;
   	   	  	}

  	     		valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     		    datos[0]=1;
					datos[t]=i;
					datos[t+1]=columna2;
  	     		}
  	     		t=t+2;
   	   	  }
   	   }
   	    aux1=fila;
   	   	 aux2=columna;
   	   if(ficha==1)
   	   {
   	   	for(q=1; q<=8; q++)
   	   	{
   	   	        if(q==1)
    			{
    			i=aux1+1;
    			columna2=aux2+1;
    		    }
    		    if(q==2)
    		    {
    		    	i=aux1-1;
    		    	columna2=aux2+1;
    		    }
    		    if(q==3)
    		    {
    		    	i=aux1+1;
    		    	columna2=aux2-1;
    		    }
    		    if(q==4)
    		    {
    		    	i=aux1-1;
    		    	columna2=aux2-1;
    		    }
    		    if(q==5)
    			{
    			i=aux1;
    			columna2=aux2+1;
    		    }
    		    if(q==6)
    		    {  
    		    	i=aux1;
    		    	columna2=aux2-1;
    		    }
    		    if(q==7)
    		    {   
    		    	i=aux1+1;
    		    	columna2=aux2;
    		    }
    		    if(q==8)
    		    {   
    		    	i=aux1-1;
    		    	columna2=aux2;
    		    }
    		    valor=DestinoValidar(p,i,columna2,re, qu,al, to, ca, pe,re2, qu2,al2, to2, ca2, pe100);
  	     		if(valor==1)
				{
  	     		    datos[0]=1;
					datos[t]=i;
					datos[t+1]=columna2;
  	     		}
  	     		t=t+2;
    	  }
   	   }
   	   return datos;
   	   
    }
 
 int ValidarNumero(char array[], int opcion)
 {
 	int i;
 	for(i=0; i<strlen(array); i++)
 	{
 		if(!isdigit(array[i]) && opcion==1){
 			printf("No es un numero");
 			return 0;
 			break;
 		}
 	}
 	return 1;
 }     
  
  void GuardarMove(int fila , int columna , int indice)
  {
  	char a[9][3]={"T1", "C1", "A1","Q1", "R1", "P1"};
  	char b[9][3]={"T2", "C2", "A2","Q2", "R2", "P2"};
  	if(gamer==1)
  	{
  		FILE *archivo= fopen("jugador1.txt", "ab");
	 	if(archivo!=NULL)
	 	{
	 		fprintf(archivo, "\n-------------------------------------------------------------------\n");
	 		fprintf(archivo,"            %s                      %d                 %d        ", a[indice], fila, columna);
	 		
	 		fclose(archivo);
	 		
		}
		gamer=2;
  	}else
  	{   
  		FILE *archivo= fopen("jugador2.txt", "ab");
	 	if(archivo!=NULL)
	 	{
	 		fprintf(archivo, "\n-------------------------------------------------------------------\n");
	 		fprintf(archivo,"            %s                      %d                 %d        ", b[indice], fila, columna);
	 		
	 		fclose(archivo);
	 		
		}
		gamer=1;
  	}
  	
  }
