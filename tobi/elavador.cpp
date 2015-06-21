#include <cstdio>

int main(){
	
	int n, c;
	scanf("%d %d",&n,&c);
	int p = 0;
	int flag = 0;
	while(n--){
		int e,s;
		scanf("%d %d",&s,&e);
		p = p + e - s;
		if(p > c)
			flag = 1;
	}
	if(flag)
		printf("S\n");
	else
		printf("N\n");
}

