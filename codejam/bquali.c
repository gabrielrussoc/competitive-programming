#include <stdio.h>

int main(){

	int t,caras,panq[10],i,j,aux,min,k;

	scanf("%d",&t);

	for(i = 0; i < t; i++){

		min = 0;

		for(j = 0; j < 10; j++){
			panq[j] = 0;
		}
		
		scanf("%d",&caras);

		for(j = 0; j < caras; j++){
			scanf("%d",&aux);
			panq[aux]++;
		}

		for(j = 9; j > 3; j--){

			while(panq[j] > 0){
				if(j > 5){ //isso aqui tá errado
					panq[j]--;
					min++;
					panq[j-3]++;
					panq[3]++;
				} else {	
					panq[j]--;
					min++;
					panq[j-2]++;
					panq[2]++;
				}	
			}

		}

		if(panq[3])
			min += 3;
		else if(panq[2])
			min += 2;
		else if(panq[1])
			min++;

		if(min > aux)
			min = aux;

		

		printf("Case #%d: %d\n",i+1,min);
	}
	
	return 0;
}