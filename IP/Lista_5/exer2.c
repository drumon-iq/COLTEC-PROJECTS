#include <stdio.h>

int main(){
	
	double sal, medSal, mSal=0;
	char sexo,esc;
	int pessSal=0, hom=0, mul=0, totP;
	
	do{
		printf("Digite o valor do salario:\n");	
		scanf("%lf",&sal);
		printf("Digite o sexo, M - Masculino F - Feminino:\n");
		scanf(" %c",&sexo);

		if(sexo == 'M'){
			hom++;
		}
		else {
			mul++;
		}

		medSal += sal;
		
		if(sal>mSal){ mSal=sal; }
		if(sal <= 998){ pessSal++; }	

		printf("Deseja inserir mais dados? S ou N\n");
		scanf(" %c",&esc);
	}while(esc!='N');
	
	totP = hom+mul;
	medSal = medSal/totP;
	pessSal = (pessSal*100)/totP;
	
	printf("Media de salario dos entrevistados: %.2lf\n", medSal );
	printf("Percentual de homens: %d %%\n", (hom*100)/totP );
	printf("Percentual de mulheres: %d %%\n", (mul*100)/totP );
	printf("Maior salario: %.2lf\n", mSal);
	printf("Pessoas com salario inferior a 998,00: %d %%\n", pessSal);

}

// Media, per das pessoas por sexo, maior salario, pessoas com salario menor ou igual 998
