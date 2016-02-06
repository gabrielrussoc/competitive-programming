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
const int N = 505;
const int modn = 1000000007;

int adj[N][N], g[N];
char cor[N];
int n,m,u,v;

bool check(){
    for(int u = 0; u < n; u++)
        for(int v = u+1; v < n; v++){
            if(abs(cor[u]-cor[v]) <= 1){
                if(!adj[u][v]) return false;
            }
            else
                if(adj[u][v]) return false;
        }
    cor[n] = 0;
    printf("Yes\n%s\n",cor);
    return true;
}

bool solve (){
    for(int u = 0; u < n; u++) if(g[u] == n-1) cor[u] = 'b';        
    for(int u = 0; u < n; u++) 
        if(!cor[u]) {
            cor[u] = 'a';
            for(int v = 0; v < n; v++)
                if(adj[u][v] && !cor[v]) cor[v] = 'a';
            break;
        }
    for(int u = 0; u < n; u++) if(!cor[u]) cor[u] = 'c';
    return check();
}

int main() {
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d",&u,&v);
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
        g[u]++; g[v]++;
    }
    if(solve()) return 0;
    puts("No");
}

