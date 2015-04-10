#include <stdio.h>

int main(){

	int i,j,matriz[501][501],m,n,esc,ind;

	while(scanf("%d %d",&n,&m) != EOF){
		
		esc = 1;
		
		/*guardo a entrada*/
		for(i = 0; i < n; i++){
			for(j = 0; j < m; j++){
				scanf("%d",&matriz[i][j]);	
			}		
		}

		ind = -1;
		/*vejo se ta tudo ok*/
		for(i = 0; i < n; i++){		
	
			/*procuro um inteiro*/
			for(j = 0; j < m; j++){
				if(matriz[i][j] != 0){
					break;
				} else if(j > ind){
					ind = j;
				}	
			}

			/*vejo se ele está no lugar errado*/
			if(j <= ind && matriz[i][j] != 0){
				esc = 0;
				break;
			} else {
				ind = j;			
			}		
		}

		if(esc)
			printf("S\n");
		else
			printf("N\n");
		
	
	}

	return 0;
}

