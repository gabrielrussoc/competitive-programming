#include <stdio.h>

int main(){
	
	int v[2][5],i,j,flag;

	while(scanf("%d",&v[0][0]) != EOF){
			
		for(j = 1; j < 5; j++)
			scanf("%d",&v[0][j]);
		for(j = 0; j < 5; j++)
			scanf("%d",&v[1][j]);

		flag = 1;
		for(j = 0; j < 5 && flag; j++){
			if(v[0][j] == v[1][j]){
				printf("N\n");
				flag = 0;
			}
		}

		if(flag)
			printf("Y\n");
	}

	return 0;
}