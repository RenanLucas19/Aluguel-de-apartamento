#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Inquilino.c"
#include "Apartamento.c"


#define TITULO_OPCAO1 "ADICIONAR INQUILINO "
#define TITULO_OPCAO2 "EXCLUIR INQUILINO "
#define TITULO_OPCAO3 "LISTAR INQUILINO "
#define TITULO_OPCAO4 "BUSCAR INQUILINO "
#define TITULO_OPCAO5 "EDITAR INQUILINO "
#define TITULO_OPCAO6 "CONSULTAR APARTAMENTOS DISPONIVEIS  "
#define TITULO_OPCAO7 "CONSULTAR QUANTITATIVO DE INQUILINOS "
#define TITULO_OPCAO8 "SAIR "


#define N_OPCOES 8
#define OPCAO1 '1'
#define OPCAO2 '2'
#define OPCAO3 '3'
#define OPCAO4 '4'
#define OPCAO5 '5'
#define OPCAO6 '6'
#define OPCAO7 '7'
#define OPCAO8 '8'

void LimpaBuffer(void) {
    int valorLido; 
    do {
        valorLido = getchar();
    } while ((valorLido != '\n') && (valorLido != EOF));
}

int LeOpcao(int menorValor, int maiorValor) {
    int op;
    while (1) {
        printf("\nDigite sua opcao: ");
        op = getchar();
        if (op >= menorValor && op <= maiorValor) {
            LimpaBuffer();
            break;
        }
        else {
            printf("\nOpcao invalida. Tente novamente.");
            printf("\nA opcao deve estar entre %c e %c. \n",
                   menorValor, maiorValor);
            LimpaBuffer();
        }
    }
    return op;
}

void ApresentaMenu(int nItens, int menorOpcao, ...) {
    int i;
    va_list argumentos;
   
    va_start(argumentos, menorOpcao);

    for(i = 0; i < nItens; ++i) {
        printf("%c-%s\n", menorOpcao++, va_arg(argumentos, char *));
    }
    va_end(argumentos);
}

int main(void) {
    unsigned char op;
    unsigned int saida = 0; //
	Lista * CadastroInquilino = lst_cria();
	Lista2 * CadastroApartamento = list_cria();
	char nome[50];
	int codigo;
	
		printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
    	
    do {
        ApresentaMenu(N_OPCOES, OPCAO1,
                      TITULO_OPCAO1, TITULO_OPCAO2,
                      TITULO_OPCAO3, TITULO_OPCAO4,TITULO_OPCAO5, TITULO_OPCAO6, TITULO_OPCAO7, TITULO_OPCAO8 );
        op = LeOpcao(OPCAO1, OPCAO1 + N_OPCOES - 1);
        
        switch(op) {
            case OPCAO1:
                Beep(1000,500); 
        printf("\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                       ADICIONAR INQUILINO                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
              CadastroInquilino = lst_insere(CadastroInquilino);
              CadastroApartamento = InsereAp(CadastroApartamento);

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");

				break;
            case OPCAO2:
                Beep(1000,500);
        printf("\n");     
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                         EXCLUIR INQUILINO                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n");
    	
      
         printf("Informe o nome do inquilino para a excluir : ");
        scanf(" %[^\n]", nome);
        
        CadastroInquilino = ExcluirInquilino(CadastroInquilino, nome);
        
        printf("Informe o codigo do apartamento do inquilino para a excluir : ");
        scanf("%d", &codigo);
        
        CadastroApartamento = ExcluirAp(CadastroApartamento, codigo);
        printf("\n\n");
        printf("Inquilino exluido com sucesso!");
        printf("\n");
        
         printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");

                break;

            case OPCAO3:
                Beep(1000,500);
        printf("\n");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                         LISTAR INQUILINOS                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n");
    		ListarInquilino(CadastroInquilino);
    		printf("\n");
    		
    	printf("\n");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                       LISTAR APARTAMENTOS                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n");
    		ListarAp(CadastroApartamento);
    		printf("\n");

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");

                break;

            case OPCAO4:
                Beep(1000,500);
        printf("\n");                 
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                         BUSCAR INQUILINOS                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
                
             CadastroInquilino = lst_buscar(CadastroInquilino);
		  	 CadastroApartamento = l_buscar(CadastroApartamento);
			   

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");

                break;
             case OPCAO5:
                Beep(1000,500);
        printf("\n");                          
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                         EDITAR INQUILINOS                               |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
                
               EditarInq( CadastroInquilino);
               EditarAp(CadastroApartamento );
                break;

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
           
             case OPCAO6:
              Beep(1000,500); 
		printf("\n");	   
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                      CONSULTAR APARTAMENTO DISPONIVEL                   |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");  
		 	
              disponivel(CadastroApartamento );

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
                break;
          
                 case OPCAO7:
                Beep(1000,500);
        printf("\n");        
		printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                   CONSULTAR QUANTIDADE DE INQUILINOS                    |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
               quant(CadastroInquilino);

        printf("\n\n");        
        printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                SISTEMA DE ALUGUEL DE APARTAMENTO                        |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
               
                break;
             case OPCAO8:
        printf("\n");     	
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n    |                            PROGRAMA ENCERRADO                           |");
    	printf("\n    #-------------------------------------------------------------------------#");
    	printf("\n\n");
              saida = 1;
                Beep(1000,500);
                printf("Obrigado por usar este programa !!\n");
               
                default:
                printf("Este programa possui um bug.\n");
                return 1;
        }
    } while(!saida);
    return 0;
}

