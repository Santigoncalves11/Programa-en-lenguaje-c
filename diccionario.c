
#ifndef DICCIONARIO_H
#define DICCIONARIO_H
typedef struct pareja       {
        const char * llave;
        const char * valor; } pareja;

typedef struct Diccionario  {
        pareja * parejas;
        int dimencion;      } diccionario;

typedef struct arreglo      {
    const char ** significado;
    int dimencion;          }arreglos;

diccionario * diccionario_nuevo(void);
void diccionario_agrega(diccionario * dicc, const char * llave,const char * valor);
void diccionario_imprime(const diccionario * dicc);
void diccionario_aumenta(diccionario ** dicc, int cantidad);
void diccionario_copia(const diccionario * origen, diccionario * copia, int cantidad);
void diccionario_liberar(diccionario * dicc);
void diccionario_inicializa(diccionario * dicc);
const char * diccionario_busca_valor(const diccionario * dicc, const char * palabra);
const char * diccionario_busca_llave(const diccionario * dicc, const char * palabra);
arreglos * busca_llaves(const diccionario * dicc, const char * palabra);
arreglos * nusca_valores(const diccionario * dicc, const char * palabra);
void liberar_arreglos(arreglos * a);
void imprime_arreglos(const arreglos *a);

#endif
/************************************************************/

#include "diccionario.h"
#include <stdlib.h>
#include <stdio.h>

diccionario * diccionario_nuevo(void){
    diccionario * D =(diccionario*)malloc(sizeof(diccionario));
    D->parejas = NULL;
    D->dimencion = 0;
    return D;
}
void diccionario_agrega(diccionario * dicc, const char * llave,\
                                            const char * valor){
    if(dicc == NULL)return;
    diccionario_aumenta(&dicc,1);
    dicc->parejas[dicc->dimencion-1].llave = llave;
    dicc->parejas[dicc->dimencion-1].valor = valor;
    }
void diccionario_imprime(const diccionario * dicc){
    int i;
    for(i = 0; i < dicc->dimencion; ++i)
        printf("%s : %s\n",dicc->parejas[i].llave,\
                           dicc->parejas[i].valor);
}
void diccionario_aumenta(diccionario ** dicc, int cantidad){
    if(dicc[0] == NULL)return;

    diccionario *E = diccionario_nuevo();
    E->dimencion = dicc[0]->dimencion;
    E->parejas = (pareja*)calloc(E->dimencion,sizeof(pareja));
    diccionario_inicializa(E);
    diccionario_copia(dicc[0],E,E->dimencion);
    diccionario_liberar(dicc[0]);
    dicc[0]=diccionario_nuevo();
    dicc[0]->dimencion = E->dimencion + cantidad;
    dicc[0]->parejas = (pareja*)calloc(dicc[0]->dimencion,sizeof(pareja*));
    diccionario_inicializa (dicc[0]);
    diccionario_copia(E,dicc[0],E->dimencion);
    diccionario_liberar(E);         }
    
void diccionario_copia(const diccionario * origen,\
                             diccionario * copia, int cantidad){
    if(origen == NULL||origen->dimencion == 0) return;
    int i;

    for(i = 0; i < cantidad;++i) {
        copia->parejas[i].llave = origen->parejas[i].llave;
        copia->parejas[i].valor = origen->parejas[i].valor;}}
        
void diccionario_liberar(diccionario * dicc){
    if(dicc == NULL) return;
    int i;
    free(dicc->parejas);
    free(dicc);                             }

void diccionario_inicializa(diccionario * dicc){
    int i;
    dicc->parejas = (pareja*)calloc(dicc->dimencion,sizeof(pareja));
    for (i = 0; i < dicc->dimencion;++i){
        dicc->parejas[i].llave = NULL;
        dicc->parejas[i].valor = NULL;}}

const char * diccionario_busca_valor(const diccionario * dicc, const char * palabra){
    int i, j,index;
    index = -1;
    for (i = 0; i < dicc->dimencion; ++i){
        for(j = 0; palabra[j] != NULL;++j){
            if(palabra[j] == dicc->parejas[i].llave[j]){
                if(palabra[j+1] == NULL){
                    index = i;
                    i = dicc->dimencion;
                    break;             }}}}
    if(index != -1)
        return dicc->parejas[index].valor;
    else
        return "__ERROR__";     }

const char * diccionario_busca_llave(const diccionario * dicc, const char * palabra){
    int i, j,index;
    index = -1;
    for (i = 0; i < dicc->dimencion; ++i){
        for(j = 0; palabra[j] != NULL;++j){
            if(palabra[j] == dicc->parejas[i].valor[j]){
                if(palabra[j+1] == NULL){
                    index = i;
                    i = dicc->dimencion;
                    break;             }}}}
    if(index != -1)
        return dicc->parejas[index].llave;
    else
        return "__ERROR__";     }

arreglos * busca_llaves(const diccionario * dicc, const char * palabra){
    arreglos * a;
    int i,j,Tam,*index;
    Tam = 0;
    index = (int*)calloc(dicc->dimencion, sizeof(int));
    for (i = 0; i < dicc->dimencion; ++i){
        for(j = 0; palabra[j] != NULL;++j){
            if(palabra[j] == dicc->parejas[i].valor[j]){
                if(palabra[j+1] == NULL){
                    index[Tam++] = i;
                    break;             }}}}
    if(Tam){
        a = (arreglos*)malloc(sizeof(arreglos));
        a->significado = (char*)calloc(Tam, sizeof(char));
        a->dimencion = Tam;
        for(i = 0; i < Tam; ++i)
            a->significado[i]=dicc->parejas[index[i]].llave;}
    free(index);
    return a;
    }

arreglos * busca_valores(const diccionario * dicc, const char * palabra){
    arreglos * a;
    int i,j,Tam,*index;
    Tam = 0;
    index = (int*)calloc(dicc->dimencion, sizeof(int));
    for (i = 0; i < dicc->dimencion; ++i){
        for(j = 0; palabra[j] != NULL;++j){
            if(palabra[j] == dicc->parejas[i].llave[j]){
                if(palabra[j+1] == NULL){
                    index[Tam++] = i;
                    break;             }}}}
    if(Tam){
        a = (arreglos*)malloc(sizeof(arreglos));
        a->significado = (char*)calloc(Tam, sizeof(char));
        a->dimencion = Tam;
        for(i = 0; i < Tam; ++i)
            a->significado[i]=dicc->parejas[index[i]].valor;}
    free(index);
    return a;
    }
void imprime_arreglos(const arreglos * a){
    if(a == NULL)return;
    for(int i = 0; i < a->dimencion;++i)
        printf("| %s |\n",a->significado[i]);
    printf("_______________________________\n");}

void liberar_arreglos(arreglos * a) {
    a->dimencion = 0;
    free(a->significado);
    free(a);                        }

/**************************************************************/

#include "diccionario.h"

int main(void)
{

    diccionario * D = diccionario_nuevo();
    diccionario_agrega(D,"Linux","derivado de unix");
    diccionario_agrega(D,"Linux","viva tux");
    diccionario_agrega(D,"FreeBSD","derivado de unix");
    diccionario_agrega(D,"MacOS","derivado de FreeBSD");
    diccionario_agrega(D,"windows","derivado de MSDos");
    arreglos * llaves,* valores;
    llaves = busca_llaves(D,"derivado de unix");
    imprime_arreglos(llaves);
    valores = busca_valores(D,"Linux");
    imprime_arreglos(valores);

    liberar_arreglos(llaves);
    diccionario_liberar(D);

     return 0;
}
