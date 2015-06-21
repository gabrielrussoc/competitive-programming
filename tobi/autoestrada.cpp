#include <cstdio>

int main(){
	
	int n;
	char c;

	scanf("%d",&n);

	int ans = 0;
	while(n--){
		scanf(" %c",&c);
		if(c == 'P' || c == 'C')
			ans += 2;
		else if(c == 'A')
			ans++;
	}

	printf("%d\n",ans);

}