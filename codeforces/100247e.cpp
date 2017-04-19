#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n;
char s[N];
bool seen[N];
vector<int> adj[N], ans;

int dfs(int u, char f) {
    seen[u] = true;
    if (s[u] == '0') s[u] = f;
    bool appear = false;
    vector<int> aux;
    for (int v : adj[u]) {
        if (!seen[v]) {
            int x = dfs(v, s[u]);
            if (x == -1) {
                appear = true;       
            } else aux.pb(v);
        }
    }

    if (appear) {
        for (int i = 0; i < aux.size(); i++) 
            ans.pb(aux[i] + 1);
        return -1;
    }
    if (u != 0 && adj[u].size() == 1) {
        if (s[u] == '-') return -1;
    }
    return 1;
}

int main() {
    scanf(" %d", &n);
    scanf(" %s", s);
    for (int i = 0; i < n - 1; i++) { 
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    if (n == 1) {
        if (s[0] == '+') {
            printf("1\n1\n");
        } else
            printf("0\n");
        return 0;
    }
    
    if (s[0] == '0') s[0] = '-';
    if (dfs(0, s[0]) == 1)
        ans.pb(1);
    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) 
        printf("%d ", ans[i]);
    printf("\n");
}