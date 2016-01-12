#include <bits/stdc++.h>
#define pb push_back
typedef int node;
typedef int edge;
using namespace std;

const int N = 1003;
int turn, es, n, u, v, k;
int m[N][N];

int tim = 0;
int visited[N], disc[N], low[N], parent[N];
int head[N], to[N*N], nx[N*N];
vector<int> bridges;

void get_bridges(node u){
    visited[u] = true;
    disc[u] = low[u] = tim++;
    for(edge e = head[u]; e; e = nx[e]){
        node v = to[e];
        if(!visited[v]){
            parent[v] = u;
            get_bridges(v);
            low[u] = min(low[u],low[v]);
            if(low[v] > disc[u]) bridges.pb(e);
        } else if (v != parent[u]) low[u] = min(low[u], disc[v]);
    }
}

bool comp(int a, int b){
    if(to[a^1] == to[b^1]) return to[a] < to[b];
    return to[a^1] < to[b^1];
}

int main(){
    while(scanf("%d",&n) != EOF){
        turn++;
        bridges.clear();
        es = 2;
        tim = 0;
        memset(head,0,sizeof head);
        for(int i = 0; i < n; i++){
            scanf("%d (%d)",&u,&k);
            parent[u] = visited[u] = 0;
            for(int j = 0; j < k; j++){
                scanf("%d",&v);
                if(m[u][v] != turn){
                    to[es] = v; nx[es] = head[u]; head[u] = es++;
                    to[es] = u; nx[es] = head[v]; head[v] = es++;
                }
                m[u][v] = m[v][u] = turn;
            }
        }
        for(int i = 0; i < n; i++) if(!visited[i]) get_bridges(i);
        int ans = bridges.size();
        for(int i = 0; i < ans; i++) {
            int a = to[bridges[i]^1], b = to[bridges[i]];
            if(a>b)bridges[i]^=1;
        }
        printf("%d critical links\n",ans);
        sort(bridges.begin(),bridges.end(),comp);
        for(int i = 0; i < ans; i++){
            int a = to[bridges[i]^1], b = to[bridges[i]];
            printf("%d - %d\n",a,b);
        }
        printf("\n");
    }
}
