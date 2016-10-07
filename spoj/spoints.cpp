#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 107;
const double eps = 1e-9;
typedef int cood;

struct point {
    cood x, y;
    point () {}
    point (cood x, cood y):x(x), y(y) {}
    point operator+ (const point &o) {
        return point(x+o.x, y+o.y);
    }
    point operator- (const point &o) {
        return point(x-o.x, y-o.y);
    }
    cood operator* (const point &o) {
        return x*o.x + y*o.y;
    }
    cood operator^ (const point &o) {
        return x*o.y - o.x*y;
    }
    bool operator< (const point &o) const {
        if(x == o.x) return y < o.y + eps;
        return x < o.x + eps;
    }
    bool operator== (const point &o) const {
        return fabs(x-o.x) < eps && fabs(y-o.y) < eps;
    }
};


int n, m;
point p[N], q[N];
point hull[N][2];
cood xin, yin;

int sgn (cood x) {
    return (x > 0) - (x < 0);
}

int orient (point a, point b, point c) {
    return sgn((b-a)^(c-a));
}

double norm(point a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

bool insidesegment(point a, point b, point q) {
    return fabs(norm(q-a)+norm(q-b)-norm(b-a)) < eps;
}

int cvx_hull(int k, point *p, int n){
    sort(p,p+n);
    int ps = 0;
    hull[ps++][k] = p[0];
    if(n == 1) return ps;
    hull[ps++][k] = p[1];
    if(n == 2) return ps;
    int ls = ps;
    for(int i = 2; i < n; i++) {
        while(ps >= ls && orient(hull[ps-2][k],hull[ps-1][k],p[i]) != 1) ps--;
        hull[ps++][k] = p[i];
    }
    hull[ps++][k] = p[n-2];
    ls = ps;
    for(int i = n-3; i >= 0; i--) {
        while(ps >= ls && orient(hull[ps-2][k],hull[ps-1][k],p[i]) != 1) ps--;
        hull[ps++][k] = p[i];
    }
    return --ps;
}

bool insidetriangle(point a, point b, point c, point q) {
    if(insidesegment(a,b,q)) return true;
    if(insidesegment(b,c,q)) return true;
    if(insidesegment(a,c,q)) return true;
    int s = sgn((b-a)^(q-a));
    if(sgn((c-b)^(q-b)) != s) return false;
    if(sgn((a-c)^(q-c)) != s) return false;
    return true;
}

bool inside(point q, int k, int sz) {
    if(sz == 1) return q == hull[0][k];
    if(sz == 2) return insidesegment(hull[0][k],hull[1][k],q);
    for(int i = 1; i < sz-1; i++)
        if(insidetriangle(hull[0][k],hull[i][k],hull[i+1][k],q)) return true;
    return false;
}

cood area(point a, point b, point c) {
    return (b-a)^(c-a);
}

bool intersect_l (int a, int b, int c, int d) {
    if (a > b) swap(a,b);
    if (c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

bool intersectsegment (point a, point b, point c, point d) {
    return intersect_l (a.x,b.x,c.x,d.x)
        && intersect_l (a.y,b.y,c.y,d.y)
        && sgn(area(c,a,b)) * sgn(area(d,a,b)) <= 0
        && sgn(area(a,c,d)) * sgn(area(b,c,d)) <= 0;
}

bool contains(point *p, point *q, int sa, int sb) {
    bool g, h;
    g = h = true;
    for(int i = 0; i < sa && g; i++)
        if(!inside(p[i],1,sb)) g = false;
    for(int i = 0; i < sb && h; i++)
        if(!inside(q[i],0,sa)) h = false;
    return g || h;
}

bool intersect(point *p, point *q, int sa, int sb) {
    for(int i = 0; i < sa; i++)
        for(int j = 0; j < sb; j++)
            if(intersectsegment(hull[i][0],hull[(i+1)%sa][0],hull[j][1],hull[(j+1)%sb][1]))
                return true;
    return false;
}

int main() {
    while(scanf("%d %d",&n,&m) && n && m) {
        for(int i = 0; i < n; i++) {
            scanf("%d %d",&xin,&yin);
            p[i] = point(xin,yin);
        }
        for(int i = 0; i < m; i++) {
            scanf("%d %d",&xin,&yin);
            q[i] = point(xin,yin);
        }
        int sa = cvx_hull(0,p,n);
        int sb = cvx_hull(1,q,m);
        if(contains(p,q,sa,sb)) puts("NO");
        else if(intersect(p,q,sa,sb)) puts("NO");
        else puts("YES");
    }
}
