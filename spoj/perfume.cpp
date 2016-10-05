#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 207;
const double eps = 1e-9;

struct point {
    double x, y;
    point () {}
    point (double x, double y):x(x), y(y) {}
    point operator+ (const point &o) {
        return point(x+o.x, y+o.y);
    }
    point operator- (const point &o) {
        return point(x-o.x, y-o.y);
    }
    double operator* (const point &o) {
        return x*o.x + y*o.y;
    }
    double operator^ (const point &o) {
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


int t, n, ps, q, cs;
point p[N];
point hull[N];
double xin, yin;

int sgn (double x) {
    return (x > -eps) - (x < eps);
}

int orient (point a, point b, point c) {
    return sgn((b-a)^(c-a));
}

double norm(point a) {
    return sqrt(a.x*a.x + a.y*a.y);
}

int cvx_hull(){
    ps = 0;
    hull[ps++] = p[0];
    if(n == 1) return ps;
    hull[ps++] = p[1];
    if(n == 2) return ps;
    int ls = ps;
    for(int i = 2; i < n; i++) {
        while(ps >= ls && orient(hull[ps-2],hull[ps-1],p[i]) != 1) ps--;
        hull[ps++] = p[i];
    }
    hull[ps++] = p[n-2];
    ls = ps;
    for(int i = n-3; i >= 0; i--) {
        while(ps >= ls && orient(hull[ps-2],hull[ps-1],p[i]) != 1) ps--;
        hull[ps++] = p[i];
    }
    return --ps;
}

bool insidesegment(point a, point b, point q) {
    return fabs(norm(q-a)+norm(q-b)-norm(b-a)) < eps;
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


bool inside(point q) {
    if(cs == 1) return q == hull[0];
    if(cs == 2) return insidesegment(hull[0],hull[1],q);
    for(int i = 1; i < cs-1; i++)
        if(insidetriangle(hull[0],hull[i],hull[i+1],q)) return true;
    return false;
}

int main() {
   scanf("%d",&t);
   bool blank = false;
   for(int tc = 1; tc <= t; tc++) {
        if(blank) putchar('\n');
        blank = true;
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf",&xin,&yin);
            p[i] = point(xin, yin);
        }
        sort(p,p+n);
        cs = cvx_hull();
        scanf("%d",&q);
        while(q--) {
            scanf("%lf %lf",&xin,&yin);     
            if(inside(point(xin,yin))) puts("Yes");
            else puts("No");
        }
   }
}

