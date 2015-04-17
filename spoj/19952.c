#include <stdio.h>
#include <stdlib.h>
#define MAX 45001


int casas[MAX];

int buscab(int ini, int fim, int encomenda){
	int mid = (ini + fim)/2;
	if (casas[mid] == encomenda) 
		return mid;
	else if (casas[mid] > encomenda)
		return buscab(ini,mid-1,encomenda);
	else if (casas[mid] < encomenda)
		return buscab(mid+1,fim,encomenda);
	else if (fim < ini)
		return -1;
}


int main(){

	int n,m,encomenda,i,carteiro,ini,fim,tempo,prox;

	while(scanf("%d %d",&n,&m) != EOF){
		
		ini = 0;
		fim = n;
		
		for(i = 0; i < n; i++){
			scanf("%d",&casas[i]);
		}

		carteiro = tempo = 0;
		for(i = 0; i < m; i++){
			scanf("%d",&encomenda);
			prox = buscab(ini,fim,encomenda);
			tempo += abs(prox - carteiro);
			carteiro = prox;
		}

		printf("%d\n",tempo);	
		

	}


	return 0;

}
