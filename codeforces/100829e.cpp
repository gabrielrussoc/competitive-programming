#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1123456;
int n, turn, vis[N];
map<int, vector<int>> m;
vector<int> adj[N];

void dfs(int u) {
    vis[u] = turn;
    for(int v : adj[u])
        if(vis[v] != turn)
            dfs(v);
}

int main() {
    while(scanf("%d",&n) && n != 0) {
        m.clear();
        turn++;
        for(int i = 0; i < n; i++) adj[i].clear();

        for(int pos = 0; pos < n; pos++) {
            int val;
            scanf("%d", &val);
            int goal = pos - val;
            int u = pos;
            for(int v : m[goal]) {
                adj[u].pb(v);
                adj[v].pb(u);
            }
            m[pos+val].pb(u);
        }
        dfs(0);
        for(int u = n-1; u >= 0; u--)
            if(vis[u] == turn) {
                printf("%d\n", u);
                break;
            }
    }
}