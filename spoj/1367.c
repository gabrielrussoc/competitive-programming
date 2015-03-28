#include <stdio.h>

int main(){
	/*
	pos = layout do caixa
	senha = a senha em si
	n, i, j ,k = auxiliares de loops
	a,b = valores da matriz para ler melhor;
	cont = contador geral
	*/
	int pos[2][5],senha[2][6],n,i,j,k,a,b,cont = 0;
	char letra;
	
	/*condicao de parada*/
	while (scanf("%d",&n) != EOF && n != 0){
		/*le n entradas */
		for(i = 0; i < n; i++){
			
			/*leitura da disposicao dos digitos*/
			for(j = 0; j < 5; j++){
				scanf("%d %d",&pos[0][j],&pos[1][j]);			
			}

			/*leitura da senha do cliente*/
			for(k = 0; k < 6; k++){
				scanf(" %c",&letra);
				letra -= 'A';

				if(i > 0){	
					/*descartando invalidos*/

					a = pos[0][letra];
					b = pos[1][letra];

					if(a == senha[0][k] || (b == senha[0][k] && a != senha[1][k])){
						senha[1][k] = -1;
					} else if (b == senha[1][k] || (a == senha[1][k] && b != senha[0][k])){
						senha[0][k] = -1;
					}

				} else {
					/*ordena a possivel senha*/
					senha[0][k] = pos[0][letra];
					senha[1][k] = pos[1][letra]; 
				}				
			}	
		}
		cont++;
		/*printa a senha*/
		printf("Teste %d\n",cont);
		for(k = 0; k < 6; k++){
			if(senha[0][k] >= 0)
				printf("%d ",senha[0][k]);
			else
				printf("%d ",senha[1][k]);
		}

		printf("\n\n");

	}

	return 0;
}
