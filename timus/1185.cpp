#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1004;
const int modn = 1000000007;

int n, l, ps;

struct point {
    ll x, y;
    point () {}
    point (ll a, ll b) : x(a), y(b) {}
} v[N], st[N];

int sign (ll x) {
    return (x > 0) - (x < 0);
}

int orient (point a, point b, point c) {
    return sign ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

ll d2 (point a, point b) {
    return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y); 
}

bool comp (point i, point j) {
    int o = orient (v[0], i, j);
    if (o == 0) return d2 (v[0], i) < d2 (v[0], j);
    return o == 1;
}

void graham(){
    st[ps++] = v[0];
    st[ps++] = v[1];
    st[ps++] = v[2];

    for (int i = 3; i < n; i++) {
        while (orient(st[ps-2], st[ps-1], v[i]) != 1) ps--;
        st[ps++] = v[i];
    }
    double ans = 0;
    for (int i = 0; i < ps-1; i++) 
        ans += sqrt(d2(st[i], st[i+1]));
    ans += sqrt(d2(st[0], st[ps-1]));

    double PI = acos(-1);
    ans += 2.*PI*double(l);
    printf("%.0lf", ans);
}

int main() {
    scanf("%d %d", &n, &l);
    point f = point(inf, inf);
    int esq;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d",&x,&y);   
        v[i] = point(x,y);
    }
    for (int i = 0; i < n; i++) {
        if(v[i].y < f.y) {
            esq = i;
            f = v[i];
        } else if (v[i].y == f.y) {
            if(v[i].x < f.x) {
                esq = i;
                f = v[i];
            }
        }
    }
    swap (v[0], v[esq]);
    sort (v+1, v+n, comp);
    graham();
}

