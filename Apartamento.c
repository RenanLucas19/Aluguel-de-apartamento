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
	  
	    printf("\n\n  > Informe o numero/codigo : ");
        scanf("%d", &apa->codigo);
		
        printf("\n\n  > Disponibilidade : ");
        scanf(" %[^\n]", &apa->disponibilidade);
        
        
        printf("\n\n  > Informe o preco do aluguel: R$ ");
        scanf("%f", &apa->preco);
        
        printf("\n\n  > Informe a localizacao : ");
        scanf(" %[^\n]", &apa->localizacao);
        
        printf("\n\n  > Informe o nome do Inquilino : ");
        scanf(" %[^\n]", &apa->inquilino);
        
        
    
		FILE *arquivo;
 		arquivo = fopen("ListaInquilino.txt" , "a");
    	if (arquivo == NULL) {
        	printf("Erro ao abrir o arquivo!");
        	exit(1);
    }
    	fprintf(arquivo, " Disponibilidade:%s\ncodigo:%d\nlocalizacao:%s\nInquilino:%s\nPreco:%f\n " , apa->disponibilidade , apa->codigo, apa->localizacao, apa->inquilino, apa->preco);
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
		 	
		printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                 CODIGO %s DO APARTAMENTO FOI ENCONTRADO !               |",cod);
    	printf("\n    #-------------------------------------------------------------------------#");
		printf("\n\n");

			 return p;
		 }

	 }
	 
	 	printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                  NUMERO DO APARTAMENTO NAO ENCONTRADO!                  |");
    	printf("\n    #-------------------------------------------------------------------------#");
	 	Printf("\n\n");
	 return NULL;
}
void EditarAp(Lista2* l){
	
	int cod = 0;
	
	printf("\n Informe o numero do codigo anterior para alteracao : ");
	scanf("%d",&cod);
	
	Lista2* p;
	
	for(p=l; p!=NULL; p=p->prox){
		
		if(p->dado->codigo == cod ){

		printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                        APARTAMENTO ENCONTRADO                           |");
    	printf("\n    #-------------------------------------------------------------------------#");
	    printf("\n");
			
			printf("\nDigite o codigo : ");
			scanf("%d", &p->dado->codigo);
			printf("\nInforme a disponibilidade do apartamento : ");
			scanf(" %s",&p->dado->disponibilidade);
			printf("\nInforme o preco do aluguel : ");
			scanf("%f", &p->dado->preco);
			printf("\n Informe a localizacao : ");
			scanf(" %[^\n]",p->dado->localizacao);
			printf("\n Informe o nome do inquilino : ");
			scanf(" %[^\n]", p->dado->inquilino);
			printf("\n");
			
		}
	}		
}
void disponivel(Lista2 * l){
	
	Lista2 * p;
	
	int ap = 50;
	
	for (p=l; p!=NULL; p=p->prox){
		ap--;
	}
		printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |               QUANTIDADE DE APARTAMENTOS DISPONIVEIS  : %d              |",ap);
    	printf("\n    #-------------------------------------------------------------------------#");
	    printf("\n");
	
}
















