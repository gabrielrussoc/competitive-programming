#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000


int main(){

	int lucro, v[MAX],i,j,n,max;

	while(scanf("%d",&n) != EOF){
		lucro = 0;
		max = 0;
		for(i = 0; i < n; i++){
			scanf("%d",&v[i]);
			lucro -= v[i];
			if(lucro < 0)
				lucro = 0;
			if(lucro > max)
				max = lucro;
		}

		printf("%d\n",max);
	}	
	
	return 0;
}
