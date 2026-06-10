#include <stdio.h>
/*Desarrolle un algoritmo que permita generar los siguientes patrones para cualquier matriz 
cuadrada de tamaño N (impar). Letra P,T y la letra Y*/
int main(){
    int i,j,n;// n sera el tamanio de la matriz y tiene que ser impar para formar las letras pedidas
    do{
        printf("Ingrese el tamanio de la matriz (impar): ");
        scanf("%d",&n);
    }while(n<1);
    int matrix[n][n],Mid=matrix[n/2][n-1];
    for(i=0;i<n;i++){//llenamos la matriz para formar la P
        for(j=0;j<n;j++){
        if(j==0 || i==0 || i==n/2 || (j==n-1 && i<=n/2)){//Con la ultima condiciones hacemos que la columna (j) llene la ultima columna Y solo las posiciones menores a la mitad
            matrix[i][j] = 1;
        }else{
            matrix[i][j] = 0;
        }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%d]",matrix[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){//Llenamos la matriz para formar la T
        for(j=0;j<n;j++){
          if(i==0 || j==n/2){// i==0 llena toda la fila 0 o sea toda la primera posicion en horizontal
            matrix[i][j] = 1;// j==n/2 llena toda la columna vertical de la columna posicion n/2 o sea la mitad
          }else{
            matrix[i][j] = 0;
          }
        }
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%d]",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n;i++){//LLenamos la matriz para formar la Y
        for(j=0;j<n;j++){
            if(((i == j || i + j == n - 1) && i <= n / 2) || (j == n / 2 && i > n / 2) ){
                matrix[i][j] = 1;
            }else{
                matrix[i][j] = 0;
            }
            
            
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("[%d]",matrix[i][j]);
        }
        printf("\n");
    }
}