#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1123456;
int t[N];
vector<int> adj[N];
map<int, int> m;
bool st[N];
pii ans;
int r = -1;

void dfs(int u) {
    for(int v : adj[u]) {
        dfs(v);
        t[u] += t[v];
    }
}

void get_ans(int u) {
    st[u] = true;
    if(u != r) {
        if(t[r] - t[u] - t[u] == t[u]) {
            if(m.count(t[u]) && !st[m[t[u]]])
                ans = pii(u, m[t[u]]);
            if(m.count(2*t[u]) && st[m[2*t[u]]])
                ans = pii(u, m[2*t[u]]);
        }
        m[t[u]] = u;
    }
    for(int v : adj[u])
        get_ans(v);
    st[u] = false;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int p;
        scanf("%d %d", &p, t+i); p--;
        if (p != -1) adj[p].pb(i);
        else r = i;
    }
    dfs(r);
    ans = pii(-1, -1);
    get_ans(r);
    if(ans.first > ans.second) swap(ans.first, ans.second);
    if(ans.first != -1) 
        printf("%d %d\n", ans.first + 1, ans.second + 1);
    else puts("-1");
}

