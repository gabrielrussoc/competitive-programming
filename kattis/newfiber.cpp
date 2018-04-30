#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 10004;
int deg[N], p[N], sum, n, m;
int uf[N], wf[N];
bool change[N];

int find(int u) {
    if(u == uf[u]) return u;
    return uf[u] = find(uf[u]);
}

void join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(wf[u] > wf[v]) swap(u, v);
    uf[u] = v;
    wf[v] += wf[u];
}

bool connected(int u, int v) {
    return find(u) == find(v);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        p[i] = i;
        uf[i] = i;
        wf[i] = 1;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        sum += 2;
    }
    sort(p, p+n, [&](int i, int j) { return deg[i] > deg[j]; });
    int u = 0;
    while(sum > 2*(n-1)) {
        if(deg[p[u]] == 1) u++;
        change[p[u]] = true;
        deg[p[u]]--;
        sum--;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += change[i];
    cout << ans << endl;
    cout << n << ' ' << n-1 << endl;
    sort(p, p+n, [&](int i, int j) { return deg[i] > deg[j]; });
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(deg[p[i]] > 0 && deg[p[j]] > 0 && !connected(p[i], p[j])) {
                join(p[i], p[j]);
                deg[p[i]]--;
                deg[p[j]]--;
                cout << p[i] << ' ' << p[j] << endl;
            }
        }
    }

}

