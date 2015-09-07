#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#define pb push_back

using namespace std;

vector<int> adj[1000006];
int d[1000006];
int n;
int maxi, ind;

void preenche(){
    for(int i = 1; i <= n; i++)
        d[i] = INT_MAX;
}

void bfs(int j){
    queue<int> q;
    q.push(j);
    d[j] = maxi = 0;
    int at, nxt;
    while(q.size()){
        at = q.front();
        if(d[at] > maxi){
            maxi = d[at];
            ind = at;
        }
        q.pop();
        int k = adj[at].size();
        for(int i = 0; i < k; i++){
            nxt = adj[at][i];
            if(d[nxt] > d[at] + 1){
                d[nxt] = d[at]+1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    int a,b;
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d",&a,&b);
        d[i+1] = INT_MAX;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    d[n] = INT_MAX;
    bfs(1);
    preenche();
    bfs(ind);
    printf("%d\n",maxi);     
}
