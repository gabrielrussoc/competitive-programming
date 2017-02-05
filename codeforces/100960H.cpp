#include <bits/stdc++.h>
#define pb push_front
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 412345;

int lab[N], sz[N], nx[N], head[N], to[N], mark[N], es = 2;
map<pii, int> m;
int vis[N], turn, cs, n;

void add_edge(int u, int v) {
    if(u > v) swap(u, v);
    m[pii(u,v)] = es;
    to[es] = v; nx[es] = head[u]; head[u] = es++;
    to[es] = u; nx[es] = head[v]; head[v] = es++;
}

int find(int &e) {
    if(!e || !mark[e]) return e;
    return e = find(nx[e]);
}

void del_edge(int u, int v) {
    if(u > v) swap(u, v);
    int e = m[pii(u,v)];
    int f = e^1;
    mark[e] = 1;
    mark[f] = 1;
}

void dfs(int u, int p, int c) {
    sz[lab[u]]--;
    sz[c]++;
    lab[u] = c;
    for(int e = find(head[u]); e; e = find(nx[e])) {
        int v = to[e];
        if(v != p) dfs(v, u, c);
    }
}

void join(int a, int b) {
    if(sz[lab[a]] > sz[lab[b]]) swap(a, b);
    dfs(a, -1, lab[b]);
    add_edge(a, b);
}

int min_comp(int a, int b) {
    turn++;
    int round = 0;
    stack<pii> q[2];
    q[0].push(pii(a, find(head[a])));
    q[1].push(pii(b, find(head[b])));
    while(!q[0].empty() && !q[1].empty()) {
        int u = q[round].top().first;
        int le = q[round].top().second;
        q[round].pop();
        if(!le) continue;
        vis[u] = turn;
        int e;
        for(e = le; e; e = find(nx[e])) {
            int v = to[e];
            if(vis[v] != turn) {
                q[round].push(pii(u, find(nx[e])));
                q[round].push(pii(v, find(head[v])));
                break;
            }
        }
        if (!e) continue;
        round = !round;
    }
    return q[0].empty() ? a : b;
}

void unjoin(int a, int b) {
    del_edge(a, b);
    int v = min_comp(a, b);
    dfs(v, -1, cs++);
}

bool test(int a, int b) {
    return lab[a] == lab[b];
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < 2*n; i++) {
        lab[i] = i;
        sz[i] = 1;
    }
    cs = n;
    char c;
    int a, b;
    while(scanf(" %c %d %d",&c, &a, &b) && c != 'E') {
        a--; b--;
        switch(c) {
            case 'C':
                join(a,b);
                break;
            case 'D':
                unjoin(a,b);
                break;
            case 'T':
                puts(test(a,b) ? "YES" : "NO");
                fflush(stdout);
                break;
        }
    }
}
