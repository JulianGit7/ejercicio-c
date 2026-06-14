#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Desarrolle un programa en C que permita generar dos vectores de números enteros 
de tamaño N y M respectivamente (valores de tamaño ingresados por teclado). 
Los vectores deben rellenarse con números aleatorios enteros en el rango de [10, 99].
Luego, el programa debe procesar la información y mostrar por pantalla:
Visualización: Los valores de ambos vectores de forma ordenada.
Intersección de datos: Indicar si el segundo vector contiene al menos tres números que también estén presentes en el primer vector (sin importar la posición).
Análisis de simetría inversa: Indicar si el primer vector es el "espejo invertido" 
del segundo vector (es decir, si tienen el mismo tamaño y los elementos leídos de izquierda a derecha en 
el primero son idénticos a los del segundo leídos de derecha a izquierda).*/
int main()
{
    srand(time(NULL));
    int n,i,m,contador=0,j,flag=1;
    do{
        printf("Ingrese el tamanio del primer vector: ");
        scanf("%d",&n);
        printf("\nIngrese el tamanio del segundo vector: ");
        scanf("%d",&m);
    }while(n<1 || m<1);
    int v1[n],v2[m];
    for(i=0;i<n;i++)
        v1[i] = 10+rand()%90;
    for(i=0;i<m;i++)
      v2[i] = 10+rand()%90;
    printf("Primer vector\n");
    for(i=0;i<n;i++)
      printf("[%d]",v1[i]);
      printf("\nSegundo vector\n");
      for(i=0;i<m;i++)
      printf("[%d]",v2[i]);
     for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(v1[i]==v2[j]){
                contador++;
            }
        }
     }
    if(contador>=3){
        printf("\nEn el segundo vector hay mas de 3 numeros iguales que en el primero\n");
    }else{
        printf("\nEn el segundo vector no hay mas de 3 numeros iguales que en el primero\n");
    }
    if(n==m){
        for(i=0,j=m-1;i<j;i++,j--){
            if(v1[i]!=v2[j]){
                flag=0;
                }

        }
        
    }else{
        flag=0;
    }
   if(flag==0){
    printf("El v1 no es el invertido del v2");
   }else{
    printf("El v1 es el espejo invertido del v2");
   }
    

}