#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const double eps = 1e-9;

class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(double a) : x(a), y(a) {} 
    double operator^ (const Point &o) const {
        return x * o.y - o.x * y;
    }
    double operator* (const Point &o) const {
        return x * o.x + y * o.y;
    }
    Point operator+ (const Point &o) const {
        return Point(x + o.x, y + o.y);
    }
    Point operator- (const Point &o) const {
        return Point(x - o.x, y - o.y);
    }
    Point operator- () const {
        return Point(-x, -y);
    }
    Point operator* (const double lambda) const {
        return Point(x * lambda, y * lambda);
    }
    double dist2 (const Point &o = 0) const {
        return (*this - o) * (*this - o);
    }
    bool operator< (const Point &o) const {
        if(fabs(x - o.x) < eps) return y < o.y + eps;
        return x < o.x + eps;
    }
    Point proj (const Point &o) const {
        return o * ((*this * o) / o.dist2());
    }
};

Point read() {
    double x, y;
    scanf("%lf %lf", &x, &y);
    return Point(x, y);
}

double qd(double x) {
    return x * x;
}

int main() {
    int t;
    double lm, lg;
    scanf("%d", &t);
    Point a, b, c;
    while(t--) {
        scanf("%lf %lf", &lm, &lg);
        a = read();
        b = read();
        c = read();
        if(fabs((b-a)^(c-a)) < eps) { //colinear
            double dist2 = max((b-a).dist2(), max((c-a).dist2(), (b-c).dist2()));
            if(dist2 <= qd(max(lm, 2*lg)) + eps) puts("YES");
            else puts("NO");
        } else {
            bool ans = false;
            vector<Point> v; v.pb(a); v.pb(b); v.pb(c);
            sort(v.begin(), v.end());
            do {
                a = v[0]; b = v[1]; c = v[2];
                Point ac = c-a;
                Point ab = b-a;
                Point h = ac.proj(ab) + a;
                if(max((h-a).dist2(), (h-b).dist2()) <= qd(lg) + eps && (h-c).dist2() <= qd(lm) + eps) ans = true;
                if(max((h-a).dist2(), (h-b).dist2()) <= qd(lm) + eps && (h-c).dist2() <= qd(lg) + eps && ((h-a) * (h-b)) >= -eps) ans = true;
            } while(next_permutation(v.begin(), v.end()));
            if(ans) puts("YES");
            else puts("NO");
        }
    }
}

