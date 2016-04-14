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
int n, m, x, gr[N], dist[N], v[N];

int d (int i, int j) { return m*i + j; }

void topo() {
    stack<int> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!gr[d(i,j)]) s.push(d(i,j)), dist[d(i,j)] = 1;

    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int v : adj[u]) {
            gr[v]--;
            if(!gr[v]) {
                s.push(v);
                dist[v] = dist[u]+1;
            }
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
        }
    }

    for(int i = 0; i < n; i++) sort(l[i].begin(), l[i].end(), comp);
    for(int i = 0; i < m; i++) sort(c[i].begin(), c[i].end(), comp);

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(v[l[i][j-1]] != v[l[i][j]]) {
                adj[l[i][j-1]].pb(l[i][j]);
                gr[l[i][j]]++;
            }
        }
    }
    
    for(int j = 0; j < m; j++) {
        for(int i = 1; i < n; i++) {
            if(v[c[j][i-1]] != v[c[j][i]]) {
                adj[c[j][i-1]].pb(c[j][i]);
                gr[c[j][i]]++;
            }
        }
    }

    topo();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ",dist[d(i,j)]);
        printf("\n");
    }
    

}

