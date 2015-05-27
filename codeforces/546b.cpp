#include <cstdio>
#include <algorithm>
#define MAX 10000

int main(){
	
	int n,v[MAX];

	scanf("%d",&n);
	int a, ans = 0;

	for(int i = 0; i < MAX; i++)
		v[i] = 0;

	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		 v[a]++;
		 if(v[a] > 1){
		 	v[a]--;
		 	while(v[a] != 0){
		 		a++;
		 		ans++;
		 	}
		 	v[a]++;
		 }
	}

	printf("%d\n",ans);

	return 0;
}