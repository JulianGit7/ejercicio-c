#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Desarrolle un programa en C que permita generar dos vectores de
tamaño n y m (valores ingresados por teclado). Los vectores deben
tener valores reales generados aleatoriamente entre 10.0 y 50.0.
Luego el programa debe mostrar la siguiente información por pantalla:
1. Los valores de ambos vectores
2. Indicar si el primer vector es palíndromo
3. Indicar si el primer vector es igual al segundo (mismos valores en las
mismas ubicaciones)*/
int main()
{
    srand(time(NULL));
    int i,j,n,m,flag=1,flag2=1;
    do{
        printf("Ingrese el tamanio del vector 1: ");
        scanf("%d",&n);
        printf("\nIngrese el tamanio del segundo vector: ");
        scanf("%d",&m);
    }while(n<1 || m<1);
    float array1[n],array2[m];
    for(i=0;i<n;i++)
      array1[i] = (100 + rand()%410)/10.0;
    for(i=0;i<m;i++)
    array2[i] = (100 + rand()%410)/10.0;
    printf("Primer vector\n");
    for(i=0;i<n;i++){
        printf("[%.1f]",array1[i]);
    }
    for(i=0;i<m;i++){
        printf("[%.1f]",array2[i]);
    }
    for(i=0,j=n-1;i<j;i++,j--){
        if(array1[i]!=array1[j]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("\nEl vector 1 es palindromo");
    }else{
        printf("\nNo es palindromo");
    }
    if(n!=m){
        flag2=0;
    }else{
        for(i=0;i<n;i++){
            if(array1[i]!=array2[i]){
              flag2=0;
              break;
            }
        }
    }
    if(flag2==1){
        printf("\nEl vector 1 y 2 son iguales");
    }else{
        printf("El vector 1 y 2 no son iguales");
    }
}