#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int v[105][105];
int m[105][105];
int h,w;

int pd(int i, int j){

	if(j == -1 || j == w) return 0;
	if(i == h-1) return v[i][j];

	if(m[i][j] != -1) return m[i][j];

	m[i][j] = v[i][j] + max(max(pd(i+1,j),pd(i+1,j+1)),pd(i+1,j-1));
	return m[i][j];
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(m,-1,sizeof m);
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