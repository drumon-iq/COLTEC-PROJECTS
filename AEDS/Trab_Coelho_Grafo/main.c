#include "commondef.h"
#include "grafo_m.h"


int main() {
    Grafo mapaWonderLand;
    criarGrafo(&mapaWonderLand, MAX_VERTICES);
    
    adicionarAresta(&mapaWonderLand, TRIBUNAL, PRISAO);
    adicionarAresta(&mapaWonderLand, PRISAO, PALACIO_COPAS);
    adicionarAresta(&mapaWonderLand, PALACIO_COPAS, SITIO_TORTUGAS);
    adicionarAresta(&mapaWonderLand, SITIO_TORTUGAS, CAMPO_CROCHE);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, ROSEIRAL);
    adicionarAresta(&mapaWonderLand, CAMPO_CROCHE, SALAO_PORTAS);
    adicionarAresta(&mapaWonderLand, SALAO_PORTAS, SALAO_CHA);
    adicionarAresta(&mapaWonderLand, SALAO_PORTAS, LAGOA_LAGRIMAS);
    adicionarAresta(&mapaWonderLand, LAGOA_LAGRIMAS, CHALE_COELHO);
    adicionarAresta(&mapaWonderLand, LAGOA_LAGRIMAS, ARVORE_GATO);
    adicionarAresta(&mapaWonderLand, ARVORE_GATO, CENTRO_INFO);
    adicionarAresta(&mapaWonderLand, CENTRO_INFO, COZINHA_DUQ);
    adicionarAresta(&mapaWonderLand, COZINHA_DUQ, CHALE_COELHO);

    encontrarMenorCaminho(&mapaWonderLand, CHALE_COELHO, PALACIO_COPAS);

    return 0;
}
