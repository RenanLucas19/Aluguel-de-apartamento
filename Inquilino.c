#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inquilino.h"

struct Inquilino {
	
    char nome [60];
    int dia,d;
    int mes,m;
    int ano,a;
    int duracao_cont;
    int documento;
    int apartamento;

};

struct lista{
	inquilino * info;
	Lista * prox;
};

Lista* lst_cria(void){
	return NULL;
}

Lista* lst_insere(Lista* list){
	inquilino * Dado = InsereDados();
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo -> info = Dado;
	novo -> prox = list;
	
return novo;
}

inquilino * InsereDados(void){
	
	inquilino* Dado = (inquilino*)malloc(sizeof(inquilino));
	
	if(Dado == NULL){
		printf("ERRO AO ALOCAR MEMORIA!");
		exit(1);
	}
	    printf("\n");
        printf("\n> Informe o nome do Inquilino : ");
        scanf("%[^\n]", &Dado->nome);
        
         printf("\n> Formato : 00 00 0000\n\n> Informe a data de entrada : ");
        scanf("%d%d%d",&Dado->dia,&Dado->mes,&Dado->ano );
    
        printf("\n> Formato : 00 00 0000\n\n> Informe a duracao de contrato : ");
        scanf("%d%d%d",&Dado->d,&Dado->m,&Dado->a );
        
        printf("\n> formato : 00000000000 \n\n> Informe o CPF: ");
        scanf(" %d", &Dado->documento);
        
        printf("\n> Numero do Apartamento : ");
        scanf(" %d", &Dado->apartamento);
        printf("\n");

	FILE *arquivo;

    arquivo = fopen("ListaInquilino.txt" , "a");
     if(arquivo == NULL){
     	printf("Erro ao abrir o arquivo!");
        exit(1);
	 }	
	 
        fprintf(arquivo, "\n\nNome:%s\nData de entrada:%d/%d/%d\n data de saida:%d/%d/%d\nDocumento:%d\nApartamento:%d\n " , Dado->nome,  &Dado->dia,&Dado->mes,&Dado->ano, &Dado->d,&Dado->m,&Dado->a,Dado->documento,Dado->apartamento);
        printf(" Dados adicionados ao arquivo!");
 	 	printf("\n");
  		fclose(arquivo);

return Dado;
}

int lst_vazia(Lista *l){
	return (l==NULL);
}

Lista* ExcluirInquilino(Lista* l , char * nome){

	Lista * ant = NULL;
	Lista * inq = l;

	while(strcmp(nome, inq->info->nome) != 0){

		if(inq == NULL){
		return l;
		}
		ant = inq;
		inq = inq->prox;
			
	}
		if (ant == NULL){

			l = inq-> prox;
		}else{
			ant -> prox = inq -> prox;

		}

free(inq);

return l;
}

void ListarInquilino ( Lista * l){
	Lista *inq;
	for (inq=l; inq!=NULL; inq=inq->prox){
		printf("\nNome:%s\nData de entrada:%d/%d/%d\n Data de saida:%d/%d/%d\nDocumento:%d\nApartamento:%d\n " , inq->info->nome, inq->info->dia, inq->info->mes, inq->info->ano, inq->info->d,inq->info->m ,inq->info->a ,inq->info->documento ,inq->info->apartamento);
		}
}

Lista *lst_buscar(Lista *l){

	char nome[50];
	
	printf("Informe o nome do inquilino que deseja buscar: \n");
	scanf(" %[^\n]", &nome);
	 
	 Lista* p;
	 for (p=l; p!=NULL; p=p->prox){
		 if(strcmp(p-> info->nome, nome)==0){
			printf("\n");
		 	printf(" \nInquilino %s foi encontrado ! \n", nome);
		 	printf("\n\n");
			 return p;
		 }
	 }
	 
	 printf("\n");
	 printf("Inquilino nao encontrado !");
	 printf("\n");

	 return NULL;
}

void EditarInq(Lista*l){
	
	int num;
	
	printf("Digite o numero anterior do apartamento para editar : \n");
	scanf("%d",&num);
	
	Lista*p;
	
	for(p=l; p!=NULL; p=p->prox){
		if(p->info->apartamento == num){
		
		printf("\n");
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                        INQUILINO ENCONTRADO                             |");
    	printf("\n    #-------------------------------------------------------------------------#");
	    printf("\n");
		
			printf(" Informe o novo nome do inquilino : ");
			scanf(" %[^\n]",p->info->nome);
			printf(" Informe a nova data do contrato : \n");
			scanf("%d%d%d", &p->info->dia,&p->info->mes,&p->info->ano);
			printf("Informe a nova duracao do contrato : \n");
			scanf("%d%d%d", &p->info->d,&p->info->m,&p->info->a);
			printf("Informe o novo documento -> CPF :\n");
			scanf("%d", &p->info->documento);
			printf("Informe o numero novo do apartamento : \n");
			scanf("%d", &p->info->apartamento);
			printf("\n");
		}
		
	}
}

void quant(Lista* l){
	
	Lista* p;
	
	int i=0;
	
	for(p=l; p!=NULL; p=p->prox){
		i++;
		
	}
	printf("\n");
	printf("A quantidade de inquilino e : %d\n ", i);
	printf("\n");
}
