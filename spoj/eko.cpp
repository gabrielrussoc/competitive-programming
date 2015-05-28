#include <cstdio>
#define MAX 1000005


int h[MAX];

int main(){
	
	int n,m,max = 0;

	scanf("%d %d",&n,&m);

	for(int i = 0; i < n; i++){
		scanf("%d",&h[i]);
		if(h[i] > max)
			max = h[i];	
	}

	unsigned long long hi = max - 1;
	unsigned long long lo = 0;

	unsigned long long mid;
	unsigned long long ans;

	while(hi > lo){
		mid = (hi+lo+1)/2;
		ans = 0;

		for(int i = 0; i < n; i++){
			int aux;
			aux = h[i] - mid;
			if(aux > 0)
				ans += aux;

			if(ans > 2000000000)
				break;
		}

		if(ans >= m)
			lo = mid;
		else
			hi = mid - 1;

	}

	printf("%llu\n",hi);


	return 0;
}