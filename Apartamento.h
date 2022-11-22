#include <stdio.h>
#include <stdlib.h>

typedef struct apartamento Apartamento;

typedef struct lista2 Lista2;

Lista2* list_cria(void);
Lista2* InsereAp (Lista2 * list);
Apartamento * AdicionaAp(void);
int list_vazia(Lista2 *list);
void ListarAp(Lista2* l);
Lista2 * ExcluirAp ( Lista2* l, int codigo);
Lista2 *l_buscar(Lista2 *l);
void EditarAp(Lista2* l);
void disponivel(Lista2* l);