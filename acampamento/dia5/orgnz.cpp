#include <cstdio>
#include <algorithm>
#define MAX 200007

using namespace std;

int main(){
	long long n;
	int v[MAX];
	int mini,maxi;
	mini = 2000009;
	maxi = 0;
	scanf("%lld",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&v[i]);
	}
	sort(v,v+n);
	long long lo = 0;
	long long hi = 2000000;
	long long ans = 0, cont, t;
	while(lo != hi){
		long long mid = (lo+hi+1)/2;
		cont = 0;
		t = 0;
		for(int i = 0; i < n; i++)
			if(v[i] % mid == 0){
				cont += v[i]/mid;
				t++;
			} 

		//printf("chutei %d consegui %d\n",mid,cont);

		if(cont*mid > ans && t >= 2){
			lo = mid;
			ans = cont*mid;
		}
		else
			hi=mid-1;
	}
	if(cont*lo > ans && cont >= 2)
		ans = cont*lo;
	
	printf("%lld\n",ans);

}