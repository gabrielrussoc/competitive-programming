#include <stdio.h>
int main(){
	int b = 1, B[20], n = 1, N[20], i, d, c, v;

	while (scanf("%d %d", &b, &n) != 0 && b != 0 && n != 0){ /*condicao de parada*/

		for (i = 0; i < b;i++){ /*escaneio o fundo de cada banco*/
			scanf("%d",&B[i]); 		
		}

		for (i = 0; i < n; i++){ /*escaneio a configuracao de cada divida*/
			scanf("%d %d %d",&d,&c,&v);		

			B[d-1] -= v; /*devedor paga*/
			B[c-1] += v; /*credor recebe*/
		}

		for (i = 0; i < b; i++){ /*verifico se ninguem ficou com o saldo negativo*/ 
			if(B[i] < 0){
				break;
			}					
		}

		if(i < b)
			printf("N\n");		
		else
			printf("S\n");			
	
	}

	return 0;
}
