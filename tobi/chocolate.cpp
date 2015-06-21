#include <cstdio>

int main(){
	
	int l;
	scanf("%d",&l);

	int ans = 1;
	while(l >= 2){
		l /= 2;
		ans *= 4;
	}

	printf("%d\n",ans);
}