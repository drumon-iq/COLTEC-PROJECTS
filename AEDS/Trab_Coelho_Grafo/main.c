#include "commondef.h"
#include "grafo_m.h"

#define TRIBUNAL        0
#define PRISAO          1 
#define PALACIO_COPAS   2
#define SITIO_TORTUGAS  3
#define CAMPO_CROCHE    4
#define ROSEIRAL        5
#define SALAO_PORTAS    6
#define SALAO_CHA       7
#define LAGOA_LAGRIMAS  8
#define ARVORE_GATO     9
#define CENTRO_INFO     10
#define COZINHA_DUQ     11
#define CHALE_COELHO    12
#define BRINCO_COELHO   13

int main() {
    Grafo mapaWonderLand;
    criarGrafo(&mapaWonderLand, MAX_VERTICES);
    
    adicionarAresta(&mapaWonderLand, PALACIO_COPAS, PRISAO);
    adicionarAresta(&mapaWonderLand, PALACIO_COPAS, TRIBUNAL);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, PALACIO_COPAS);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, SITIO_TORTUGAS);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, ROSEIRAL);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, SALAO_CHA);
    adicionarAresta(&mapaWonderLand, ROSEIRAL, SALAO_PORTAS);
    adicionarAresta(&mapaWonderLand, SALAO_PORTAS, SALAO_CHA);
    adicionarAresta(&mapaWonderLand, SALAO_PORTAS, ARVORE_GATO);
    adicionarAresta(&mapaWonderLand, SALAO_CHA, CHALE_COELHO);
    adicionarAresta(&mapaWonderLand, ARVORE_GATO, CENTRO_INFO);
    adicionarAresta(&mapaWonderLand, CENTRO_INFO, COZINHA_DUQ);
    adicionarAresta(&mapaWonderLand, COZINHA_DUQ, CHALE_COELHO);
    adicionarAresta(&mapaWonderLand, CHALE_COELHO, BRINCO_COELHO);

    encontrarMenorCaminho(&mapaWonderLand, CHALE_COELHO, PALACIO_COPAS);

    return 0;
}
