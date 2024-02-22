#include <stdio.h>

void mostrarTodasTablas();
void mostrarTablaUnica(int);

int main(){
    int opc,tabla;
    do{
    printf("Selecciona una opcion\n");
    printf("1 -> Todas las tablas\n");
    printf("2 -> Una sola tabla\n");
    printf("3 -> Salir\n");
    scanf("%d",&opc);

    if(opc == 1){
        mostrarTodasTablas();
    }else if(opc == 2){
        printf("Ingresa el numero de la tabla ");
        scanf("%d",&tabla);
        mostrarTablaUnica(tabla);
    }
    }while(opc != 3);
    return 0;
}

void mostrarTodasTablas(){
    int i,j;
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            printf("%d x %d = %d\n",i,j,i*j);
        }
        printf("\n ******************** \n\n");
    }

}

void mostrarTablaUnica(int tabla){
    int i;

    for(i=1;i<=10;i++){
        printf("%d x %d = %d\n",i,tabla,i*tabla);
    }

}
