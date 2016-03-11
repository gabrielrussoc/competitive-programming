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
const int N = 1000004;
const int modn = 1000000007;

int n, k, a, b,ps;
int p[N];
ll e[30], d[30], primes[N], ans;
int t[35][1<<16 + 7], ts[35], ss;

bool comp (int i, int j) {
    ll a, b;
    a = b = 0;
    for(int k = 0; k < n/2; k++){
        if(i&(1<<k)) a += d[k];
        if(j&(1<<k)) b += d[k];
    }
    return a < b;
}

string get (int x) {
    if(!x) return "{0}";
    string a = "{";
    for(int i = 0; i < n/2; i++) if(x&(1<<i)) a += d[i]+'0', a += ' ';
    return a+'}';
}
string get2 (int x) {
    if(!x) return "{0}";
    string a = "{";
    for(int i = 0; i < (n+1)/2; i++) if(x&(1<<i)) a += e[i]+'0', a += ' ';
    return a+'}';
}

ll vale(int x) {
    ll ret = 0;
    for(int i = 0; i < (n+1)/2; i++) if(x&(1<<i)) ret += e[i];
    return ret;
}

ll vald(int x) {
    ll ret = 0;
    for(int i = 0; i < n/2; i++) if(x&(1<<i)) ret += d[i];
    return ret;
}

int main() {
    for(int i = 2; i*i < N; i++){
        if(p[i]) continue;
        for(int j = i*i; j < N; j += i)
            p[j] = 1;
    }
    for(int i = 2; i < N; i++) if(!p[i]) primes[ps++] = i;
    
    scanf("%d %d %d %d",&n,&k,&a,&b);
    ll bar;
    for(int i = 0; i < (n+1)/2; i++) {
        scanf("%lld",&bar);
        ll foo = 1;
        for(int j = 0; j < ps; j++) if(bar % primes[j] == 0) foo *= primes[j];
        e[i] = foo;
    }
    for(int i = 0; i < n/2; i++) {
        scanf("%lld",&bar);
        ll foo = 1;
        for(int j = 0; j < ps; j++) if(bar % primes[j] == 0) foo *= primes[j];
        d[i] = foo;
    }
    ss = 1<<((n+1)/2);
    int bs = 1<<(n/2);
    for(int i = 0; i < bs; i++) {
        int q = __builtin_popcount(i);
        t[q][ts[q]++] = i;
    }
    for(int i = 0; i <= n/2; i++)
        sort(t[i],t[i]+ts[i],comp);
    
    for(int i = 0; i < ss; i++) {
        ll x = vale(i);
        int w = __builtin_popcount(i);
        for(int j = 0; j <= k-w; j++) {
            int lb, ub;
            int lo = 0, hi = ts[j];
            while (lo != hi) {
                int mid = (lo+hi)/2;
                if(vald(t[j][mid]) + x < a) lo = mid+1;
                else hi = mid;
            }
            lb = lo;
            lo = -1, hi = ts[j]-1;
            while(lo != hi) {
                int mid = (lo+hi+1)/2;
                if(vald(t[j][mid]) + x > b) hi = mid-1;
                else lo = mid;
            }
            ub = lo;
            //cout << "Para : " << get2(i) << endl; 
            //for(int l = lb; l <= ub; l++) cout << get(t[j][l]) << endl;
            if(ub >= lb) ans += ub-lb+1;
        }
    }
    printf("%lld\n",ans);
}

