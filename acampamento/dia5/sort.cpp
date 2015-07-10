#include <cstdio>

using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	if(n == 1 || n == 2){
		printf("-1\n");
	}
	else{
		for(int i = n; i > 0; i--)
			printf("%d ",i);
		printf("\n");
	}


}