#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define MAXN 4005
#define ff first
#define ss second

using namespace std;

vector<pii> e;
int g[MAXN][MAXN];
int q[MAXN];
int n,m;

int main(){
    
    scanf("%d %d",&n,&m);
    memset(g,0,sizeof g);
    memset(q,0,sizeof q);
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        e.pb(mp(a,b));
        g[a][b] = g[b][a] = 1;
        q[a]++;
        q[b]++;
    }
    int k = e.size();
    int mini = INT_MAX;
    for(int i = 0; i < k; i++){
        for(int j = 1; j <= n; j++){
            if(j != e[i].ff && j != e[i].ss && g[j][e[i].ff] && g[j][e[i].ss])
                mini = min(q[j] + q[e[i].ff] + q[e[i].ss]-6, mini);
        } 
    }
    if(mini == INT_MAX)
        printf("-1\n");
    else
        printf("%d\n",mini);

}
