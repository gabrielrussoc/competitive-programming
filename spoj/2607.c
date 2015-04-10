#include <stdio.h>
int main(){

	int col[100],maior = 0,linha,i,j,n,m,s;

	while(scanf("%d %d",&n,&m) != EOF){

		for(i = 0; i < m; i++)
			col[i] = 0;

		for(i = 0; i < n; i++){
			s = 0;
			for(j = 0; j < m; j++){
				scanf("%d",&linha);
				col[j] += linha;
				s += linha; 
			}
			if(s > maior)
				maior = s;			
		}

		for(i = 0; i < m; i++){
			if(col[i] > maior)
				maior = col[i];
		}

		printf("%d\n",maior);
		maior = 0;
	}

	return 0;
}
