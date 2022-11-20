#include <stdio.h>
#include <stdlib.h>

typedef struct nasc NASC;

typedef struct Inquilino inquilino;

typedef struct lista Lista;

inquilino * InsereDados(void);
Lista* lst_cria(void);
Lista* lst_insere(Lista* list);
int lst_vazia(Lista *l);