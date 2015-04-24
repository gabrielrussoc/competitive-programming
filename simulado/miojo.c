#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){

	int a1,a2,maior,menor,miojo,aux;

	while(scanf("%d %d %d",&miojo,&a1,&a2) != EOF){
		
		if(a2 > a1){
			aux = a2;
			a2 = a1;
			a1 = aux;
		}

		maior = a1;
		menor = a2;

		while((maior - menor) != miojo){
			menor += a2;


			if(menor > maior){
				aux = maior;
				maior = menor;
				menor = aux;

				aux = a1;
				a1 = a2;
				a2 = aux;
			}
					
		}

		printf("%d\n",maior);
			
	}

	return 0;
}
