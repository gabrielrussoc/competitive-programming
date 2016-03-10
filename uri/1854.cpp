#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define y1 auehushuesah
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 1004;
const int K = 10001004;
const ll modn = 1000000007;

int bit[N][N];

int x1,x2,y1,y2,c,b,n,m;
char s[150];
ll fat[K];

void add (int idx, int idy, ll val) {
    for(int i = idx; i < N; i += i&-i)
        for(int j = idy; j < N; j += j&-j)
            bit[i][j] += val;
}

ll query(int idx, int idy) {
    ll sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        for(int j = idy; j > 0; j -= j&-j)
            sum += bit[i][j];
    return sum;
}

ll fexp (ll a, ll e) {
    ll t = 1;
    for(;e; e >>= 1, a = (a*a)%modn)
        if(e&1) t = (a*t)%modn;
    return t;
}

ll solve (ll n, ll k) {
    if(!n) return 0;
    ll num = fat[n+k-1];
    ll den = (fat[n-1] * fat[k]) % modn;
    return (num * fexp(den,modn-2))%modn;
}

int main() {
    fat[0] = 1;
    for(ll i = 1; i < K; i++)
        fat[i] = (fat[i-1]*i)%modn;
    scanf("%d %d",&n,&m);
    int day = 0;
    while(scanf(" %[^\n]", s) != EOF){
        int count = sscanf(s, "%d %d %d %d %d", &x1, &y1, &x2, &y2, &c); 
        b = x2;
        if (count == 3) add(x1,y1,b);
        else if (count == 2) {
            ll val = query(x1,y1) - query(x1-1,y1) - query(x1,y1-1) + query(x1-1,y1-1);
            add(x1,y1,-val);
        } else {
            ll res = query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
            ll ret = solve(res,c);
            printf("Day #%d: %d\n",++day, ret);
        }
    }
}

