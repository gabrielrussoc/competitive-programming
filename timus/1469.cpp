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
const int N = 50005;
const int modn = 1000000007;
typedef complex<double> point;

int l, r, ts, n, ss;
int key[N], pri[N], lc[N], rc[N];

struct segment {
    point st, end;
    bool f;   
    
}
const double PI = acos(-1);

double x (point a) { return a.real(); }
double y (point a) { return a.imag(); }

double cross (point a, point b){ return y(conj(a)*b); }
double dot (point a, point b){ return x(conj(a)*b); }
point rot (point a, double theta) { return a * polar(1.0, theta); }

int merge(int tl, int tr){
    int ans = tl;
    if(min(tl,tr) == -1) return max(tl,tr);
    if(pri[tl] > pri[tr]) rc[tl] = merge(rc[tl], tr);
    else lc[ans=tr] = merge(tl,lc[tr]); 
    return ans;
}

void split(int t, int k){
    if(t == -1) l = r = -1;
    else {
        if(key[t] > k) split(lc[t],k), lc[t] = r, r = t;
        else split(rc[t],k), rc[t] = l, l = t;
    }
}

int main() {
    srand(time(NULL));
    scanf("%d",&n);
    double ang = 2*PI*((1.*rand())/(1.*RAND_MAX));
    for(int i = 0; i < n; i++){
        double a,b,c,d;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
        if(a > c) swap(a,c), swap(b,d);
        seg[ss++] = rot(point(a,b), ang);
        seg[ss++] = rot(point(c,d), ang);
    }
}

