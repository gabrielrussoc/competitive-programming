#include <stdio.h>
#define MAX 100001

int main(){
	int casa[MAX],n,k,i,ini,fim,mid,pivo;

	while(scanf("%d",&n) != EOF){
		for(i = 0; i < n; i++){
			scanf("%d",&casa[i]);
		}
		scanf("%d",&k);

		for(i = 0; i < n; i++){
			ini = i+1;
			fim = n-1;
			pivo = casa[i];

			while(1){
				if (ini > fim)
					break;
				mid = (ini+fim)/2;
				if(casa[mid] + pivo == k)
					break;
				else if(casa[mid] + pivo > k)
					fim = mid - 1;
				else if(casa[mid] + pivo < k)
					ini = mid + 1;			
			}

			if(casa[mid] +  pivo == k){
				printf("%d %d\n",pivo, casa[mid]);
				break;
			}	
		}	

	}

	return 0;
}
