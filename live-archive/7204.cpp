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
const int N = 105;
const int modn = 1000000007;

int n,q,b,t, turn;
int pai[N][N], vis[2*N], v[2*N], m[2*N];

int dfs(int u){
    if(vis[u]) return 0;
    vis[u] = 1;
    for(int i = 0; i < n; i++){
        if(pai[i][v[u]] == turn){
            if(m[i+b] == -1 || dfs(m[i+b])){
                m[u] = i+b;
                m[i+b] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    while(scanf("%d %d",&n,&q) != EOF) {
        turn++;
        for(int i = 0; i < n; i++) {
            scanf("%d",&b);
            for(int j = 0; j < b; j++){
                scanf("%d",&t);
                pai[i][t] = turn;
            }
            if(b < n) pai[i][0] = turn;
        }
        for(int i = 0; i < q; i++){
            memset(m,-1,sizeof m);
            scanf("%d",&b);
            for(int j = 0; j < b; j++)
                scanf("%d",v+j);
            int ans = 0;
            for(int j = 0; j < b; j++){
                memset(vis,0,sizeof vis);
                if(dfs(j)) ans++;
            }
            if(ans == b){
                bool bla = 1;
                int c = b;
                if(b < n) v[b++] = 0;
                for(int j = 0; j < n; j++){
                    if(m[j+c] == -1){
                        bool ok = 0;
                        for(int k = 0; k < b; k++)
                            if(pai[j][v[k]] == turn) ok = 1;
                        if(!ok) {
                            bla = 0;
                            break;
                        }
                    }
                }
                if(bla)
                    puts("Y");
                else
                    puts("N");
            }
            else puts("N");
        }
    }
}

