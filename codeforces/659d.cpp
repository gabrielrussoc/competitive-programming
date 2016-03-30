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
const int N = 1003;
const int modn = 1000000007;

typedef complex<int> point;

int x (point a) {
    return a.real();
}

int y (point a) {
    return a.imag();
}

int a,b,n;
point v[N];

int f(point a, point b) {
    int dx = x(b) - x(a);
    int dy = y(b) - y(a);
    if(dx > 0) return 2;
    if(dx < 0) return 3;
    if(dy > 0) return 0;
    return 1;
}

int can (int dir, int newdir) {
    if(dir == 0) return newdir == 3;
    if(dir == 1) return newdir == 2;
    if(dir == 2) return newdir == 0;
    return newdir == 1;
} 

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&a, &b);
        v[i] = point(a,b);
    }
    /* 0 N
     * 1 S
     * 2 L
     * 3 O */
    int dir = 0, ans = 0, newdir;
    for(int i = 1; i < n-1; i++) {
        point at, nxt;
        at = v[i]; nxt = v[i+1];
        newdir = f(at, nxt);
        ans += can(dir,newdir);
        dir = newdir;
    }
    printf("%d\n",ans);
}

