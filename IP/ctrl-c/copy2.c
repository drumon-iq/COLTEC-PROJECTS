#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct sTentativa
{
    char palavra[100];
    char simOuNao[5];
}tentativa;

int validaPalavra(char palavra[],char ultima)
{   
    
    if(strlen(palavra) == 10){
        return 1;
    }
    
    if((palavra[0] == 'a')||(palavra[0]=='A')){
        return 1;
    }
    if((palavra[strlen(palavra)-1] == 'r') || (palavra[strlen(palavra)-1] == 'R')){
        return 1;
    }
    if(palavra[0] == tolower(ultima)){
        return 1;
    }
    if((palavra[3] == 'w')||(palavra[3] == 'W'))
    {
        return 1;
    }
    
    return 0;
}
int main()
{

    int structs = 5;
    
    tentativa *tentativas = (tentativa*) malloc (structs*sizeof(tentativa));

    char * nome = (char*) calloc (20,sizeof(char) );

    printf("----------------------------------------------------------\n");

    printf("Welcome to Piquenique na Lua\n");

    printf("Antes de tudo, digite seu nickname:");

    fgets(nome,49,stdin);

    int tamanhonome = strlen (nome) - 1;

    char * diretorio = (char*) calloc ( tamanhonome , sizeof(char) );

    strncat (diretorio , nome , tamanhonome );

    strcat ( diretorio , ".txt" );

    FILE * arquivo = fopen ( diretorio , "w+" );

    if( arquivo == NULL ){

        printf ("deu ruim no arquivo");

        return 0;

    }

    printf("----------------------------------------------------------\nola, vamos comecar a jogar.\ndigite uma palavra e vou lhe dizer se pode ou nao leva-la.\ndigite q para sair do jogo\ndigite h para historico de tentativas\nVoce tem o direito de errar 30 vezes, caso acerte 5 vezes seguidas, será considerado vencedor!\n----------------------------------------------------------\n");
    
    int vez = 0;

    int final = 30;

    int deubom = 0;

    int tamanhopalavra = 0;

    int aprovado;

    int repetido = 0;
    
    while(1){

        repetido=0;

        if(vez >= 5){

            structs++;

            tentativas = (tentativa*) realloc (tentativas,structs*sizeof(tentativa));

        }
        printf("-->Digite uma palavra:");

        fgets(tentativas[vez].palavra , 99 , stdin);

        tamanhopalavra=strlen(tentativas[vez].palavra)-1;

        if((tentativas[vez].palavra[0] == 'q') && (tamanhopalavra == 1)){

            printf("aaaaa :( voce saiu do jogo\n");

            break;
        }

        if((tentativas[vez].palavra[0] == 'h') && (tamanhopalavra == 1)){
           printf("-------------- historico de tentativas -------------------\n");

           for(int i=0;i<vez;i++){

               printf("numero da tentativa: %i",i+1);

               printf("\n");

               printf("Palavra que tentou: %s",tentativas[i].palavra);

               printf("\n");

               printf("Palavra foi aceita? %s",tentativas[i].simOuNao);

               printf("\n");
           }
           printf("----------------------------------------------------------\n");

        }
        else
        {
            tentativas[vez].palavra[tamanhopalavra] =' \0';

            aprovado=validaPalavra(tentativas[vez].palavra,tentativas[vez-1].palavra[strlen(tentativas[vez-1].palavra)-1]);

            if(vez!=0){
                for(int i = 0 ; i < vez ; i++){
                    
                    if(strcmp(tentativas[vez].palavra,tentativas[i].palavra) == 0)
                    {
                        aprovado = 0;
                    }

                }
            
            }

            repetido=0;

            if(aprovado==1){

                deubom++;

                printf("MALOU! pode levar %s para o piquenique\n",tentativas[vez].palavra);

                tentativas[vez].simOuNao[0]='s';

                tentativas[vez].simOuNao[1]='i';

                tentativas[vez].simOuNao[2]='m';

                fprintf(arquivo,"%s\n",tentativas[vez].palavra);

            }
            else if(aprovado==0){

                final--;

                printf("NAO e permitido %s no piquenique\n",tentativas[vez].palavra);

                printf("Tentativas restantes: %i\n",final);
                tentativas[vez].simOuNao[0] = 'n';

                tentativas[vez].simOuNao[1] = 'a';
                
                tentativas[vez].simOuNao[2] = 'o';

            }

            vez++;

        }
        if(final == 0){

            printf("PERDEU :(, VOCE TENTOU DE MAIS CAMPEA/O\n");

            break;
        }
        if(deubom == 5){

            printf("AEEEEEEEEE, GANHOUS\n");

            break;
        }

    }
    
    fclose(arquivo);

    free(tentativas);

    free(nome);

    free(diretorio);

    system("pause");

    return 0;
}