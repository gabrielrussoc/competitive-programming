#include <stdio.h>

int main(){

	int coral[10000], i, media = 0,n,qtd = 0;

	while(scanf("%d",&n) != EOF){

		/*leio as notas iniciais*/		
		for(i = 0; i < n; i++){			
			scanf("%d",&coral[i]);
			media += coral[i];					
		}

		/*se a media for inteira*/
		if(media%n == 0){
			media = media/n;
			for(i = 0; i < n; i++){
				/*pego o modulo da distancia e somo*/
				if(media - coral[i] < 0)
					qtd += coral[i]- media;
				else
					qtd += media - coral[i];				
			}

			printf("%d\n",qtd/2+1);
			qtd = 0;
			media = 0;
		} else {
			printf("-1\n");	
			media = 0;	
		}
	
	}
		
	return 0;
}
