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
const int N = 10004;
const int modn = 1000000007;

ll solve (ll n) {
    if(n == 0) return 0;
    ll k = (n+1)/2;
    return k*k + solve(n/2);
}

int main() {
    int t;
    ll a, b;
    scanf("%d",&t);
    while(t--) {
        scanf("%lld %lld",&a,&b);
        printf("%lld\n",solve(b) - solve(a-1));
    }
}

