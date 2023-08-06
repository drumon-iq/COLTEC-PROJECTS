#include "fila.h"

// Inicializa uma fila
void initializarFila(Fila *q) {
    q->pos_ini = q->pos_final = -1;
}

// Verifica se a fila está vazia
bool filaVazia(Fila *q) {
    return q->pos_ini == -1;
}

// Adiciona um elemento à fila
void adc_Fila(Fila *q, int vertex) {
    if (q->pos_final == MAX_VERTICES - 1) {
        printf("Fila cheia!\n");
        return;
    }

    if (q->pos_ini == -1) {
        q->pos_ini = 0;
    }

    q->pos_final++;
    q->fila[q->pos_final] = vertex;
}

// Remove e retorna um elemento da fila
int rem_da_Fila(Fila *q) {
    if (filaVazia(q)) {
        printf("Fila vazia!\n");
        return -1;
    }

    int vertex = q->fila[q->pos_ini];

    if (q->pos_ini == q->pos_final) {
        q->pos_ini = q->pos_final = -1;
    } else {
        q->pos_ini++;
    }

    return vertex;
}

