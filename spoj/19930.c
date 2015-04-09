#include <stdio.h>

int main(){
	
	int n, lista[1000001], i,aux, alunos = 0;

	scanf("%d",&n);

	/*zero um vetor*/
	for(i = 0; i < 1000001; i++){
		lista[i] = 0;
	}

	/*vejo se ja tem alguem*/
	for(i = 0; i < n; i++){
		scanf("%d",&aux);
		
		if(lista[aux] == 0){
			lista[aux] += 1;
			alunos++;
		}		
	}
	printf("%d\n",alunos);

	return 0;
}