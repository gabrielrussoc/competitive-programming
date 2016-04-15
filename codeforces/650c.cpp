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
const int N = 1000006;
const int modn = 1000000007;

vector<int> l[N], c[N], adj[N];
int n, m, gr[N], dist[N], v[N], uf[N], wf[N];

int d (int i, int j) { return m*i + j; }

int find (int i) {
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j) {
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

void topo() {
    stack<int> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int idx = d(i,j);
            if(uf[idx] != idx) continue;
            idx = find(idx);
            if(!gr[idx]) { 
                s.push(idx);
                dist[idx] = 1;
            }
        }

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int v : adj[u]) {
            gr[v]--;
            if(!gr[v]) s.push(v);
            dist[v] = max(dist[v], dist[u]+1);
        }
    }
}

bool comp (int i, int j) { return v[i] < v[j]; }

int main() {
    scanf("%d %d",&n,&m);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int idx = d(i,j);
            scanf("%d",&v[idx]);
            l[i].pb(idx);
            c[j].pb(idx);
            uf[idx] = idx;
            wf[idx] = 1;
        }
    }

    for(int i = 0; i < n; i++) sort(l[i].begin(), l[i].end(), comp);
    for(int i = 0; i < m; i++) sort(c[i].begin(), c[i].end(), comp);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int a = l[i][j-1], b = l[i][j];
            if (v[a] == v[b]) join (a,b);
        }
    }
    
    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            int a = c[j][i-1], b = c[j][i];
            if (v[a] == v[b]) join (a,b);
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            int a = find(l[i][j-1]), b = find(l[i][j]);
            if (a == b) continue;
            adj[a].pb(b);
            gr[b]++;
        }
    }
    
    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            int a = find(c[j][i-1]), b = find(c[j][i]);
            if (a == b) continue;
            adj[a].pb(b);
            gr[b]++;
        }
    }

    topo();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ",dist[find(d(i,j))]);
        printf("\n");
    }

}

