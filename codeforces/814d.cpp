#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1003;
const double PI = acos(-1);

int g[N], n;
double memo[N][2][2];
bool vis[N][2][2];

vector<int> adj[N];

inline ll sq(ll x) { return x * x; }

struct point {
    ll x, y;
    point () {}
    point(ll x, ll y) : x(x), y(y) {}

    ll distTo(const point &o) const {
        return sq(x - o.x) + sq(y - o.y);
    }
};

struct circle {
    point c;
    ll r;
    circle () {}
    circle (point c, ll r) : c(c), r(r) {}

    bool contains(const circle &o) const {
        return c.distTo(o.c) <= sq(r);
    }

    bool operator<(const circle &o) const {
        return r < o.r;
    }

    double area() const {
        return PI * double(sq(r));
    }

} v[N];

int f(bool p) {
    return p ? -1 : 1;
}

double dp(int u, bool e, bool d) {
    if(u == n) return 0;
    double &me = memo[u][e][d];
    if(vis[u][e][d]) return me;
    vis[u][e][d] = 1;
    me = 0;
    double esq = f(e) * v[u].area();
    double dir = f(d) * v[u].area();
    for(int c : adj[u]){
        esq += dp(c, e^1, d);
        dir += dp(c, e, d^1);
    }
    return me = max(esq, dir);
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        v[i] = circle(point(x,y), r);       
    }
    sort(v, v+n);
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[j].contains(v[i])) {
                adj[j].pb(i);
                g[i]++;
                break;
            }
        }
    }

    double ans = 0;
    for(int i = 0; i < n; i++) if(!g[i]) ans += dp(i, 0, 0);
    printf("%.20lf\n", ans);

}

