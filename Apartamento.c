#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Apartamento.h"
#define MAXTAM 4

struct apartamento {
	int codigo;
	char disponibilidade[MAXTAM];
	float preco;
	char localizacao[10];
	char inquilino[60];
};

struct lista2{
	Apartamento *Dado;
	struct Lista2 *prox;
};



Lista2 * list_cria(void){
	return NULL;
}

Lista2 * InsereAp (Lista2* l){
	
	Apartamento * Ap = AdicionaAp();
	 Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	 novo -> Dado = Ap;
	 novo -> prox = l;
	
	return novo;
}
	
Apartamento * AdicionaAp(void){
	
	Apartamento* apa = (Apartamento*)malloc(sizeof(Apartamento));
	
	if(apa == NULL){
		printf("ERRO AO ALOCAR MEMORIA!");
		exit(1);
	}else
	{
	
    FILE *arquivo;
    
    arquivo = fopen("ListaInquilino.txt" , "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }
    else{

	system("cls");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                        CADASTRO DO APARTAMENTO                          |");
    	printf("\n    #-------------------------------------------------------------------------#");
	
		printf("\n\n  > Disponibilidade : ");
        scanf("%s", &apa->disponibilidade);
        
        
        printf("\n\n  > Informe o numero/codigo : ");
        scanf("%d", &apa->codigo);
        
        printf("\n\n  > Informe a localizacao : ");
        scanf("%s", &apa->localizacao);
        
        printf("\n\n  > Informe o preco do aluguel: R$  ");
        scanf("%f", &apa->preco);
        
        printf("\n\n  > Informe o Inquilino : ");
        scanf("%[^/n]", &apa->inquilino);
        
    	fprintf(arquivo, " Disponibilidade:%s\n Codigo:%d\nLocalizacao:%s\nPreco:%f\nInquilino:%s\n " , apa->disponibilidade , apa->codigo, apa->localizacao, apa->preco , apa->inquilino);
		printf("Os Dados foram adicionado ao arquivo!\n");
 		}
	
 fclose(arquivo);
 	}
 	return apa;
}

int list_vazia(Lista2 *list){
	return (list==NULL);
}