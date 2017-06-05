#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;

int c, p, x, l, ga[N], go[N];
bool vis[N];
vector<int> adj[N];

void leave() {
    puts("leave");
    exit(0);
}

int main() {
    scanf("%d %d %d %d", &c, &p, &x, &l); x--; l--;
    for(int i = 0; i < p; i++) {
        int a, b;
        scanf("%d %d",&a, &b);
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        ga[a]++; ga[b]++;
    }
    for(int i = 0; i < c; i++) go[i] = ga[i];

    queue<int> q;
    q.push(l);
    vis[l] = true;
    while(!q.empty()) {
        int u = q.front();
        if(u == x) leave();
        q.pop();
        for(int v : adj[u]) {
            ga[v]--;
            if(2*ga[v] <= go[v] && !vis[v]) {
                q.push(v);
                vis[v] = true;
            } 
        }
    }
    puts("stay");
}

