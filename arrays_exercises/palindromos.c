#include <stdio.h>
//crear un vector de espacio N y verificar si es palindromo o no
int main()
{
    int i,j,palindromo=1,n;
    do{
        printf("Ingrese el tamanio del vector: ");
        scanf("%d",&n);
    }while(n<1);
    int array[n];
    printf("Ingrese los valores para el vecto\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
        
    }
    for(i=0;i<n;i++){
       printf("[%d]",array[i]);
    }
    
    for(i=0,j=n-1;i<j;i++,j--){
        if(array[i]!=array[j]){
            palindromo = 0;
            break;
        }
    }
    if(palindromo==1){
        printf("\nEs palindromo");
    }else{
        printf("\nNo es palindomo");
    }
}