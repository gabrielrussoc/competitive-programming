#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 400005;
const int modn = 1000000007;

int n;
int head[N], to[2*N], nx[2*N], p[N], vis[N], inp[N];
int es = 2, cont, r;

void dfs(int u, int pe) {
    if(inp[u]) { cont++; r == -1 ? r = to[pe^1], p[r] = r : p[to[pe^1]] = r; return; }
    if(vis[u]) return;
    vis[u] = 1;
    inp[u] = 1;
    for(int e = head[u]; e; e = nx[e]) {
        if((e^1) == pe) continue;
        dfs(to[e],e);
    }
    inp[u] = 0;
}


int main() {
    scanf("%d",&n);
    r = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]); p[i]--;
        if(i == p[i]) { r = i; continue; }
        to[es] = p[i]; nx[es] = head[i]; head[i] = es++;
        to[es] = i; nx[es] = head[p[i]]; head[p[i]] = es++;
    }
    for(int i = 0; i < n; i++) if(!vis[i]) { dfs(i, 0); }
    for(int i = 0; i < n; i++) if(p[i] == i && i != r) { p[i] = r; cont++; }
    printf("%d\n",cont);
    for(int i = 0; i < n; i++) printf("%d ",p[i]+1);
    putchar('\n');
}

