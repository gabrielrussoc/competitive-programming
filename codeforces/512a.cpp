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

int n, ss, tt, j;
string s, t;
int g[30][30], vis[30], ans[30], in[30];
bool f;

void dfs(int u) {
    if(in[u]) {
        puts("Impossible");
        exit(0);
    }
    if(vis[u]) return;
    in[u] = vis[u] = 1;
    for(int v = 0; v < 26; v++) {
        if(g[u][v]) dfs(v);
    }
    in[u] = 0;
    ans[j++] = u;
}

int main() {
    scanf("%d",&n);
    cin >> s;
    ss = s.length();
    for(int k = 1; k < n; k++) {
        cin >> t;
        tt = t.length();
        f = false;
        for(int i = 0; i < ss && i < tt && !f; i++) {
            if(s[i] != t[i]) {
                f = true;
                g[s[i]-'a'][t[i]-'a'] = 1;
            }
        }
        if(!f) {
            if(tt < ss) {
                puts("Impossible");
                return 0;
            }  
        }
        s = t;
        ss = tt;
    }
    for(int i = 0; i < 26; i++)
        if(!vis[i])
            dfs(i);
    for(int i = j-1; i >= 0; i--) putchar(ans[i]+'a');
    putchar('\n');
}

