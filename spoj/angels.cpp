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
int t, lx[N][N], ly[N][N], k, turn;

void labelx(int i, int j){
    if(j >= n || g[i][j] != 'H' || visx[i][j] == turn) return;
    visx[i][j] = turn;
    lx[i][j] = k;
    labelx(i, j+1);
}

void labelu(int i, int j){
    if(i >= n || g[i][j] != 'H' || visy[i][j] == turn) return;
    visy[i][j] = turn;
    ly[i][j] = k;
    labely(i+1, j);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        ++turn;
        k = 0;
        scanf("%d %d", &x, &y);
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++) {
                scanf(" %c",&g[i][j]);
                adj[i*x+y].clear();
            }

        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++){
                labelx(i,j), labely(i,j);
                if(g[i][j] != 'H') {
                    adj[lx[i][j]].pb(ly[i][j]); 
                    adj[ly[i][j]].pb(lx[i][j]); 
                }
            }
        for(int i = 0; i < k; i++) {
            if(dfs(i)) ans++;
        }
    }
}

