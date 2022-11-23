#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Apartamento.h"


struct apartamento{
	int codigo;
	char disponibilidade[50];
	float preco;
	char localizacao[10];
	char inquilino[60];
};

struct lista2{
	Apartamento *dado;
	struct lista2 *prox;
};

Lista2* list_cria(void){
	return NULL;
}
	
Apartamento * AdicionaAp(void){
	
	Apartamento* apa = (Apartamento*)malloc(sizeof(Apartamento));
	
	if(apa == NULL){
		printf("ERRO AO ALOCAR MEMORIA!");
		exit(1);
	}
	
		
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                        CADASTRO DO APARTAMENTO                          |");
    	printf("\n    #-------------------------------------------------------------------------#");
	  	printf("\n");
	  	
	    printf("\n> Informe o numero/codigo : ");
        scanf("%d", &apa->codigo);
		
        printf("\n\> Disponibilidade : ");
        scanf(" %[^\n]", &apa->disponibilidade);
        
        
        printf("\n\> Informe o preco do aluguel: R$ ");
        scanf("%f", &apa->preco);
        
        printf("\n> Informe a localizacao : ");
        scanf(" %[^\n]", &apa->localizacao);
        
        printf("\n> Informe o nome do Inquilino : ");
        scanf(" %[^\n]", &apa->inquilino);
        
        
    
		FILE *arquivo;
 		arquivo = fopen("ListaInquilino.txt" , "a");
    	if (arquivo == NULL) {
        	printf("Erro ao abrir o arquivo!");
        	exit(1);
    }
    	fprintf(arquivo, "Disponibilidade:%s\ncodigo:%d\nlocalizacao:%s\nInquilino:%s\nPreco:%f\n " , apa->disponibilidade , apa->codigo, apa->localizacao, apa->inquilino, apa->preco);
        printf("\n");
        printf("Os dados foram adicionado ao arquivo!\n");
        printf("\n\n");

 	 fclose(arquivo);

 	return apa;
}

Lista2* InsereAp (Lista2* l){
	
	Apartamento * Ap = AdicionaAp();
	 Lista2 *novo = (Lista2*)malloc(sizeof(Lista2));
	 novo -> dado = Ap;
	 novo -> prox = l;
	
	return novo;
}

int list_vazia(Lista2 *l){
	return (l==NULL);
}

void ListarAp(Lista2* l){
	Lista2*apa;
	for(apa=l; apa!=NULL; apa=apa->prox){
		printf("\nDisponibilidade:%s\ncodigo:%d\nlocalizacao:%s\nInquilino:%s\nPreco:%f\n " , apa->dado->disponibilidade , apa->dado->codigo, apa->dado->localizacao, apa->dado->inquilino, apa->dado->preco);
	}
}

Lista2 * ExcluirAp( Lista2* l, int codigo){

	Lista2 * antes = NULL;
	Lista2 * apa = l;

	while( apa->dado->codigo != codigo){
		if(apa == NULL)
			return l;
	
		antes = apa;
		apa = apa->prox;
	}
	if(antes == NULL){
		l = apa->prox;
	}else{
		antes->prox = apa->prox;
	}
free(apa);
return l;

}

	Lista2 *l_buscar(Lista2 *l){
	int cod;
	printf("informe o codigo do apartamento que deseja buscar: \n");
	scanf("%d", &cod);
	 
	 Lista2* p;
	 for (p=l; p!=NULL; p=p->prox){
		 if(p-> dado->codigo == cod){
		 	printf("Codigo do apartamento %d encontrado!\n",cod);
		 	printf("\n\n");
			 return p;
		 }

	 }
	 printf("codigo do apartamento nao encontrado!\n");
	 printf("\n\n");
	 return NULL;
}
void EditarAp(Lista2* l){
	
	int cod = 0;
	
	printf("\n Informe o numero do codigo anterior para alteracao : \n");
	scanf("%d",&cod);
	
	Lista2* p;
	
	for(p=l; p!=NULL; p=p->prox){
		
		if(p->dado->codigo == cod ){
		
		printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                        APARTAMENTO ENCONTRADO                           |");
    	printf("\n    #-------------------------------------------------------------------------#");
	    printf("\n");
		
			printf("Digite o novocodigo : ");
			scanf("%d", &p->dado->codigo);
			printf("Informe a disponibilidade do apartamento :\n");
			scanf(" %s",&p->dado->disponibilidade);
			printf("Informe o novo preco do aluguel :\n");
			scanf("%f", &p->dado->preco);
			printf("Informe a nova localizacao :\n");
			scanf(" %[^\n]",p->dado->localizacao);
			printf("Informe o novo nome do inquilino :\n");
			scanf(" %[^\n]", p->dado->inquilino);
			
		}
	}		
}
void disponivel(Lista2 * l){
	
	Lista2 * p;
	
	int ap = 50;
	
	for (p=l; p!=NULL; p=p->prox){
		ap--;
	}
printf("Quantidade de apartamentos disponiveis e : %d\n" ,ap);
	
}