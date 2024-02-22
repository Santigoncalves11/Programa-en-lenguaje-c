#include <stdio.h>

 int main(){
     int filas = 3;
     int columas = 5;

     int A [3][5] = {{51,21,33,49,51},
                     {12,22,34,84,95},
                     {19,21,23,51,57}};

     int i,j,c = -1,f = -1;
     int dato = 51;

     for(i=0;i<filas;i++){
        for(j=0;j<columas;j++){
            if(A[i][j] == dato){
                f = i+1;
                c = j+1;
                printf("El dato se encuentra el la fila %d y la columna %d\n",f,c);

            }
        }

     }

     if(c == -1 && f == -1){
        printf("El dato no esta en el arreglo\n");
     }

    return 0;
 }
