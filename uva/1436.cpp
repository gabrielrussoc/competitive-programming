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
const int N = 500004;
const int modn = 1000000007;

int p[N], sz[N], pr[N], primes[N], v[N];
int ps, t ,n, m;

int main() {
    
    for(int i = 2; i < N; i++) {
        if(!pr[i])
            for(int j = i; j < N; j+= i)
                pr[j] = i;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i = 1; i < n; i++) {
            scanf("%d",&p[i]);
            p[i]--;
            sz[i] = 1;
        }
        for(int i = n-1; i > 0; i--) sz[p[i]] += sz[i];
        memset(v,0,sizeof v);
        for(int i = 2; i < n; i++){
            int k = i;
            while(k > 1) {
                v[pr[k]]++;
                k /= pr[k];
            }
        }
        for(int i = 1; i < n; i++){
            int k = sz[i];
            while(k > 1) {
                v[pr[k]]--;
                k /= pr[k];
            }
        }
        ll ans = 1;
        for(int i = 2; i < n; i++) 
            while (v[i]--) ans = (ans*i)%m;
        printf("%lld\n",ans);
    }
}

