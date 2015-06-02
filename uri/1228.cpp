#include <cstdio>

#define N 30

int main(){
	
	int l[N], c[N], n, aux[N];

	while(scanf("%d",&n) != EOF){

		for(int i  = 1; i <= n; i++)
			scanf("%d",&l[i]);

		for(int i  = 1; i <= n; i++)
			scanf("%d",&c[i]);

		for(int i = 1; i <= n; i++)
			aux[c[i]] = i;


		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < n; j++){
				if(aux[l[j]] > aux[l[j+1]]){
					int s;
					s = l[j];
					l[j] = l[j+1];
					l[j+1] = s;
					ans++;
				}
			}
		}

		printf("%d\n",ans);

	}

}