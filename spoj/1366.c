#include <stdio.h>

int main(){
	
	int m,n,matriz[1001][1001],i,j,x,y,horizontal,vertical,ok,teste = 1;

	while(scanf("%d %d",&m,&n) && m != 0){

		horizontal = vertical = 0;
		ok = 1;

		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				scanf("%d",&matriz[i][j]);
			}
		}

		while(ok){
			scanf("%d %d",&x,&y);
			horizontal += -x;
			vertical += y;
			if(x == 0 && y == 0)
				ok = 0;
		}

		if(horizontal < 0)
			horizontal = n + horizontal;
		if(vertical < 0)
			vertical = m + vertical;

		printf("Teste %d\n",teste);

		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				printf("%d ",matriz[(i+vertical)%m][(j+horizontal)%n]);
			}
			printf("\n");
		}
		printf("\n");


		teste++;

	}



	return 0;
}