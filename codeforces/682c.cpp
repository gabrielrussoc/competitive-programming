#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define vert first
#define wei second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 100005;
const int modn = 1000000007;

int a[N], sz[N];
int n,p,c;
vector<pii> adj[N];
int ans;

void dfs(int u, ll s, bool russoburro) {
    if(a[u] < s) russoburro = true;
    ans += russoburro;
    for(pii v : adj[u]) dfs(v.vert, max(0ll,s+ll(v.wei)),russoburro);
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d",&p,&c); p--;
        adj[p].pb(pii(i+1,c));
    }
    dfs(0,0,false);
    printf("%d\n",ans);
}

