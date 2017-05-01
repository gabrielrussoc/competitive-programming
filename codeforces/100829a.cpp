#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int n, t[N], v[N];
double start;

double dist(double m) {
    double mn, mx;
    mn = 1. / 0.;
    mx = 0;
    for(int i = 0; i < n; i++) {
        double pos = (m - double(t[i])) * double(v[i]);
        mn = min(pos, mn);
        mx = max(pos, mx);
    }
    return mx - mn;
}

int main() {
    while(scanf("%d",&n) && n != 0) {
        for(int i = 0; i < n; i++) scanf("%d %d", t+i, v+i);
        start = *max_element(t, t+n);
        double lo = start, hi = 1e9;
        int iter = 0;
        while(iter++ < 100) {
            double r = (hi-lo)/3.;
            double m1 = lo + r;
            double m2 = lo + 2.*r;
            if(dist(m1) <= dist(m2)) hi = m2;
            else lo = m1;
        }
        printf("%.3lf\n", dist(lo));
    }

}