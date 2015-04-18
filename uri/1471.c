#include <stdio.h>
#define MAX 10001

int merg[MAX];

int buscab(int ini, int fim, int voltou){
	int mid = (ini + fim)/2;

	if(merg[mid] == voltou) 
		return mid;
	else if(merg[mid] > voltou)
		return buscab(ini, mid -1, voltou);
	else if(merg[mid] < voltou) 
		return buscab(mid +1, fim, voltou);
	else
		return MAX;
	
}

int main(){

	int n,r,voltou,vivos[MAX],i;

	while(scanf("%d %d",&n,&r) != EOF){

		

		for(i = 0; i < n; i++){
			merg[i] = i+1;
			vivos[i] = i+1;
		}

		for(i = 0; i < r; i++){
			scanf("%d",&voltou);
			vivos[buscab(0,n,voltou)] = 0;
		}

		if(n == r)
			printf("*");

		else {
			for(i = 0; i < n; i++){
				if(vivos[i])
					printf("%d ",vivos[i]);
			}
		}	

		printf("\n");

	}
	
	return 0;
}