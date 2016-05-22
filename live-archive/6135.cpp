#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-6;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

int w, d, a, k;
int p[5][12];
double mid;

double poli (int i, double x){
    double q = 1;
    double ret = 0;
    for(int j = 0; j < k+1; j++){
        ret += p[i][j]*q;
        q *= x;
    }
    return ret;
}

double g(int i, double x) {
    return max (mid, poli(2*i,x)/poli(2*i+1,x));
}

double f(double x){
    return g(0,x) - g(1,x);
}

double simps(double a, double b) {
    return (f(a) + 4*f((a+b)/2) + f(b))*(b-a)/6;
}

double area (double a, double b) {
    double m = (a+b)/2;
    double l = simps(a,m), r = simps(m,b), ret = simps(a,b);
    if(fabs(l+r-ret) < eps) return ret;
    return area(a,m) + area(m,b);
    
}

int main() {
    while (scanf("%d %d %d %d",&w,&d,&a,&k) != EOF) {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < k+1; j++)  
                scanf("%d", &p[i][j]);
        double lo = -d, hi = 0;
        while(hi-lo > eps){
            mid = (hi+lo)*.5;    
            if(area(0,w) >= a) lo = mid;
            else hi = mid;
        }
        printf("%.5lf\n",-lo);
    }
}

