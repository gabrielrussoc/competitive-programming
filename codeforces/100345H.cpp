#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 203;
int n, m;
set<int> adj[N];
bitset<N> reach[N];

void calc(){
    int cont = 0;
    for(int u = n-1; u >= 0; u--) {
        reach[u] = 0;
        reach[u][u] = 1;
        for(int v : adj[u]) reach[u] |= reach[v];
        cont += reach[u].count() - 1;
    }
    printf("%d\n", cont);
}

int main() {
    freopen("settling.in", "r", stdin);
    freopen("settling.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].insert(v);
    }
    calc();
    int k;
    scanf("%d", &k);
    while(k--){
        char c;
        int u, v;
        scanf(" %c", &c);
        scanf("%d %d", &u, &v);
        u--; v--;
        if(c == '+') {
            adj[u].insert(v);
            calc();
        } else if(c == '-') {
            adj[u].erase(v);
            calc();
        } else  {
            if(reach[u][v]) puts("YES");
            else puts("NO");
        }
    }

}

