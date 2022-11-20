#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inquilino.h"

struct nasc{
	int dia;
	int mes;
	int ano;
};

struct Inquilino {
	
    char nome [60];
    char documento[12];
    int apartamento;
    NASC data;
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
	}else
	{
	
	
	 FILE *arquivo;

    arquivo = fopen("ListaInquilino.txt" , "a");
     if(arquivo == NULL){
     	printf("Erro ao abrir o arquivo!");
        exit(1);
	 }else{
	 
    	system("cls");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                      CADASTRO DE INQUILINO                              |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	
        printf("\n\n  > Informe o nome do Inquilino : ");
        scanf("%[^\n]", &Dado->nome);
        
    
        printf("\n\n   > Formato : 00 00 0000\n\n > Informe a data : ");
        scanf("%d %d %d", &Dado->data.dia, &Dado->data.mes, &Dado->data.ano);
        
        printf("\n\n   > formato : ***.***.***-** \n\n > Informe o CPF: ");
        scanf("%s", &Dado->documento);
        

        printf("\n\n   > Numero do > Apartamento : ");
        scanf("%d", &Dado->apartamento);
        printf("\n");

     
        fprintf(arquivo, " Nome:%s\nData:%d / %d / %d\nDocumento:%s\nApartamento:%d\n " , Dado->nome, Dado->data.dia, Dado->data.mes, Dado->data.ano , Dado->documento , Dado->apartamento);
        printf("Dados adicionados ao arquivo!");
 	 	}
  fclose(arquivo);
	}
return Dado;
}

int lst_vazia(Lista *l){
	return (l==NULL);
}