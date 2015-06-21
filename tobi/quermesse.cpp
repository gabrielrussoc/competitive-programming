#include <cstdio>

int main(){
	
	int n, t = 1;
	while(scanf("%d",&n) && n != 0){
		int a;
		for(int i = 0; i < n; i++){
			scanf("%d",&a);
			if(i == a-1){
				printf("Teste %d\n%d\n\n",t++,a);
			}
		}
	}


}