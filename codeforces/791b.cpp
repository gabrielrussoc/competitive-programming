#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 150007;
int uf[N], wf[N], g[N];

int find(int u) {
    if(u == uf[u]) return u;
    return uf[u] = find(uf[u]);
}

void join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(wf[u] > wf[v]) swap(u,v);
    uf[u] = uf[v];
    wf[v] += wf[u];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        uf[i] = i;
        wf[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v); u--; v--;
        g[u]++;
        g[v]++;
        join(u,v);
    }
    for(int i = 0; i < n; i++) {
        int k = wf[find(i)];
        if(k - 1 != g[i]) {
            puts("NO");
            return 0;
        } 
    }
    puts("YES");
}

