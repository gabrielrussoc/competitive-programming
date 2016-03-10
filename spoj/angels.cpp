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
const int N = 304;
const int modn = 1000000007;

char g[N][N];
int t, lx[N][N], ly[N][N], k, turn, x, y;
vector<int> adj[N*N];
int vis[N*N], M[N*N], visy[N][N], visx[N][N];

int dfs (int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for (int v : adj[u])
        if(M[v] == -1 || dfs(M[v])) {
            M[u] = v;
            M[v] = u;
            return 1;
        }
    return 0;
}

void labelx(int i, int j){
    if(j >= y || g[i][j] == 'A') return;
    visx[i][j] = turn;
    lx[i][j] = k;
    labelx(i, j+1);
}

void labely(int i, int j){
    if(i >= x || g[i][j] == 'A') return;
    visy[i][j] = turn;
    ly[i][j] = k;
    labely(i+1, j);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        ++turn;
        memset(M, -1, sizeof M);
        k = 0;
        scanf("%d %d", &x, &y);
        int n = max(x,y);
        for(int i = 0; i < n*n; i++) adj[i].clear();
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++) 
                scanf(" %c",&g[i][j]);

        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++){
                if(g[i][j] == 'H'){
                    if(visx[i][j] != turn)
                        labelx(i,j), k++;
                }
            }
        int a = k;
        
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++){
                if(g[i][j] == 'H'){
                    if(visy[i][j] != turn)
                        labely(i,j), k++;
                    adj[lx[i][j]].pb(ly[i][j]);
                    adj[ly[i][j]].pb(lx[i][j]);
                }
            }

        int ans = 0;
        for(int i = 0; i < a; i++){
            memset(vis,0,sizeof vis);
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
}

