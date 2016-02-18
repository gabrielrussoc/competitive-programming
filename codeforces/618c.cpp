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
const int N = 100004;
const int modn = 1000000007;
typedef complex<ll> point;

point v[N];
int p[N];

ll x(point a){ return a.real(); }
ll y(point a){ return a.imag(); }
ll cross(point a, point b) { return y(conj(a) * b); }
int n;

bool comp (int i, int j){
    if(x(v[i]) == x(v[j])) return y(v[i]) < y(v[j]);
    return x(v[i]) < x(v[j]);
}

int sig (ll x){
    return (x>0) - (x<0);
}

int ok (point a, point b, point c){
    return sig(cross(b-a,c-a));
}

int main() {
    scanf("%d",&n);
    ll a,b;
    for(int i = 0; i < n; i++){
        p[i] = i;
        cin >> a >> b;
        v[i] = point(a,b);
    }
    int cont = 0;
    sort(p, p+n, comp);
    for(int i = 0; i < n-2; i++){
        if(ok(v[p[i]],v[p[i+1]],v[p[i+2]])) {
            printf("%d %d %d\n",p[i]+1,p[i+1]+1,p[i+2]+1);
            return 0;
        }
    }


}

