#include <stdio.h>

int main(){
	
	int freq[10000], sentido, n,i,pico = 0;

	while(scanf("%d",&n) && n != 0){
	
		/*guardo os valores*/
		for(i = 0; i < n; i++){
			scanf("%d",&freq[i]);
		}

		/*vejo como começa*/
		if(freq[n-1] < freq[0])
			sentido = 1;
		else
			sentido = 0;	

		for(i = 0; i < n; i++){
			
			if(sentido){
				if(freq[i+1] < freq[i]){
					sentido = 0;
					pico++;
				}
			}
			else{	
				if(freq[i+1] > freq[i]){
					sentido = 1;
					pico++;
				}
			}	
		}

		printf("%d\n",pico);
		pico = 0;
	} 


	return 0;
}