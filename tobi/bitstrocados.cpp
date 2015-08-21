#include <cstdio>

using namespace std;

int main(){

	int v, tc = 1;
	while(scanf("%d",&v), v != 0) {
		int n50, n10, n5;
		n50 = v/50;
		v %= 50;
		n10 = v/10;
		v %= 10;
		n5 = v/5;
		v %= 5;
		printf("Teste %d\n%d %d %d %d\n\n",tc++,n50,n10,n5,v);
	}


}
