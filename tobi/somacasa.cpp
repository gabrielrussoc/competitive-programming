#include <cstdio>

int main(){
	int n,k;
	scanf("%d",&n);

	int v[100004];
	for(int i = 0; i < n; i++)
		scanf("%d",v+i);
	scanf("%d",&k);

	int lo = 0, hi = n-1;

	while(v[lo] + v[hi] != k){
		if(v[lo] + v[hi] > k)
			hi--;
		else
			lo++;
	}
	printf("%d %d\n",v[lo],v[hi]);
}