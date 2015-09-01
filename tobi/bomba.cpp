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

vector<int> adj[505];
pii d[505];
map<pii,bool> f;

void bfs (int j) {
    queue<int> q;
    q.push(j);
    d[j].ff = d[j].ss = 0;

    while(q.size()){
       int p = q.front();
       q.pop(); 
       int k = adj[j].size();
       for(int i = 0; i < k; i++){
           if(f[mp(p,adj[p][i])] && d[adj[p][i]].ff > d[p].ff +1){
              q.push(i); 
              d[i].ff = d[p].ff + 1;
           }
           if(f[mp(p,adj[p][i])] && d[adj[p][i]].ss > d[p].ss +1){
              q.push(i); 
              d[i].ss = d[p].ss + 1;
           }
       }
    }
}

int main(){
    for(int i = 0; i < 505; i++){
        d[i].ff = d[i].ss = INT_MAX;
    }
    int n,e,s,m;
    scanf("%d %d %d %d",&n,&e,&s,&m);

    for(int i = 0; i < m; i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        adj[a].pb(b);
        f[mp(a,b)] = t;
    }

}
