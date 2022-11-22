#include <stdio.h>
#include <stdlib.h>



typedef struct Inquilino inquilino;

typedef struct lista Lista;

inquilino* InsereDados(void);
Lista* lst_cria(void);
Lista* lst_insere(Lista* list);
int lst_vazia(Lista *l);
Lista* ExcluirInquilino(Lista* l , char *nome);
void ListarInquilino ( Lista * l);
Lista *lst_buscar(Lista*l);
void EditarInq(Lista*l);
void quant(Lista* l);
Lista* OrdenaInq (Lista * l, int inq );