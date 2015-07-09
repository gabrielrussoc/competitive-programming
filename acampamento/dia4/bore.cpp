#include <cstdio>
#include <cstring>

using namespace std;

int v[100006];

int main(){
	
	int n, max = 0;
	memset(v,0,sizeof v);
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		v[a]++;
		if(a > max)
			max = a;
	}

	int ans = 0;
	while(n){
		for(int i = 1; i <= max; i++){
			if(i*v[i] >= (i-1)*v[i-1] + (i+1)*v[i+1]){
				ans += i*v[i];
				n -= v[i] + v[i+1] + v[i-1];
				v[i] = v[i+1] = v[i-1] = 0;
			}
		}
	}
	printf("%d\n",ans);



}