#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

typedef complex<double> point;
const double pi = acos(-1);
const double eps = 1e-9;
const point o = point(50, 50);

double x(point p) {
    return p.real();
}

double y(point p) {
    return p.imag();
}

double dot(point a, point b) {
    return x(conj(a) * b);
}

double cross(point a, point b) {
    return y(conj(a) * b);
}

//clockwise
point rotate(point p, double theta) {
    return p * polar(1.0, 2.*pi - theta);
}

int sgn(double x) {
    return (x > -eps) - (x < eps);
}

void show(point p) {
    printf("%.2lf %.2lf\n", x(p), y(p));
}

bool inside(int r, point p) {
    point v = point(0, 1);
    point w = rotate(v, double(r) / 100. * 360 * pi / 180.);
    //show(v);
    //show(w);
    p = p - o;
    if(r <= 50) {
        return sgn(cross(v, p)) * sgn(cross(w, p)) <= 0;     
    } else {
        return sgn(cross(v, p)) * sgn(cross(w, p)) >= 0;     
    }
} 

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        int xin, yin, r;
        scanf("%d %d %d",&r, &xin, &yin);
        printf("Case #%d: ", tc);
        point p = point(xin, yin);
        if(abs(p-o) < 50 + eps && inside(r, p)) 
            puts("black");
        else
            puts("white");
    } 
}

