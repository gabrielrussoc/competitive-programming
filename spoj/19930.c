#include <stdio.h>

int main(){
	
	int n, lista[100001], i,j, alunos = 0;

	scanf("%d",&n);

	/*guardo a chamada*/
	for(i = 0; i < n; i++){
		scanf("%d",&lista[i]);
	}

	/*pego cada cara e comparo com todos os PROXIMOS*/
	for(i = 0; i < n; i++){


		if(lista[i] >= 0){

			for(j = i+1; j < n; j++){
				/*descarto os repetidos*/
				if(lista[i] == lista[j])
					lista[j] = -1;
			}

			alunos++;
		}
	}
	printf("%d\n",alunos);

	return 0;
}