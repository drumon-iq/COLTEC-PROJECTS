#include <stdio.h>
#include <locale.h>
#include <math.h>

/*
 *ALUNO : ARIF DRUMOND BARCALA REIS
 *TURMA : 103
 *CURSO : Desenvolvimento de sistemas
 *ETAPA : 6
 *NOTA(S): Mesmo bug de input da versão anterior, não resolvido( materia avançada)
*/

int esc_menu=0;

void menuText();
void calcJurosReais(); //1 Calculo dos juros reais
void convMoedas();     //2 Conversao de moedas
void resEmerg();	   //3 Calculo da reserva de emergência
void jurComp();		   //4 Juros compostos com deposito mensal
void poupFacul();	   //5 Poupanca para a faculdade
void planDin();		   //6 Plano para juntar dinheiro
void simEmp();		   //7 Simulador de empréstimo
void calcImpostRenda();//8 Calculo do imposto de renda
//---------------// 
int safeIntInp();		// <--- Trabalhar futuramente nesses metodos
float safeFloatInp();   // <---

int main(){
	
	setlocale(LC_ALL,"");
	
	do{
		menuText();
	}while(esc_menu != 0);
	
	return 0;
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
	printf("(0) Sair\n");
	scanf("%d",&esc_menu);

	switch(esc_menu){
		
		case 0:
			break;
			
		case 1:
			calcJurosReais();
			break;
			
		case 2:
			convMoedas();
			break;
			
		case 3:
			resEmerg();
			break;
			
		case 4:
			jurComp();
			break;
			
		case 5:
			poupFacul();
			break;
			
		case 6:
			planDin();
			break;
			
		case 7:
			simEmp();
			break;
			
		case 8:
			calcImpostRenda();
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

void convMoedas(){
	
	unsigned int choice;
	float inp_value, out_value;
		
	printf("CONVERSAO DE MOEDAS\n");
	printf("Selecione a conversão desejada\n");
	printf("(1) Dolar (USD) -> Real (BRL)\n");
	printf("(2) Real (BRL) -> Dolar (USD)\n");
	printf("(3) Euro (EUR) -> Real (BRL)\n");
	printf("(4) Real (BRL) -> Euro (EUR)\n");
	printf("(5) Libra Esterlina (GBP) -> Real (BRL)\n");
	printf("(6) Real (BRL) -> Libra Esterlina (GBP)\n");
	
	scanf("%d",&choice);
	
	switch(choice){
		
		case 1:
		//Dolar para Real
			printf("Digite o valor em Dolar (USD) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value*5.12;
			printf("\nValor correspondente em Real (BRL): %.2f\n", out_value);
			break;
			
		case 2:
		//Real para Dolar
			printf("Digite o valor em Real (BRL) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value/5.12;
			printf("\nValor correspondente em Dolar (USD): %.2f\n", out_value);
			break;
			
		case 3:
		//Euro para Real
			printf("Digite o valor em Euro (EUR) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value*5.4;
			printf("\nValor correspondente em Real (BRL): %.2f\n", out_value);
			break;
			
		case 4:
		//Real para Euro
			printf("Digite o valor em Real (BRL) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value/5.4;
			printf("\nValor correspondente em Euro (EUR): %.2f\n", out_value);
			break;
			
		case 5:
		//Libra Esterlina para Real
			printf("Digite o valor em Libra Esterlina (GBP) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value*6.29;
			printf("\nValor correspondente em Real (BRL): %.2f\n", out_value);
			break;
			
		case 6:
		//Real para Libra Esterlina
			printf("Digite o valor em Real (BRL) a ser convertido: ");
			scanf("%f",&inp_value);
			out_value = inp_value/6.29l;
			printf("\nValor correspondente em Libra Esterlina (GBP): %.2f\n", out_value);
			break;
			
		default:
			printf("Entrada inválida de dados, operação cancelada!\n");
			return;
			
	}	
	
}

void resEmerg(){
	
	float sal, desp, sobra, resv, meses;
	
	printf("CALCULO DA RESERVA DE EMERGENCIA\n");
	printf("Digite o valor do salario mensal em R$: ");
	scanf("%f",&sal);
	printf("\nDigite o valor das despesas mensais em R$: ");
	scanf("%f",&desp);
	
	if(sal<0||desp<0){
		return;
	}
	
	sobra = sal-desp;
	
	resv = desp*6;
	
	meses = resv/sobra;
	
	printf("\nSerao necessarios %.0f meses para atingir esse valor poupando R$ %.2f por  mes. \n",meses,sobra);
	
}

void jurComp(){
	
	int meses;
	float invIn, depM, taxa;
	double vFinal;
	
	printf("JUROS COMPOSTOS COM DEPOSITO MENSAL\n");
	printf("Digite o valor do investimento inicial em R$: \n");
	scanf("%f",&invIn);
	printf("Digite o valor dos depósitos mensais em R$: \n");
	scanf("%f",&depM);
	printf("Digite a taxa de juros mensal: \n");
	scanf("%f",&taxa);
	printf("Digite o período de tempo em meses: \n");
	scanf("%d",&meses);
	
	if(invIn<0||depM<0||taxa<0||meses<0){
			printf("Entrada inválida de dados, operação cancelada!\n");
			return;
	}
	
	vFinal = invIn;
	
	for(int i = 1; i<meses; i++){
		
		vFinal = vFinal*(1+taxa)+depM;
	}
	
	printf("O valor ao final de %d meses sera R$ %.2lf",meses, vFinal);
	
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

void planDin(){
	
	float renda, gBas, gVid, objF, taxa;
	double mesBas, mesVid, mesPoup, poup;
	int meses;
	
	printf("PLANO PARA JUNTAR DINHEIRO\n");
	printf("Digite o valor da renda atual em R$: \n");
	scanf("%f",&renda);
	printf("Digite o percentual de gastos básicos: \n");
	scanf("%f",&gBas);
	printf("Digite o percentual de gastos com estilo de vida: \n");
	scanf("%f",&gVid);
	printf("Digite o objetivo financeiro em R$: \n");
	scanf("%f",&objF);
	printf("Digite a taxa de juros mensal dos investimentos: \n");
	scanf("%f",&taxa);
	
	if(renda<0||gBas<0||gVid<0||objF<0||taxa<0){
		printf("Entrada de dados inválida, processo cancelado");
		return;
	}
	
	taxa+=1;
	mesBas = renda*(gBas/100);
	mesVid = renda*(gVid/100);
	mesPoup = renda - (mesVid+mesBas);
	poup = mesPoup;
	
	for(meses = 1; poup<objF ; meses++){
		
		poup = poup*taxa+mesPoup;
	}
	
	printf("Total em gastos básicos: R$ %.2lf\n", mesBas);
	printf("Total em gastos com estilo de vida: R$ %.2lf\n", mesVid);
	printf("Total a ser poupado: R$ %.2lf\n", mesPoup);
	printf("Tempo para atingir o objetivo financeiro: %d meses\n", meses);
	
	//printf("\n%f\n",poup);
}

void simEmp(){
	
	
}

void calcImpostRenda(){
		
	int choice, dias;
	float invst, resg, per_IR;
	double bruto, liqd, impR_rend, impR_of;
	
	printf("CALCULO DE IMPOSTO DE RENDA\n");
	printf("(1) Acoes\n");
	printf("(2) Renda Fixa\n");
	
	scanf("%d",&choice);
	
	printf("\nDigite o valor total investido em R$: ");
	scanf("%f",&invst);
	printf("\nDigite o valor total resgatado em R$: ");
	scanf("%f",&resg);
	printf("\nDigite o tempo total do investimento em dias: ");
	scanf("%d",&dias);
	
	//Teste de input, será implementada em outro metodo mais tarde?
	if(choice<0 || dias<0 || invst<0 || resg<0 || (invst==0 && resg>invst)){
		printf("Entrada inválida de dados no programa, operação cancelada!");
		return;
	}
	
	bruto = resg - invst;
	
	switch(choice){
		
		case 1:
		//Ação
			
			if(resg>20000){
				
				if(dias==0){
					per_IR = 0.2;
					impR_rend = bruto*per_IR;
					liqd = bruto - impR_rend;
					
					printf("Lucro Bruto: R$ %.2lf\n",bruto);
					printf("Lucro Liquido: R$ %.2lf\n",liqd);
					printf("Imposto de Renda Retido: R$ %.2lf\n",impR_rend);
					
				}
				else{
					per_IR = 0.15;
					impR_rend = bruto*per_IR;
					liqd = bruto - impR_rend;
					
					printf("Lucro Bruto: R$ %.2lf\n",bruto);
					printf("Lucro Liquido: R$ %.2lf\n",liqd);
					printf("Imposto de Renda Retido: R$ %.2lf\n",impR_rend);
				}
				
				
			}
			else{
				//Não há imposto de renda nesse caso, liquido = bruto
				liqd = bruto;
				
				printf("Lucro Bruto: R$ %.2lf\n",bruto);
				printf("Lucro Liquido: R$ %.2lf\n",liqd);
			}
			
			break;
			
		case 2:
		//Investimento
		
			//Imposto de renda
	
			if(dias>720){
				per_IR = 0.15;
			}
			else if(dias>360){
				per_IR = 0.175;
			}
			else if(dias>180){
				per_IR = 0.2;
			}
			else{
				per_IR = 0.225;
			}
			
			//Calculo imposto de renda, operação finaceira e lucro liquido
			if(dias>=30){
				impR_rend = bruto*per_IR;
				liqd = bruto - impR_rend;
				printf("Lucro Bruto: R$ %.2lf\n",bruto);
				printf("Lucro Liquido: R$ %.2lf\n",liqd);
				printf("Imposto de Renda Retido: R$ %.2lf\n",impR_rend);
				
				//Debugging
				//printf("\n\n%f %lf\n",liqd,impR_rend);
			}
			else{
				impR_of = bruto*(0.01*(100-dias*3.33));
				liqd = bruto - impR_of;
				impR_rend = liqd*per_IR;
				liqd = liqd - impR_rend;
				printf("Lucro Bruto: R$ %.2lf\n",bruto);
				printf("Lucro Liquido: R$ %.2lf\n",liqd);
				printf("IOF retido: R$ %.2lf\n",impR_of);
				printf("Imposto de Renda Retido: R$ %.2lf\n",impR_rend);
			}
			
			break;
			
		default:
			printf("Entrada inválida, operação cancelada!");
			return;
		
	}
	
}


//Licensed under GPL v3.0, drumon 2022

