#include <cstdio>

int main(){
	
	int n;
	int v[10004];
	while(scanf("%d",&n) && n != -1){

		int ans = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i]);
			ans += v[i];
		}

		if(ans % n != 0)
			printf("-1\n");
		else {
			ans = ans/n;
			int cont = 0;
			for(int i = 0; i < n; i++){
				if(v[i] < ans)
					cont += ans-v[i];
			}
			printf("%d\n",cont);

		}

	}


}