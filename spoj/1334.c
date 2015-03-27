#include <stdio.h>

int main(){

	int m,i,num,soma = 0,cont = 0;
	char op;

	while(scanf("%d",&m) && m != 0){
		
		scanf("%d",&num);
		soma = num;

		for(i = 1; i < m; i++){
			scanf(" %c",&op);
			scanf("%d",&num);
			
			if (op == '+')
				soma +=	num;
			else
				soma -= num;	
			
		}

		cont++;
		
		printf("Teste %d\n",cont);
		printf("%d\n\n",soma);
	}

	return 0;
}
