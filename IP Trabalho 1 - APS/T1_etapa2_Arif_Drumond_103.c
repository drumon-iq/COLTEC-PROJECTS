#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 *ALUNO : ARIF DRUMOND BARCALA REIS
 *TURMA : 103
 *CURSO : Desenvolvimento de sistemas
 *ETAPA : 2
 *NOTA(S): Do jeito que especifiquei a formatação do programa, valores flutuantes devem ser escritos com "," e não ".", como 12,9 e não 12.9
 * , pelo que sei esse problema é devido ao programa tratar o ponto como um caracter, que leva a um erro de input e causa o programa a ficar preso em
 * um loop.
 * Segunda versão, editado pequenos erros de impressão no poupFacul, bug de entrada de dados ainda não corrigido
*/

int esc_menu=9;

void menuText();
void calcJurosReais();
void poupFacul();

int main()
{
	setlocale(LC_ALL,"");
	
	while(esc_menu != 0){
	menuText();
	}
}

void menuText(){


	printf("\nMYMONEY - DIGITE A OPÇÃO DESEJADA\n");
	printf("(1) Calculo dos juros reais\n");
	printf("(2) Conversao de moedas\n");
	printf("(3) Calculo da reserva de emergência\n");
	printf("(4) Juros compostos com deposito mensal\n");
	printf("(5) Poupanca para a faculdade\n");
	printf("(6) Plano para juntar dinheiro\n");
	printf("(7) Simulador de empréstimo\n");
	printf("(8) Calculo do imposto de renda\n");
	scanf("%d",&esc_menu);

	switch(esc_menu){

		case 1:
			calcJurosReais();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			poupFacul();
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			printf("Opção invalida!\n");
	}
}

void calcJurosReais(){
	float jNom, inf, jRe;

	printf("CALCULO DOS JUROS REAIS\n");
	printf("Digite a taxa de juros nominal a.a. em %%:\n");
	scanf("%f",&jNom);
	printf("Digite a taxa de inflação a.a. em %%:\n");
	scanf("%f",&inf);
	jRe = (jNom/100+1)/(inf/100+1);
	jRe = (jRe-1)*100;
	printf("Taxa de juros reais a.a. em %%: %.2f \n",jRe);


	//debuging
	//printf("%f%f%f",jNom,inf,jRe);
}

void poupFacul(){

	double meses, juros, preco, parcela, valTot;
	int idade, tempo, tempMes; 
	printf("POUPANCA PARA A FACULDADE\n");
	printf("Digite o valor da mensalidade em R$:\n");
	scanf("%lf",&preco);
	printf("Digite o tempo do curso em anos:\n");
	scanf("%d",&tempo);
	printf("Digite a idade atual do filho:\n");
	scanf("%d",&idade);
	printf("Digite a taxa de juros mensal dos investimentos:\n");
	scanf("%lf",&juros);
	tempMes = tempo*12;
	valTot= tempMes*preco;
	if(preco<0 || tempo<0 || idade<0 || juros<0){
		printf("Entrada de dados negativo, operação cancelada!\n");
		return;
	}
	else if(idade >= 18){
		parcela = preco;
	}
	else{
		meses = (18-idade)*12;
		parcela = (valTot*juros)/(pow(1+juros,meses)-1);
	}
	printf("O valor total do curso após %d anos é R$ %.2lf\n", tempo, valTot);
	printf("Você deve poupar R$ %.2lf por mês\n",parcela);

}
