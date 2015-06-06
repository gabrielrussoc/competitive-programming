#include <cstdio>
#include <algorithm>

#define MAXN 100009

using namespace std;

int v[MAXN];
int n;

int main(){

	while(scanf("%d",&n) != EOF){ 

		for(int i = 0; i < n; i++)
			scanf("%d",&v[i]);

		for(int i = 1; i < n; i++)
			v[i] += v[i-1];

		int tgt = v[n-1];

		if(tgt % 3 != 0){
			printf("0\n");
			continue;
		}
		

		tgt = tgt/3;
		int cont = 0;
		
		for(int i = 0; i < n; i++){
			bool ans, ans1;
			ans = binary_search(v,v+n,v[i] + tgt);
			ans1 = binary_search(v,v+n,v[i] + 2*tgt);
			if(ans && ans1)
				cont++;
		}
		printf("%d\n",cont);
	}

}