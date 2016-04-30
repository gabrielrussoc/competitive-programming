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
const int N = 3003;
const int modn = 1000000007;

int d[N][N];
int dd[N];
vector<int> ad[N];
int us[N];
int best[N][4], bestr[N][4];
int n, m;

void pre() {
    for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) dd[v] = inf;
        dd[u] = 0;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int w : ad[v]){
                if(dd[w] > dd[v] + 1) {
                    dd[w] = dd[v] + 1;
                    q.push(w);
                }
            }
        }
        for(int v = 0; v < n; v++)
            d[u][v] = dd[v];
    }
    for(int u = 0; u < n; u++) {
        int maxi, w;
        for(int v = 0; v < n; v++) us[v] = 0;
        for(int i = 0; i < 3; i++) {
            maxi = 0; w = -1;
            for(int v = 0; v < n; v++)
                if(d[u][v] != inf && !us[v])
                    if(d[u][v] > maxi) maxi = d[u][v], w = v;
            best[u][i] = w; 
            if(w != -1) us[w] = 1;
        }
        for(int v = 0; v < n; v++) us[v] = 0;
        for(int i = 0; i < 3; i++) {
            maxi = 0; w = -1;
            for(int v = 0; v < n; v++)
                if(d[v][u] != inf && !us[v])
                    if(d[v][u] > maxi) maxi = d[v][u], w = v;
            bestr[u][i] = w; 
            if(w != -1) us[w] = 1;
        }
    }
}

bool can(int a, int b, int c, int d) {
    if(a == -1 || b == -1 || c == -1 || d == -1) return false;
    if(a == b || a == c || a == d) return false;
    if(b == c || b == d) return false;
    if(c == d) return false;
    return true;
}

void solve() {
    int u1,u2,u3,u4;
    int maxi = 0;
    for (int b = 0; b < n; b++)
        for(int c = 0; c < n; c++) {
            if (b == c || d[b][c] == inf) continue;
            for(int i = 0; i < 3; i++) {
                int a = bestr[b][i];
                for(int j = 0; j < 3; j++) {
                    int f = best[c][j];
                    if (!can(a,b,c,f)) continue;
                    int cost = d[a][b] + d[b][c] + d[c][f];
                    if(cost > maxi) {
                        maxi = cost;
                        u1 = a; u2 = b; u3 = c; u4 = f;
                    }
                }
            }
        } 

    printf("%d %d %d %d\n",u1+1,u2+1,u3+1,u4+1);
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        ad[u].pb(v);
    }
    pre();
    solve();
}

