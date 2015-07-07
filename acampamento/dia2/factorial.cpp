#include <cstdio>

using namespace std;

int main(){

	int k,n,t;
	scanf("%d",&t);
	
	for(int i = 0; i < t; i++){
		scanf("%d",&n);
		int ans = 0;		
		for(int k = 5; k <= n; k *= 5)
			ans += n/k;
		printf("%d\n",ans);
	}


}
