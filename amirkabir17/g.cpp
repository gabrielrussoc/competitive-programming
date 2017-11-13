#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n, a, r, pr[N], sz[N];
vector<int> adj[N];

void dfs(int u, int p = -1) {
    pr[u] = p;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    sz[u]++;
}


int main() {
    scanf("%d %d %d", &n, &a, &r);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(a);
    int u = r;
    vector<int> path;
    while(pr[u] != -1) {
        path.pb(u); 
        u = pr[u];
    }
    path.pb(u);
    reverse(path.begin(), path.end());
    int k = path.size();
    /* for(int x : path) printf("%d ", x); */
    /* puts(""); */
    int m = k / 2;
    for(int i = 0; i < n; i++) sz[i] = 0;
    dfs(path[m]);

    int ba = -1, br = -1;
    if(m-1 >= 0) ba = path[m-1];
    if(m+1 < k) br = path[m+1];

    int ans[2];
    ans[0] = ba == -1 ? 0 : sz[ba];
    ans[1] = br == -1 ? 0 : sz[br];
    int turn = !(k&1);
    vector<int> szor;
    for(int v : adj[path[m]]) {
        if(v == ba || v == br) continue;
        szor.pb(sz[v]);
    }
    sort(szor.begin(), szor.end(), greater<int>());
    for(int s : szor) {
        ans[turn] += s;
        turn ^= 1;
    }
    printf("%d %d\n", ans[0], ans[1]);
}

