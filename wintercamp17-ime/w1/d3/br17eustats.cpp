#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
#define snd second
#define fst first
typedef long long ll;

const int MAXN = 312345;

int n, m;
vector<pii> s;

vector<int> tree[4*MAXN];
vector<int> px, vx;

int res[MAXN];

void join(int a, int u, int v){
    int i = 0, j = 0;
    while(i < tree[u].size() && j < tree[v].size()){
        if(tree[u][i] < tree[v][j])
            tree[a].pb(tree[u][i++]);
        else
            tree[a].pb(tree[v][j++]);
    }
    while(i < tree[u].size())
        tree[a].pb(tree[u][i++]);
    while(j < tree[v].size())
        tree[a].pb(tree[v][j++]);
}

void build(int idx, int i, int j){
    if( i == j ){
        tree[idx].pb(s[i].snd);
        return ; 
    }
    int m = (i+j)/2;
    build(idx*2, i, m);
    build(idx*2+1, m+1, j);
    join(idx, idx*2, idx*2+1);
}

int qry(int idx, int i, int j, int l, int r, int x){
    if(i > r || j < l) return 0;
    if(i >= l && j <= r){
        int u = upper_bound(tree[idx].begin(), tree[idx].end(), x) - tree[idx].begin();
        return max(0, u);
    }
    int m = (i+j)/2;
    return qry(idx*2, i, m, l, r, x) + qry(idx*2+1, m+1, j, l, r, x);
}

int main() {
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        int u, v;
        scanf("%d%d", &u, &v); 
        s.push_back(pii(u, v));
    }
    sort(s.begin(), s.end());
    for(int a=0;a<n;a++){
        px.pb(s[a].fst);
        vx.pb(s[a].snd);
    }
    build(1, 0, n-1);
    scanf("%d", &m);
    for(int a=0;a<m;a++){
        int i, j, l, r;
        scanf("%d %d %d %d", &i, &j, &l, &r);
        if(a > 3)
            i ^= res[a-4];
        if(a > 2)
            j ^= res[a-3];
        if(a > 1)
            l ^= res[a-2];
        if(a > 0)
            r ^= res[a-1];
        if(i > j)
            swap(i, j);
        if(l > r)
            swap(l, r);

        int ii = lower_bound(px.begin(), px.end(), i) - px.begin();
        int jj = upper_bound(px.begin(), px.end(), j) - px.begin() - 1;
        if(ii > jj){
            res[a] = 0;
            puts("0");
            continue;
        }
        res[a] = qry(1, 0, n-1, ii, jj, r) - qry(1, 0, n-1, ii, jj, l-1);
        printf("%d\n", res[a]);
    }
}

