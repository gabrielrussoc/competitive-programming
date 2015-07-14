#include <cstdio>
#include <algorithm>

using namespace std;

int v[1004][2];
int d[1000005];

int main(){

	int t;
	scanf("%d",&t);
	int k = 1;
	while(k <= t){
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
			scanf("%d %d",&v[i][0], &v[i][1]);

		int p = 0;
		for(int i = 0; i < n - 1; i++){
			for(int j = i; j < n; j++){
				d[p++] = (v[j][0] - v[i][0])*(v[j][0] - v[i][0])
				 + (v[j][1]-v[i][1])*(v[j][1]-v[i][1]);
			}
		}

		sort(d,d+p);

		int ant = -1;
		int ans = 0;
		for(int i = 0; i < p; i++){
			if(d[i] != ant){
				ans++;
				ant = d[i];
			}
		}
		printf("Case %d: %d\n",k++,ans);
	}

	
}