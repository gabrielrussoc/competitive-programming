#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	
	int x,y,a,b;
	int anx[10004];
	int any[10004];
	int ans = 0;

	scanf("%d %d %d %d",&x,&y,&a,&b);

	for(int i = a; i <= x; i++){
		for(int j = b; j <= min(y,i-1); j++){
			anx[ans] = i;
			any[ans] = j;
			ans++;
		}
	}

	printf("%d\n",ans);
	for(int i = 0 ; i < ans; i++)
		printf("%d %d\n",anx[i],any[i]);


}