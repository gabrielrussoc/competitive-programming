#include <stdio.h>
int main(){
	float salario,reajuste = 0.00;
	scanf("%f",&salario);

	if(salario <= 400.00){
		reajuste = 0.15; 	
	} else if (salario <= 800.00){
		reajuste = 0.12;  	
	} else if (salario <= 1200.00){
		reajuste = 0.10;  	
	} else if (salario <= 2000.00){
		reajuste = 0.07;  	
	} else {
		reajuste = 0.04;  	
	}
	
	printf("Novo salario: %.2f\n",(salario + salario*reajuste));
	printf("Reajuste ganho: %.2f\n",salario*reajuste);
	printf("Em percentual: %.0f %%\n",reajuste*100);

	return 0;
}
