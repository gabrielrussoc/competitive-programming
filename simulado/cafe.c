#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10000


int main(){

	int maquinas[1001], n, m, i, soma, aux,j,cafe, maq;
	
	while(scanf("%d %d",&n,&m) != EOF){
		soma = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&maquinas[i]);
			soma += maquinas[i];		
		}	

		if(soma < m){
			printf("NOOOO!\n");			
		} 

		else if(m > 0){ 
				
			for(i = 0; i < n; i++){
				for(j = 0; j < n - 1; j++){
					if(maquinas[j] > maquinas[j+1]){
						aux = maquinas[j];
						maquinas[j] = maquinas[j+1];
						maquinas[j+1] = aux;
					}
				}
			}
	
			cafe = maq = 0;
			for(i = n - 1; i >= 0; i--){
				cafe += maquinas[i];
				maq++;
				if(cafe >= m)
					break;
					
			}

			printf("%d\n",maq);
			
		}
		else
			printf("0\n");	
		
	}

	return 0;
}
