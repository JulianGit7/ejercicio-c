#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
/*Cree un programa en C que permita almacenar las temperaturas máximas 
registradas en cada día de una N cantidad de semanas para luego mostrar la 
siguiente información*/
/*Todas las temperaturas
Indicar la semana donde se encontró la temperatura más alta
Indicar en que semana se encuentra el domingo más caluroso
Indicar en que semana se encuentra el lunes menos caluroso.
Mostrar el promedio de temperaturas de los días viernes
Indicar cual fue la semana más calurosa*/
int main()
{
    srand(time(NULL));
    int i,j,n,aux=0,aux1=0,aux3=0,aux2=0;
    char *Weeks_Days[] = {"lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
    do{
        printf("Ingrese la cantidad de semanas: ");
        scanf("%d",&n);
    }while(n<1);
    float Mat[n][7],Friday=0;
    for(i=0;i<n;i++){
        for(j=0;j<7;j++){
            Mat[i][j] = (-500 + rand()%1000)/10.0;
        }
    }
     printf("    Lunes Martes Miercoles Jueves viernes Sabado Domingo");
    float Max_temp=-999,Sunday=-999,Monday=999,FridayPromedio=0;
    printf("\n");
    float Hot_Week=-999;
    for(i=0;i<n;i++){
     printf("Semana %d ",i+1);
        for(j=0;j<7;j++){
            printf("[%.1f]",Mat[i][j]);
            ;
            if(Max_temp<Mat[i][j]){
                Max_temp = Mat[i][j];
                aux = i+1;
            }
            if(j==6 && Sunday<Mat[i][6]){
                Sunday = Mat[i][j];
               aux1=i;
            }
            if(j==0 && Monday>Mat[i][0]){
                Monday = Mat[i][j];
                aux3=i;
            }
            if(j==4){
                Friday = Friday + Mat[i][j];
            }
        }
        
        printf("\n");
    }
    for(i=0;i<n;i++){
        
       float Comp=0;
        
        for(j=0;j<7;j++){
            Comp = Comp + Mat[i][j];
        }
        if(Comp>Hot_Week){
          Hot_Week = Comp;
          aux2 = i;
        }
        
    }
    FridayPromedio = Friday/n;
  printf("\nLa temperatura mas alta fue %.1f en la semana %d",Max_temp,aux);
  printf("\nEl domingo mas caluroso fue de %.1f en la semana %d",Sunday,aux1+1);
  printf("\nLa temperatura mas baja del lunes fue %.1f en la semana %d",Monday,aux3+1);
  printf("\nEl promedio de temperaturas del dia viernes es de: %.1f",FridayPromedio);
  printf("\nLa semana mas calurosa es la semana %d y su suma de temperaturas es %.1f",aux2+1,Hot_Week);
}