#include <cstdio>

int main(){
	
	int n,tc = 1;
	while(scanf("%d",&n) && n != 0){
		printf("Teste %d\n%d\n\n",tc++,(1 << n) -1);
	}
}