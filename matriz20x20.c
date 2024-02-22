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
  printf("Ingrese el número de filas de las matrices: ");
  scanf("%d", &filas);
  printf("Ingrese el número de columnas de las matrices: ");
  scanf("%d", &columnas);

  // Validación de datos
  if (filas < 1 || columnas < 1) {
    printf("El número de filas y columnas debe ser mayor que 0\n");
    return 1;
  }

  // Llenado de las matrices
  llenarMatriz(matrizA, filas, columnas);
  llenarMatriz(matrizB, filas, columnas);

  // Suma de las matrices
  sumarMatrices(matrizA, matrizB, matrizC, filas, columnas);

  // Impresión de la matriz resultante
  printf("La matriz resultante es:\n");
  imprimirMatriz(matrizC, filas, columnas);

  return 0;
}

// Función para llenar una matriz con valores ingresados por el usuario
void llenarMatriz(int matriz[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++) {
      printf("Ingrese el elemento A[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

// Función para sumar dos matrices
void sumarMatrices(int matrizA[][3], int matrizB[][3], int matrizC[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
    }
  }
}

// Función para imprimir una matriz
void imprimirMatriz(int matriz[][3], int filas, int columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }
}
