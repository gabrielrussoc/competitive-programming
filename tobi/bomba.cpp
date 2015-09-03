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

vector<int> adj[1805];
int d[1805];
int s;

void bfs (int j) {
    queue<int> q;
    q.push(j);
    d[j] = 0;
    while(q.size()){
       	int a = q.front();
       	q.pop(); 
       	int k = adj[a].size();
       	for(int i = 0; i < k; i++){
           	int b = adj[a][i];
            if(d[b] > d[a]+1){
                d[b] = d[a]+1;
                q.push(b);
            }
	    }
    }
}

int main(){
    for(int i = 0; i < 1805; i++){
        d[i] = INT_MAX;
    }
    int n,e,m;
    scanf("%d %d %d %d",&n,&e,&s,&m);

    for(int i = 0; i < m; i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        if(t == 0){
            adj[3*a+1].pb(3*b+2);
            adj[3*a+2].pb(3*b);
        }
        else
            adj[3*a].pb(3*b+1);
    }
	bfs(3*e);
    int ans = min(d[3*s],min(d[3*s+1],d[3*s+2]));
	if(ans == INT_MAX) printf("*\n");
	else printf("%d\n",ans);

}
