#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N = 100005;
int n, m;

struct edge {
    int u, v, w;
    edge(){}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

vector<edge> g;

void add(int u, int v, int w) {
    g.pb({u,v,w});
}

int is_prime(int p) {
    for(int i = 2; i*i <= p; i++)
        if(p%i == 0) return false;
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    add(0,n-1,2);
    for(int i = 1; i < n-1; i++)
        add(i, i+1, 1);
    int sum = n;
    int p = sum;
    while(!is_prime(p)) p++;
    g[1] = {g[1].u, g[1].v, g[1].w + p-sum};
    int q = n-1;
    for(int u = 0; u < n && q < m; u++) {
        for(int v = u+1; v < n && q < m; v++) {
            if(u == 0 && v == n-1) continue;
            if(u > 0 && v == u+1) continue;
            q++;
            add(u,v,p+1);
        }
    }
    printf("2 %d\n", p);
    for(edge &e : g) {
        printf("%d %d %d\n", e.u+1, e.v+1, e.w); 
    }

}

