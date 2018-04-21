#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 12;
const int M = 10004;


int fexp(int x, int e, int mod) {
    int r = 1;
    while(e) {
        if(e&1) r = (x*r) % mod;
        x = (x*x) % mod;
        e >>= 1;
    }
    return r%mod;
}

int expmax(int x, int e) {
    /* cout << x << "^" << e << endl; */
    int r = 1;
    while(e && r < M) {
        r = r*x;
        e--;
    }
    return r;
}

bool vis[M];
void get_dist_cyc(int a, int mod, int &dist, int &cyc) {
    for(int i = 0; i < mod; i++) vis[i] = false;
    stack<int> s;
    int u = a;
    cyc = dist = 0;
    while(!vis[u]) {
        s.push(u);
        vis[u] = true;
        u = (u*a) % mod;
    }
    int v = s.top();
    while(v != u) {
        s.pop();
        v = s.top();
        cyc++;
    }
    s.pop();
    cyc++;
    dist = s.size();
    /* printf("Para %d no mod %d deu dist %d e cyc %d\n", a, mod, dist, cyc); */
}
int n, m, a[N], el[N];

int calc(int i, int sub, int mod) {
    if(i == n-1) return (a[i] + mod - sub) % mod;
    int cyc, dist;
    get_dist_cyc(a[i] % mod, mod, dist, cyc);   
    if(dist <= el[i+1]-1)
        return (fexp(a[i], calc(i+1, dist+1, cyc) + dist+1, mod) + M*mod - sub) % mod;
    else 
        return (fexp(a[i], el[i+1], mod) + mod - sub) % mod;
}

int main() {
    int tc = 1;
    string s;
    stringstream line;
    getline(cin, s);
    while(s != "#") {
        line = stringstream(s);
        line >> m >> n;
        for(int i = 0; i < n; i++) line >> a[i];
        el[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--) el[i] = expmax(a[i], el[i+1]);
        /* for(int i = 0; i < n; i++) cout << el[i] << endl; */
        printf("Case #%d: %d\n", tc++, calc(0, 0, m));
        getline(cin, s);
    }
}

