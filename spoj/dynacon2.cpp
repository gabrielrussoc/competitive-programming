#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;

struct uf {
    int id[N], sz[N];
    vector<int> hist;
    uf() {
        for(int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int u) {
        if(u == id[u]) return u;
        return find(id[u]);
    }

    void join(int u, int v) {
       u = find(u); v = find(v); 
       if(u == v) {
           hist.pb(-1);
           return;
       }
       if(sz[u] > sz[v]) swap(u, v); 
       id[u] = v;
       sz[v] += sz[u];
       hist.pb(u);
    }

    void undo() {
        if(!hist.size()) return;
        int u = hist.back();
        hist.pop_back();
        if(u == -1) return;
        sz[id[u]] -= sz[u];
        id[u] = u;
    }
} U;

enum _ {
    ADD,
    REM,
    CONN
};

struct qry {
    int u, v, type, other;
    qry(){}
    qry(int u, int v, int type, int other) : u(u), v(v), type(type), other(other) {}
} q[N];

map<pair<int, int>, int> open;

void rollback(int cnt) {
    for(int i = 0; i < cnt; i++) U.undo();
}

void solve(int l, int r) {
    if(l == r) {
        if(q[l].type == CONN) {
            int u = q[l].u;
            int v = q[l].v;
            puts(U.find(u) == U.find(v) ? "YES" : "NO");
        }
        return;
    }
    int m = (l+r)/2;

    int cnt = 0;
    for(int i = m+1; i <= r; i++) {
        if(q[i].type == REM && q[i].other < l) {
            U.join(q[i].u, q[i].v);
            cnt++;
        }
    }
    solve(l, m);
    rollback(cnt);
    
    cnt = 0;
    for(int i = l; i <= m; i++) {
        if(q[i].type == ADD && q[i].other > r) {
            U.join(q[i].u, q[i].v);
            cnt++;
        }
    }
    solve(m+1, r);
    rollback(cnt);
}

int main() {
    int n, m;
    char op[10];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf(" %s %d %d", op, &u, &v);
        if(u > v) swap(u, v);
        pair<int, int> uv = {u, v};
        if(op[0] == 'a') { 
            q[i] = {u, v, ADD, -1};
            open[uv] = i;
        }
        if(op[0] == 'r') { 
            int other = -1;
            if(open.count(uv)) {
                other = open[uv];
                q[other].other = i;
                open.erase(uv);
            }
            q[i] = {u, v, REM, other};
        }
        if(op[0] == 'c') q[i] = {u, v, CONN, -1};
    }

    int nm = m;
    for(int i = 0; i < m; i++) {
        if(q[i].type == ADD && q[i].other == -1) {
            q[nm] = {q[i].u, q[i].v, REM, i};
            q[i].other = nm;
            nm++;
        }
    }
    m = nm;
    solve(0, m-1);
}

