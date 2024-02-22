//Un supermercado ha puesto en oferta la venta al por mayor de cierto producto, ofreciendo un descuento del 15% por la compra de más de 3 docenas y 10% en caso contrario. Además 
//por la compra de más de 3 docenas se obsequia una unidad del producto por cada docena en exceso sobre 3. Desarrolle un programa en C gue determine el monto de la compra, el monto
//del descuento, el monto a pagar y el número de unidades de obsequio por la compra de cierta cantidad de docenas del producto.

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

int main() {
  // Definición de variables
  int docenas, unidades, precio_unidad, descuento, monto_compra, monto_pagar, unidades_obsequio;
  float porcentaje_descuento;

  // Ingreso de datos
  printf("Ingrese el numero de docenas: ");
  scanf("%d", &docenas);
  printf("Ingrese el numero de unidades sueltas (entre 0 y 11): ");
  scanf("%d", &unidades);
  printf("Ingrese el precio por unidad: ");
  scanf("%d", &precio_unidad);

  // Cálculo del monto de la compra
  monto_compra = (docenas * 12 + unidades) * precio_unidad;

  // Cálculo del porcentaje de descuento
  if (docenas > 3) {
    porcentaje_descuento = 0.15;
  } else {
    porcentaje_descuento = 0.1;
  }

  // Cálculo del descuento
  descuento = monto_compra * porcentaje_descuento;

  // Cálculo del monto a pagar
  monto_pagar = monto_compra - descuento;

  // Cálculo de las unidades de obsequio
  if (docenas > 3) {
    unidades_obsequio = docenas - 3;
  } else {
    unidades_obsequio = 0;
  }

  // Salida de resultados
  printf("\n**Monto de la compra: $%d", monto_compra);
  printf("\n**Descuento: $%d", descuento);
  printf("\n**Monto a pagar: $%d", monto_pagar);
  printf("\n**Unidades de obsequio: %d", unidades_obsequio);

  return 0;
}
