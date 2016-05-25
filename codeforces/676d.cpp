#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define end uashe
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1003;
const int modn = 1000000007;

char g[N][N];
int n, m;
int door[N][N];
vector<int> adj[4*N*N];
int d[4*N*N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
pii st, end;

// top right down left
//  3    2    1    0
int get_door(char c) {
    int ret = 0;
    if(c == '+' || c == '|' || c == '^' || c == 'L' || c == 'R' || c == 'D')
        ret |= (1<<3);
    if(c == '+' || c == '|' || c == 'v' || c == 'L' || c == 'R' || c == 'U')
        ret |= (1<<1);
    if(c == '+' || c == '-' || c == '<' || c == 'R' || c == 'U' || c == 'D')
        ret |= (1<<0);
    if(c == '+' || c == '-' || c == '>' || c == 'L' || c == 'U' || c == 'D')
        ret |= (1<<2);
    return ret;
}

bool has_door (int i1, int j1, int i2, int j2, int k) {
    int a = door[i1][j1];
    int b = door[i2][j2];
    int c;
    for(int i = 0; i < k; i++) {
        c = 1 & a;
        c <<= 3;
        a = (a>>1) | c;
        c = 1 & b;
        c <<= 3;
        b = (b>>1) | c;
    }
    int p, q;
    //top-down
    if(i1 < i2) { //a/b
        p = a & (1<<1);
        q = b & (1<<3);
        return p && q;
    } else if (i1 > i2) { //b/a
        p = a & (1<<3);
        q = b & (1<<1);
        return p && q;
    }

    //left-right
    if(j1 < j2) { //a-b
        p = a & (1<<2);
        q = b & (1<<0);
        return p && q;
    } else if (j1 > j2) { //b-a
        p = a & (1<<0);
        q = b & (1<<2);
        return p && q;
    }

    return false;
}

bool isval(int i, int j) {
    if(i < 0 || i >= n) return false;
    if(j < 0 || j >= m) return false;
    return true;
}

int uni(int i, int j, int k) {
    return 4*(i*m + j) + k;
}

void solve () {
    for(int i = 0; i < 4*n*m; i++) d[i] = inf;
    queue<int> q;
    q.push(uni(st.ff,st.ss,0));
    d[uni(st.ff,st.ss,0)] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();       
        for(int v : adj[u]) {
            if(d[v] > d[u] + 1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            scanf(" %c",&g[i][j]);
            door[i][j] = get_door(g[i][j]);
        }

    int a, b;
    scanf("%d %d",&a,&b); a--; b--;
    st = pii(a,b);
    scanf("%d %d",&a,&b); a--; b--;
    end = pii(a,b);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            for(int p = 0; p < 4; p++) {//myself
                int u = uni(i,j,p);
                int v = uni(i,j,(p+1)%4);
                adj[u].pb(v);
                adj[v].pb(u);
            }
            for(int k = 0; k < 4; k++){ //neighbours
                if(!isval(i+dx[k], j+dy[k])) continue;
                for(int l = 0; l < 4; l++){ //rings
                    if(has_door(i,j,i+dx[k], j + dy[k], l)) {
                        int u = uni(i,j,l);
                        int v = uni(i+dx[k], j + dy[k], l);
                        adj[u].pb(v);
                        adj[v].pb(u);
                    }
                }
            }
        }
    }
    solve();
    int ans = inf;
    for(int i = 0; i < 4; i++) ans = min(ans, d[uni(end.ff,end.ss,i)]);
    if(ans == inf) ans = -1;
    printf("%d\n",ans);

}

