#include <cstdio>

using namespace std;

int main(){

	int n,c = 1;
	
	while(scanf("%d",&n) && n != 0){
		int ans = 0, a;
		for(int i = 0; i < n; i++){
			scanf("%d",&a);
			if(a) ans++;
			else ans--;
		}
		printf("Case %d: %d\n",c++,ans);
	}

}
