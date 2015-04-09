#include <stdio.h>

int main(){
	
	int a, v, cong[100],x,y,i,teste = 1,maior = 0;

	while(scanf("%d %d",&a,&v) && a != 0 || v != 0){

		/*zero o vetor*/
		for (i = 0; i < 101; i++){
			cong[i] = 0;
		}

		/*leio as entradas e conto*/
		for (i = 0; i < v; i++){
			scanf("%d %d",&x,&y);
			cong[x-1]++;
			cong[y-1]++;

			if(cong[x-1] > maior || cong[y-1] > maior) 
				maior++;
		}

		printf("Teste %d\n",teste);

		/*imprimo todos congestionados*/
		for (i = 0; i < a; i++){
			if(cong[i] == maior)
				printf("%d ",i+1);
		}

		teste++;
		maior = 0;
		printf("\n\n");

	}

	return 0;
}