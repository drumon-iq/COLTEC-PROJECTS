#include "commondef.h"

typedef struct {
    int fila[MAX_VERTICES];
    int pos_ini;
    int pos_final;
} Fila;

// Inicializa uma fila
void initializarFila(Fila *q);

// Verifica se a fila está vazia
bool filaVazia(Fila *q);

// Adiciona um elemento à fila
void adc_Fila(Fila *q, int vertex);

// Remove e retorna um elemento da fila
int rem_da_Fila(Fila *q);
