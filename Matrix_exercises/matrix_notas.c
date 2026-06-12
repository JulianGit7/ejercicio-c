#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*Cree un programa en C que permita almacenar las notas de evaluaciones de un curso de 
postgrados que tiene entre 15 y 50 estudiantes. Las evaluaciones y sus ponderaciones son 
las siguientes
• Avance informe 1: 10%
• Avance informe 2: 15%
• Exposición investigación: 15%
• Entrega final informe: 20%
• Certamen 1: 20%
• Certamen 2: 20%
Importante:
• Nota mínima de aprobación en postgrado es de 5.0
• En el curso se puede reprobar por promedio menor a 
5.0 y por nota en “entrega final informe” menor a 5.0
Al finalizar el programa debe mostrar en pantalla la información de:
Todas las evaluaciones más los promedios de cada estudiante
Permitir ver el promedio general de una evaluación que indique el usuario (ej: si se ingresa un 1 se 
muestra el promedio entre todos los “avances informe 1”. Si se ingresa un 6 se puede ver el 
promedio entre todos los “certamen2”)
Indicar cuantos alumnos aprobaron la asignatura*/
int main()
{
    srand(time(NULL));
    int i,j,n,aprobados=0,op;
    do{
        printf("Ingrese la cantidad de alumnos: ");
        scanf("%d",&n);
    }while(n<15 || n>50);
    float notas[n][6];
    char *evaluaciones[] = {"Informe 1","informe 2","Exposicion","Informe final","Certamen 1","Certamen 2"};
    printf("\n          [AV1][AV2][EXP][ENTF][CER1][CER2]\n");
    for(i=0;i<n;i++){
        float promedio=0;
        printf("Alumno %d ",i+1);
        for(j=0;j<6;j++){
            notas[i][j] = (10 + rand()%61)/10.0;
            printf("[%.1f]",notas[i][j]);
        }
 promedio = (notas[i][0]*0.10 + notas[i][1]*0.15 + notas[i][2]*0.15 + notas[i][3]*0.20 + notas[i][4]*0.20 + notas[i][5]*0.20);
  printf("PF [%.1f]",promedio);
  if(promedio>= 5 && notas[i][3]>=5){
    aprobados++;
  }
  printf("\n");
  
    }
    do{
        printf("\nIngrese que nota quiere ver su promedio: ");
        scanf("%d",&op);
    }while(op<1 || op>6);
    float suma=0;
    for(i=0;i<n;i++){
        suma = suma + notas[i][op-1];
     }
    float promedio2=0;
    promedio2 = suma/n;
    printf("\nHay %d aprobados",aprobados);
    printf("\nEl promedio de (%s) es: %.1f",evaluaciones[op-1],promedio2);
}