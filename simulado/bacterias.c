#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){

	int a,b,n,i,indice;

	float maior;
	
	while(scanf("%d",&n) != EOF){
		maior = 0;		

		for(i = 0; i < n; i++){
			scanf("%d %d",&a,&b);
			if(b*log(a) > maior){
				indice = i+1;
				maior = b*log(a);
			}
		}

		printf("%d\n",indice);

	}
	
		
	

	return 0;
}
