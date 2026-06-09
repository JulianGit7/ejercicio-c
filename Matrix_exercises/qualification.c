#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    int i,j,n;
    float promedio;
    do{
        printf("Ingrese la cantidad de estudiantes (15-100): ");
        scanf("%d",&n);
    }while(n<15 || n>100);
    float notas[n][5];
    for(i=0;i<n;i++){
        for(j=0;j<5;j++){
            notas[i][j] = (10 +rand()%61)/10.0;// llenamos la matriz de notas random
        }
    }
    char *NombresEvaluaciones[] = {"test 1","test 2","tarea 1","tarea 2","certamen"}; //escribimos los nombres para usarlos luego
    printf("\nReporte de notas");
    for(i=0;i<n;i++){ // con este ciclo recorremos todo (mostrar cada nota,promedio y nota maxima)
        printf("\nNotas alumno %d || test 1: %.2f || test 2: %.2f || tarea 1: %.2f || tarea 2: %.2f || certamen: %.2f",i+1,notas[i][0],notas[i][1],notas[i][2],notas[i][3],notas[i][4]);
        promedio = notas[i][0] * 0.15 + notas[i][1] * 0.15 + notas[i][2] * 0.15 + notas[i][3] * 0.15 + notas[i][4] * 0.40;
        printf("\nEl promedio final es: %.3f",promedio);
        float NotaMaxima = notas[i][0];
        int aux;
        aux = 0;
        for(j=0;j<5;j++){
            if(notas[i][j]>NotaMaxima){
                NotaMaxima = notas[i][j];
                aux = j;

            }
            
        }
        printf("\nLa nota maxima del alumno %d es: %.2f de (%s)",i+1,NotaMaxima,NombresEvaluaciones[aux]);

    }
}