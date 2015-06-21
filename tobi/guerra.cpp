#include <cstdio>

int main(){
	
	int n, v[100005], soma = 0;
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",v+i);
		soma += v[i];	
	}

	int ans = 0;
	int i;
	for(i = 0; i < n; i++){
		ans += v[i];
		soma -= v[i];
		if(soma == ans)
			break;
	}
	printf("%d\n",i+1);


}