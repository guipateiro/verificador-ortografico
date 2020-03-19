#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	char *locale;
	locale = setlocale(LC_ALL,"pt_BR.ISO-8859-1");
	printf("a palavra digita eh %s \n\n", locale);
	int tam,j;
	FILE* biblioteca;
	biblioteca = fopen ("biblioteste","r");
	if ( ! biblioteca){
    	perror ("erro ao abrir biblioteca");
    	exit (1);
   	}

	char **dicionario;
	dicionario = (char**) malloc (10 * sizeof (char*));
	for (j = 0; j < 5 ; j++)
    	dicionario[j] = (char*) malloc (32 * sizeof (char)) ;
    //int i = 0;
    //while (! feof(biblioteca)){
    	//fscanf(biblioteca,"%s",&dicionario[i]);
    	//printf("tamanho atual %i",i);
    	//i++;
   // }




    //leitura do arquivo a ser corrigido// 
	char c;
	int i; 
	char palavra[32]; 
	char palavraaux[32];
	scanf("%c", &c);
	while (! feof(stdin)){
		while (!ehletra(c)  && !feof(stdin)){
			printf("%c",c);
			scanf("%c", &c);
		}
		limpapalavra(palavra);
		i = 0; 
		palavra[i] = c;
		scanf("%c", &c);
		while (ehletra(c) && !feof(stdin)){
			i++;
			palavra[i] = c;
			scanf("%c", &c);
		}
		limpapalavra(palavraaux);
		minusculo( palavra,palavraaux);
		if (buscabinaria(dicionario ,palavraaux,tam))
			printf("%s",palavra);
		else 
			printf("[%s]",palavra);
	}	



	fclose(biblioteca);
	for (i=0; i < 5; i++)
   		free (dicionario[i]) ;
	free (dicionario) ;
	return 0; 
}


int buscabinaria(char **dicionario ,char *palavrachave, int tam){
	int low,high,mid;
	

	low=0;
	high=tam-1;
	while(low<=high){
		mid=(low+high)/2;
		if (strcmp(palavrachave,&dicionario[mid])==0){
			return 1; 
		}
		else if(strcmp(palavrachave,&dicionario[mid])>0){
			high=high;
			low=mid+1;
		}
		else{
			low=low;
			high=mid-1;
		}
	}
	return 0;
}