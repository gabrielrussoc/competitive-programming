#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 50004;

int n, q;
ll cw[N], ccw[N];

struct point {
    ll x, y;
    point() : x(0), y(0) {}
    point(ll _x, ll _y) : x(_x), y(_y) {}
    point operator+(const point &o) const {
        return point(x+o.x, y+o.y);
    }
    point operator-(const point &o) const {
        return point(x-o.x, y-o.y);
    }
    ll operator*(const point &o) const {
        return x*o.x + y*o.y;
    }
    ll operator^(const point &o) const {
        return x*o.y - y*o.x;
    }
    bool operator<(const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
} p[N];

ll cross(const point &o, const point &a, const point &b) {
    return (a-o)^(b-o);
}

ll area(const point &o, const point &a, const point &b) {
    return llabs(cross(o,a,b));
}

int main() {
    bool blank = false;
    while(scanf("%d %d", &n, &q) && n && q) {
        if(blank) puts("");
        blank = true;
        for(int i = 0; i < n; i++) {
            ll x,y;
            scanf("%lld %lld", &x, &y);
            p[i] = point(x,y);
        }
        cw[1] = 0;
        for(int i = 2; i < n; i++) cw[i] = cw[i-1] + area(p[0], p[i-1], p[i]);
        ccw[n-1] = 0;
        for(int i = n-2; i > 0; i--) ccw[i] = ccw[i+1] + area(p[0], p[i], p[i+1]);
        ll total = cw[n-1];
        while(q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            ll ans;
            if(a == 0) ans = min(cw[b], ccw[b]);
            else {
                ll loc = cw[a] + ccw[b] + area(p[0], p[a], p[b]);
                ans = min(loc, total-loc);
            }
            printf("%lld.%lld\n", ans/2ll, (ans % 2ll) * 5ll);
        }
    }
}

