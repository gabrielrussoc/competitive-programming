#include <cstdio>
#include <algorithm>

using namespace std;

int v[105][105];
int m[105][105] = {-1};
int h,w;

int pd(int i, int j){

	if(i == w) return 0;
	if(j == -1 || j == h) return 0;

	if(m[i][j] != -1) return m[i][j];



	return max(max(r1,r2),r3);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&h,&w);
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
				scanf("%d",&v[i][j]);

		int ans = 0;
		for(int i = 0; i < w; i++){
			int k = pd(0,i);
			if(k > ans)
				ans = k;
		}
		printf("%d\n",ans);
	}

	
}