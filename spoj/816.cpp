#include <cstdio>
#include <algorithm>
#define MAX 1005

using namespace std;

bool compare(int i, int j){ return !(i<j); }

int main(){
	
	int v[MAX], n, x, y, tot,t;
	t = 1;
	
	while(scanf("%d %d %d",&x,&y,&n) && x){

		tot = x+y;
		int tesouro = 0;
		for(int i = 0; i < n; i++){
			scanf("%d",&v[i]);
			tot += v[i];
			tesouro += v[i];
		}

		printf("Teste %d\n",t);
		if(tot % 2 != 0)
			printf("N\n\n");

		else{
			sort(v,v + n,compare);
			int obj = tot/2;
			int j;
			
			for(j = 0; j < n; j++){
				int res = v[j];
				for(int k = 0; k < n; k++){
					if(k != j && res + v[k] + x <= obj)
						res += v[k];
				}
				if(res + x == obj){
					printf("S\n\n");
					break;
				}
			}
			if(j == n) {
				for(j = 0; j < n; j++){
					int res = v[j];
					for(int k = 0; k < n; k++){
						if(k != j && res + v[k] + y <= obj)
							res += v[k];
					}
					if(res + y == obj){
						printf("S\n\n");
						break;
					}
				}
				if(j == n)
					printf("N\n\n");
			}
		}
		t++;
	}

	return 0;
}