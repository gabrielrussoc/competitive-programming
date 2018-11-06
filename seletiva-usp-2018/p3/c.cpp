#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const int inf = 0x3f3f3f3f;
int v[N], mini[N], maxi[N];
int n, t;

struct point {
    ll x, y;
    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
    point operator+(const point &o) const {
        return point(x+o.x, y+o.y);
    }
    point operator-(const point &o) const {
        return point(x-o.x, y-o.y);
    }
    point operator*(const point &o) const {
        return point(x*o.x, y*o.y);
    }
    ll operator^(const point &o) const {
        return x*o.y - y*o.x;
    }
    bool operator<(const point &o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
} p[2*N], h[2*N];

ll cross(const point &o, const point &a, const point &b) {
    return (a-o)^(b-o);
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> v[i];

        mini[n] = inf;
        maxi[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            maxi[i] = max(v[i], maxi[i+1]);
            mini[i] = min(v[i], mini[i+1]);
        }
        for(int i = 0; i < n-1; i++) {
            p[2*i] = point(v[i], maxi[i+1]);
            p[2*i+1] = point(v[i], mini[i+1]);
        }

        n = 2*(n-1);
        
        int ps = 0;
        sort(p, p+n);
        for(int i = 0; i < n; i++) {
            while(ps >= 2 && cross(h[ps-2], h[ps-1], p[i]) >= 0) ps--;
            h[ps++] = p[i];
        }
        int q = ps;
        for(int i = n-2; i >= 0; i--) {
            while(ps > q && cross(h[ps-2], h[ps-1], p[i]) >= 0) ps--;
            h[ps++] = p[i];
        }

        ll area = 0;
        for(int i = 1; i < ps-1; i++)
            area += abs(cross(h[0], h[i], h[i+1]));
        cout << area << endl;
    }
}

