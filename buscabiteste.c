#include <stdio.h>
#include <string.h>
#include <stdlib.h>




int main(){

	int low,high,mid;
	FILE* biblioteca;
	biblioteca = fopen ("brazilian","r");
	if ( ! biblioteca){
      	perror ("Erro ao abrir/criar arquivo x") ;
      	exit (1) ; // encerra o programa com status 1
   	}
   	int tamanho = 0;
    char a[200000][50],key[32];

 	while (! feof(biblioteca) && tamanho <= 200000){
 		fscanf(biblioteca,"%s",&a[tamanho]);
 		//printf("tamanho atual %i",tamanho);
 		tamanho++;
 	}  
 	printf("saiu do while");
 	tamanho = tamanho - 6 ;
 	printf("tamanho da biblioteca %i ",tamanho);
 	printf("\n\n");
 	printf("enter the name to be searched\n");
 	scanf("%s",&key);





 low=0;
 high=tamanho -1;
 while(low<=high)
 {
 mid=(low+high)/2;
 if (strcmp(key,a[mid])==0)
 {
 printf("key found at the position %d\n",mid+1);
        exit(0);
 }
 else if(strcmp(key,a[mid])>0)
 {
 high=high;
 low=mid+1;
 }
 else
 {
 low=low;
 high=mid-1;
 }
 }
 printf("name not found\n");
 fclose(biblioteca);
 return 0;
 }

