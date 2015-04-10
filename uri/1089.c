#include <stdio.h>

int main(){
	
	int freq[10001], sentido, n,i,pico = 0;

	while(scanf("%d",&n) && n != 0){
	
		/*guardo todos*/
		for(i = 0; i < n; i++){
			scanf("%d",&freq[i]);
		}

		/*comparo o ultimo com o primeiro para ver como comeca*/
		if(freq[n-1] > freq[0]){
			sentido = 0;
		} else {
			sentido = 1;
		}

		/*coloco o primeiro na ultima posicao p comparar no final*/
		freq[n] = freq[0];

		for(i = 0; i < n; i++){

			if(sentido){

				if(freq[i] > freq[i+1]){
					pico++;
					sentido = 0;
				}

			} else {

				if(freq[i] < freq[i+1]){
					pico++;
					sentido = 1;
				}
			}
		}

		printf("%d\n",pico);
		pico = 0;


	} 


	return 0;
}