#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>
#include <map>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

vector<pii> adj[505];
int d[505];
int f[505][505];
int s, cont = 0;

void bfs (int j) {
    queue<int> q;
    q.push(j);
    d[j] = 0;
    while(q.size()){
       	int a = q.front();
		if (a == s) break;
       	q.pop(); 
       	int k = adj[a].size();
       	for(int i = 0; i < k; i++){
           	int b,c;
           	b = adj[a][i].ff;
		   	c = adj[a][i].ss;
			if(d[a]%3 == 0 && c){
				if(d[b] == INT_MAX || d[b]%3 != (d[a] + 1)%3){
					d[b] = d[a]+1;
					q.push(b);
				}   
			} else if (d[a]%3 && !c){
				if(d[b] == INT_MAX || d[b]%3 != (d[a] + 1)%3){
					d[b] = d[a]+1;
					q.push(b);
				}   
			}
	   }
    }
}

int main(){
    for(int i = 0; i < 505; i++){
        d[i] = INT_MAX;
    }
    int n,e,m;
    scanf("%d %d %d %d",&n,&e,&s,&m);

    for(int i = 0; i < m; i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        adj[a].pb(mp(b,t));
    }
	bfs(e);
	if(d[s] == INT_MAX) printf("*\n");
	else printf("%d\n",d[s]);

}
