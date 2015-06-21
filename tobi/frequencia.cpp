#include <cstdio>

int main(){
	
	int v[1000007] = {0};

	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		if(!v[a]){
			v[a]++;
			ans++;
		}
	}
	printf("%d\n",ans);

}