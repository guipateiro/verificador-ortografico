#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>


int ehletra(char c){
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (192 <= c && c <= 255))
		return 1;
	return 0; 
}

void minusculo (char *palavra, char *palavranova){
	int controle;
	controle = 0;  
	while (palavra[controle] != '\0'){
		if ((90 >= palavra[controle] && palavra[controle] >= 65))
			palavranova[controle] = palavra[controle] + 32;
		else 
			palavranova[controle] = palavra[controle];
		controle++;
	}
	return;	
}

void limpapalavra(char *palavra){
	for (int i = 0 ; i <= 32 ; i++){
		palavra[i] = '\0';
	}
	return; 
}	

 int carregadicionario(FILE* arquivo, char *dicionario,int *tam){
	int i;
	i = 0; 
	char palavra[32];
	while(!feof(arquivo)){
		fscanf(arquivo, "%s",palavra);
		dicionario[i] = palavra; 
		i++;
	}
	*tam = i-1;
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

//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------
//------------------------------------A MAIN COMECA AQUI ----------------------------------
//-----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------

int main(){
	//DEFINICAO DO LOCALE PARA RECONHECER CARACTERES ESPECIAIS
	char *locale;
	locale = setlocale(LC_ALL,"pt_BR.ISO-8859-1");
	printf("a palavra digita eh %s \n\n", locale);
	int tam,j;
	// CARREGAMENTO DO ARQUIVO DO DICIONARIO (MODIFICAR PALA LOCAL PADRAO)
	FILE* biblioteca;
	biblioteca = fopen ("brazilian","r");
	if ( ! biblioteca){
    	perror ("erro ao abrir biblioteca");
    	exit (1);
   	}
   	//EDCLARACAO DA ALOCACAO DINAMICA DO DICIONARIO( FAZER MAIS DINAMICA DPS)
	char **dicionario;
	dicionario = (char**) malloc (300000 * sizeof (char*));
	for (j = 0; j < 5 ; j++)
    	dicionario[j] = (char*) malloc (32 * sizeof (char)) ;

    //FUNCAO QUE CARREGA NO DICIONARIO (FAZER FUNCAO DPS)
    int k = 0;
    while (! feof(biblioteca)){
    	fscanf(biblioteca,"%s",&dicionario[k]);
    	k++;
    }
    tam = --k;
	
	printf("\n tamanho total: %i \n\n",tam);

    //carregadicionario(biblioteca,&dicionario,&tam);

    printf("pode comecar a digitar \n\n");
	//LEITURA DO ARQUIVO QUE SERA CORRIGIDO
	char c;
	int i; 
	char palavra[32]; 
	char palavraaux[32];
	scanf("%c", &c);
	while (! feof(stdin)){
		//SE NAO FOR LETRA SO IMPRIMIR
		while (!ehletra(c)  && !feof(stdin)){
			printf("%c",c);
			scanf("%c", &c);
		}
		//RESETA A VARIAVEL PALAVRA PARA IMPEDIR LIXO DE MEMORIA 
		limpapalavra(palavra);
		i = 0; 
		palavra[i] = c;
		scanf("%c", &c);
		//ENQUANTO HOUVEREM LETRAS ELE IRA LER PARA GRAVAR UMA NOVA PALAVRA
		while (ehletra(c) && !feof(stdin)){
			i++;
			palavra[i] = c;
			scanf("%c", &c);
		}
		/*RESETA A VARIAVEL PALAVRAAUX PALA A FUNCAO MINUSCULA, UMA VEZ Q NO DICINONARIO A MAIOR PARTE DAS PALAVRAS ESTA EM MINUSCULA
		A FUNCAO MINUSCULA SE ENCARREGA DE FAZER A CONVERSAO DE LETRA MAIUSCULAS PARA MINUSCULAS*/
		limpapalavra(palavraaux);
		minusculo( palavra,palavraaux);
		//A BUSCA BINARIA EM SI NO DICIONARIO E A INPRESSAO DE PALAVRAS NA SAIDA 
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