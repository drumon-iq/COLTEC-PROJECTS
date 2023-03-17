#include <stdio.h>
#include <locale.h>

int main(){
	
	printf("A diferença entre 'A' e \"A\" está no uso de aspas, pois\na letra A no meio de aspas simples representa o caractere ASCII, de numero %d,\nmas quando está entre aspas duplas este é uma STRING, um vetor de caracteres\neste ultimo acaba por ocupar mais espaço pois possuí um caractere especial\nque representa o final da string. Então a representação de aspas simples ocupa\n1 byte na memoria e o de aspas duplas ocupa 2 bytes.\n", 'A');
	
}

