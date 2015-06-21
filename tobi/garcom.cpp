#include <cstdio>

int main(){
	
	int n,l,c;
	scanf("%d",&n);
	int ans = 0;
	while(n--){
		scanf("%d %d",&l,&c);
		if(l > c)
			ans += c;
	}
	printf("%d\n",ans);

}