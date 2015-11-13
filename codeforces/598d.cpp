#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-8;
const int inf = INT_MAX;
const int modn = 1000000007;

//////////////0123456789
const int N = 1005;

int g[N][N];
int d[N][N] = {0};
int nx[] = {1,-1,0,0};
int ny[] = {0,0,1,-1};
int quant[N*N];

void dfs(int i, int j,int c){
    if(d[i][j]) return;
    d[i][j] = c;
    for(int k = 0; k < 4; k++)
        if(g[i+nx[k]][j+ny[k]] != '*'){
            dfs(i+nx[k],j+ny[k],c);
        }
}

int main(){
    memset(d,0,sizeof d);
    int m,n,k;
    
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf(" %c",&g[i][j]);
    
    int x = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] != '*' && !d[i][j]) dfs(i,j,x++);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(g[i][j] != '*'){
                for(int p = 0; p < 4; p++)
                    quant[d[i][j]] += (g[i+nx[p]][j+ny[p]] == '*');
            }
        }
    for(int i = 0; i < k; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--, b--;
        printf("%d\n",quant[d[a][b]]);
    }
}

