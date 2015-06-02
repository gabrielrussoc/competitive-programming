#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#define pb push_back

using namespace std;

int main(){
	
	queue<int> q;
	vector<int> adj[33000];
	int p[33000];
	int r[33000];
	int t;

	scanf("%d",&t);

	while(t){

		int n, k;
		scanf("%d %d",&n,&k);
		int f;

		for(int i = 1; i <= (1 << n); i++){
			scanf("%d",&f);
			q.push(i);
			p[i] = r[i] = f;
		}

		for(int i = 0; i <= (1 << n); i++)
			adj[i].clear();

		while(q.size() > 1){

			int i1, i2;

			i1 = q.front();
			q.pop();
			i2 = q.front();
			q.pop();


			if(p[i1] == p[i2]){
				int y = min(i1,i2);
				p[y] = min(r[y],k);
				q.push(y);
				adj[y].pb(max(i1,i2));
			}
			else {
				int a, b;
				if(p[i1] > p[i2]){
					a = i1;
					b = i2;
				}
				else {
					a = i2;
					b = i1;
				}
				
				p[a] = min(r[a],p[a] - p[b] + k);
				q.push(a);
				adj[a].pb(b);

			}


		}
		

		int ans = q.front();
		printf("%d\n",ans);

		for(int i = 0; i < n; i++)
			printf("%d%c",adj[ans][i],i == n - 1 ? '\n' : ' ');

		q.pop();
		t--;
	}

}