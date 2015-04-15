#include <stdio.h>

int main(){
	
	char tabuleiro[101][101];
	char auxiliar[101];
	int n,i,j,comida,maior;

	while(scanf("%d",&n) != EOF){

		maior = 0;
		comida = 0;

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf(" %c",&tabuleiro[i][j]);
			}
		}

		//inverto as linhas que ele 'vira'
		for(i = 1; i < n; i += 2){
			for(j = 0; j < n; j++){
				auxiliar[n-j-1] = tabuleiro[i][j];
			}
			for(j = 0; j < n; j++){
				tabuleiro[i][j] = auxiliar[j];
			}
		}

		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(tabuleiro[i][j] == 'o'){
					comida++;
					if(comida > maior)
						maior = comida;
				}
				else if(tabuleiro[i][j] == 'A'){
					comida = 0;
				}
			}
		}

		printf("%d\n",maior);

	}


	return 0;
}
