#include <cstdio>

int main(){
	
	int a, ans = 0;

	while(scanf("%d",&a) && a != 0){
		if(a > ans)
			ans = a;
	}
	printf("%d\n",ans);
}

