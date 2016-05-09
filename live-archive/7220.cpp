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
const int N = 10004;
const int modn = 1000000007;

int t, n, m, sum;
pii a, b;
char g[105][105];
int d[105][105][12];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int peso(int i, int j) {
    if(g[i][j] == 'B' || g[i][j] == 'A') return 0;
    return g[i][j]-'0';
}

bool isval(int i, int j){
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    if(g[i][j] == '0') return false;
    return true;
}

struct triple {
    int i, j, k;
    triple () {}
    triple (int a, int b, int c) : i(a), j(b), k(c) {}
    bool operator < (triple o) const {
        return k < o.k;
    }
};
typedef pair<int, triple> pit;

void solve(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 10; k++)
                d[i][j][k] = inf;
    d[a.ff][a.ss][0] = 0;
    priority_queue<pit> pq;
    pq.push(pit(0,triple(a.ff,a.ss,0)));
    while(!pq.empty()){
        triple aux = pq.top().ss;
        pq.pop();
        int i = aux.i;
        int j = aux.j;
        int h = aux.k;
        for(int k = 0; k < 4; k++) {
            if(!isval(i+dx[k],j+dy[k])) continue;
            int r = max(h, peso(i+dx[k],j+dy[k]));
            if(d[i+dx[k]][j+dy[k]][r] > d[i][j][h] + peso(i+dx[k],j+dy[k])){
                d[i+dx[k]][j+dy[k]][r] = d[i][j][h] + peso(i+dx[k],j+dy[k]);
                pq.push(pit(-d[i+dx[k]][j+dy[k]][r],triple(i+dx[k],j+dy[k],r)));
            }  
        }
    }
}

int main() {
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d %d",&n, &m);
        sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf(" %c",&g[i][j]);
                if(g[i][j] == 'A') a = pii(i,j);
                else if(g[i][j] == 'B') b = pii(i,j);
                else sum += g[i][j] - '0';
            }
        }
        int ans = sum;
        solve();
        for(int i = 0; i < 10; i++) 
            if(d[b.ff][b.ss][i] != inf)
                ans = min(ans,d[b.ff][b.ss][i]-i);
        printf("Case #%d: %d\n",tc,sum-ans);

    }
}

