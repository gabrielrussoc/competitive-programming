#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, k, b, x;
const int N = 50004;
const int inf = 0x3f3f3f3f;
int a[N], d[N];
bool vis[N];

struct edge {
    int w, v;
    edge(){}
    edge(int v, int w) : v(v), w(w) {}
    bool operator<(const edge &o) const {
        return w > o.w;
    }
};

void dij(){
    priority_queue<edge> pq;
    for(int u = 0; u < x; u++) d[u] = inf;
    int s = 0;
    d[s] = 0;
    pq.push(edge(s, d[s]));
    while(!pq.empty()){
        int u = pq.top().v;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < n; i++) {
            int v = (u + a[i]) % x;
            int w = a[i];
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push(edge(v, d[v]));
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a+n);
    n = unique(a, a+n) - a;
    
    x = *min_element(a, a+n);
    dij();

    scanf("%d",&k);
    while(k--) {
        scanf("%d", &b);
        if(d[b%x] <= b) puts("TAK");
        else puts("NIE");
    }
}

