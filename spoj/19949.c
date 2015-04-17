#include <stdio.h>
#include <stdlib.h>
#define MAX 1001

int main(){
	
	int v[MAX],n,m,resp,i;
	

	while (scanf("%d %d",&n,&m) != EOF){

		for(i = 0; i < n; i++){
			scanf("%d",&v[i]);
		}

		resp = 0;
		for(i = 1; i < n; i++){
			if(m >= v[i-1])
				v[i] += m - v[i-1];
			else
				v[i] -= v[i-1] - m;

			resp += abs(m - v[i-1]);
		}


		printf("%d\n",resp);

	}

	return 0;
}