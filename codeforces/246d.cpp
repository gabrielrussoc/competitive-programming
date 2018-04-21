#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n, m, c[N];
set<int> adj[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", c+i);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        a = c[a]; b = c[b];
        if(a != b) {
            adj[a].insert(b);
            adj[b].insert(a);
        }
    }
    int ans = N, maxi = -1;
    for(int i = 0; i < n; i++) {
        int sz = adj[c[i]].size();
        if(sz > maxi) {
            ans = c[i];
            maxi = sz;
        } else if(sz == maxi) {
            if(c[i] < ans) ans = c[i];
        }
    }
    printf("%d\n", ans);
}

