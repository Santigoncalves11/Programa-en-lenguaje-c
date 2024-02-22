//realizar un programa en lenguaje c llamado vendedores cree un array de 18x10 e indican que poseemos una empresa de 18 vendedores cada uno de los cuales vende 10 producto. El array
//almacena los ingresos obtenidos por cada vendedor en cada producto, de modo que un menu permite almacenar los ingresos, revisar al total de cada vendedor y obtener los ingresos 
//totales.
//1- Sumar la cantidad de articulos por vendedor y almacenarlo en un vector. 
//2- Cual fue el vendedor que obtuvo la menor venta de articulos.
//3- Validar cada una de las opciones e imprimir el resultado de cada actividad. 
//4) Validar en caso que la opcion sea incorrecta. 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 18

   int validar(char []);
  main()

  {

  	int i,t,b,r,v,p,s,aux,cantidad;

  	char nombres[][100]={};

	int  articulo[4][4],suma[100]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};

     

    do{

	 

	    printf("Cuantos vendedores son? \n"); scanf("%d", &cantidad);

	    if(cantidad>MAX)

	    printf("Ingrese un maximo de 100 vendedores\n");

    

    }while(cantidad>MAX);

  	for(i=1; i<=cantidad; i++)

  	{

  		//system("cls");e

  		printf("Ingrese el nombre\n");

  		scanf("%s", nombres[i]);

  		

  		for(t=1; t<4; t++)

  		{

  			printf("Ingrese los articulos\n");

  		    scanf("%d", &articulo[i][t]);

			suma[i]+=articulo[i][t];

		}

  		

    }

    

    getch();

    system("cls");

    

    printf("Vendedores   art1  art2  art3\n");

    for(s=1; s<=cantidad; s++)

  	{

  		printf(" %s       %d      %d     %d\n", nombres[s], articulo[s][1], articulo[s][2], articulo[s][3]);	

	}

    

	for(p=1; p<=cantidad; p++)

	{

		printf("La cantidad de articulos de %s es= %d\n", nombres[p], suma[p]);

	    

	}

  	v=suma[2];

  	 for(b=1; b<cantidad ;b++)

  	 {

  	 	if(suma[b]<v)

  	 	{

  	 		v=suma[b];

	    }



	}

  	

  	printf("El menor es %d", v);

  	





  	

  	getch();

  }

  

  int validar(char num[])

  {

  	int i;

  	for(i=0; i<strlen(num); ++i)

  	{

  		if(!isdigit(num[i]))

  		{

  			printf("Ingrese solo numeros, porfavor");

  			return 0;

		  }

	}

  	return 1;

  }