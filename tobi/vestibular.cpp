#include <cstdio>

int main(){
	
	int n;
	char v[85], c;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf(" %c",&v[i]);
	int ans = 0;
	for(int i = 0; i < n; i++){
		scanf(" %c",&c);
		if(v[i] == c)
			ans++;
	}
	printf("%d\n",ans);


}