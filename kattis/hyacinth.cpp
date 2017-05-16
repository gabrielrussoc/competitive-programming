#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 10004;
int n;
vector<int> adj[N];
int ans[N][2];
int f = 1;

void color(int u, int p) {
    if(!ans[u][0]) ans[u][0] = f++;
    if(!ans[u][1]) ans[u][1] = f++;
    int q = adj[u].size();
    for(int i = 0; i < q; i++) {
        int v = adj[u][i];
        if(v != p) {
            if(p != -1) ans[v][0] = ans[u][1];
            else ans[v][0] = ans[u][i < (q/2)];
            color(v, u);
        }
    }
}


int main() {
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    color(0, -1);
    if(n == 2) ans[1][1] = ans[0][1];
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
}
