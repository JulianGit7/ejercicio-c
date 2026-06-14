#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Cree un programa en C que permita gestionar el stock y las ventas de una tienda de 
tecnología que maneja un catálogo de entre 10 y 30 productos diferentes,
registrando sus ventas mensuales durante el último semestre (6 meses).
Use una matriz para almacenar la cantidad de unidades vendidas de cada producto en cada mes 
(valores enteros generados aleatoriamente entre 0 y 50 unidades).
Condiciones del negocio:
Un producto se considera "Éxito de ventas" si su promedio mensual de ventas es mayor o igual a 25 unidades.
Un producto se considera "Crítico" si en cualquiera de los 6 meses registró 0 ventas.
al finalizar la carga de datos, el programa debe mostrar por pantalla:
Reporte General: La matriz completa que muestre las ventas de cada producto mes a mes,
 junto con el total acumulado de unidades vendidas para cada producto al final de la fila.
Consulta Dinámica: Permitir al usuario ingresar el número de un mes en específico (1 al 6). 
El programa debe calcular y desplegar en pantalla cuál fue el promedio general de ventas de toda la tienda en ese mes seleccionado.
Indicadores de Desempeño: Indicar cuántos productos del catálogo cumplen con la condición de ser 
"Éxito de ventas" y cuántos están en estado "Crítico" simultáneamente.*/
int main()
{
    srand(time(NULL));
    int i,j,total=0,contadorSimultaneo=0,n;
    do{
        printf("Ingrese la cantidad de productos: ");
        scanf("%d",&n);
    }while(n<10 || n>30);
    int mat[n][6];
    for(i=0;i<n;i++){
        for(j=0;j<6;j++){
            mat[i][j] = rand()%51;
        }
    }
    float promediomensual=0;
    printf("\n            [Mes1][Mes2][Mes3][Mes4][Mes5][Mes6]\n");
    for(i=0;i<n;i++){
        int critico=0;
        float suma=0,promedio=0;
        printf("Producto %d:  ",i+1);
        for(j=0;j<6;j++){
           printf("[%d]",mat[i][j]);
           suma = suma + mat[i][j];
           if(mat[i][j]==0){
            critico=1;
           }
           }

        promedio = suma/6;
        if(promedio>=25 && critico==1){
            contadorSimultaneo++;
        }
        printf("T.V [%.1f]",suma);
        printf("\n");
     }
     
     
     
     int op=0;
     float suma2=0;
     do{
        printf("\nDe que mes quiere saber el promedio de ventas: ");
        scanf("%d",&op);
     }while(op<1 || op>6);
     for(i=0;i<n;i++){
        suma2 = suma2 + mat[i][op-1];
     }
     promediomensual = suma2/n;
     
     printf("\nEl promedio de ventas del mes %d es: %.1f",op,promediomensual);
     printf("Hay %d productos criticos y exitosos al mismo tiempo",contadorSimultaneo);
}