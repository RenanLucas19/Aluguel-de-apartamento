#include <stdio.h>
#include <stdlib.h>

typedef struct apartamento Apartamento;

typedef struct lista2 Lista2;

Lista2* list_cria(void);
Lista2* InsereAp (Lista2 * list);
Apartamento * AdicionaAp(void);
int list_vazia(Lista2 *list);