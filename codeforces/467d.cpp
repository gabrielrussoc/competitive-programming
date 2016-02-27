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
const int N = 1000004;
const int modn = 1000000007;

string ss;
char s[N];
pii ans[N];
map<string, int> m;
vector<string> v;
vector<int> adj[N];

int k = 1,n, mm, vis[N];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1; 
    for(int it : adj[u]){
        dfs(it);
        ans[u] = min(ans[u], ans[it]);
    }
}


int main() {
    scanf("%d",&mm);
    for (int i = 0; i < mm; i++){
        scanf(" %s", s);
        for(int j = 0; s[j]; j++) s[j] = tolower(s[j]);
        ss = s;
        if(!m[ss]) {
            m[ss] = k++;
            int cont = 0, j;
            for(j = 0; s[j]; j++) if(s[j] == 'r') cont++;
            ans[k-1] = pii(cont,j);
        }
        v.pb(ss);
    }
    scanf("%d",&n);
    int a,b;
    for(int i = 0; i < n; i++){
        scanf(" %s", s); 
        for(int j = 0; s[j]; j++) s[j] = tolower(s[j]);
        ss = s;
        if(!m[ss]) {
            m[ss] = k++;
            int cont = 0, j;
            for(j = 0; s[j]; j++) if(s[j] == 'r') cont++;
            ans[k-1] = pii(cont,j);
        }
        a = m[ss];
        scanf(" %s", s); 
        for(int j = 0; s[j]; j++) s[j] = tolower(s[j]);
        ss = s;
        if(!m[ss]) {
            m[ss] = k++;
            int cont = 0, j;
            for(j = 0; s[j]; j++) if(s[j] == 'r') cont++;
            ans[k-1] = pii(cont,j);
        }
        b = m[ss];
        adj[a].pb(b);
    }
    for (int i = 1; i < k; i++) dfs(i);
    int t, r;
    t = r = 0;
    for(int i = 0; i < mm; i++) r += ans[m[v[i]]].ff, t += ans[m[v[i]]].ss; 
    printf("%d %d\n",r,t);
}

