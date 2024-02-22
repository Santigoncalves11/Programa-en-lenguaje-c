// Declaraciones de funciones
void llenarMatriz(int matriz[][3], int filas, int columnas);
void sumarMatrices(int matrizA[][3], int matrizB[][3], int matrizC[][3], int filas, int columnas);
void imprimirMatriz(int matriz[][3], int filas, int columnas);

// Programa principal
int main() {
  // Declaraciones de variables
  int matrizA[3][3], matrizB[3][3], matrizC[3][3];
  int filas, columnas;

  // Entrada de datos
  printf("Ingrese el n�mero de filas de las matrices: ");
  scanf("%d", &filas);
  printf("Ingrese el n�mero de columnas de las matrices: ");
  scanf("%d", &columnas);

  // Validaci�n de datos
  if (filas < 1 || columnas < 1) {
    printf("El n�mero de filas y columnas debe ser mayor que 0\n");
    return 1;
  }

  // Llenado de las matrices
  llenarMatriz(matrizA, filas, columnas);
  llenarMatriz(matrizB, filas, columnas);

  // Suma de las matrices
  sumarMatrices(matrizA, matrizB, matrizC, filas, columnas);

  // Impresi�n de la matriz resultante
  printf("La matriz resultante es:\n");
  imprimirMatriz(matrizC, filas, columnas);

  return 0;
}

// Funci�n para llenar una matriz con valores ingresados por el usuario
void llenarMatriz(int matriz[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++) {
      printf("Ingrese el elemento A[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

// Funci�n para sumar dos matrices
void sumarMatrices(int matrizA[][3], int matrizB[][3], int matrizC[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }
}

// Funci�n para imprimir una matriz
void imprimirMatriz(int matriz[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}
