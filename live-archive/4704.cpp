#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 54;
const int modn = 1000000007;

int v[N], pr[N], a[N],n,t;
ll k;

ll calc (int j, int c){
    memset(a,0,sizeof a);
    for(int i = t-j; i > 1; i--){
        int q = i;
        while(q > 1){
            a[pr[q]]++;
            q /= pr[q];
        }
    }
    for(int i = 0; i < n; i++){
        int q = v[i] - (i == c);
        for(int w = q; w > 1; w--) {
            int d = w;
            while(d > 1) {
                a[pr[d]]--;
                d /= pr[d];
            }
        }
    }
    ll ret = 1;
    for(int i = 2; i < N; i++)
        while(a[i] > 0) {
            ret = ret * ll(i);
            a[i]--;
            if(ret > 1e19) return ret;
        }
    return ret;
}

int main() {

    for(int i = 2; i < N; i++) 
        if(!pr[i])
            for(int j = i; j < N; j += i)
                pr[j] = i;

    while(scanf("%d %llu",&n,&k) && n){
        t = 0;
        for(int i = 0; i < n; i++) scanf("%d",v+i), t += v[i];
        for(int i = 0; i < t; i++){
            for(int c = 0; c < n; c++){
                if(v[c]) {
                    ll b = calc(i+1,c);
                    if(k < b) {
                        v[c]--;
                        putchar(c+'a');
                        break;
                    }
                    else
                        k -= b;
                }
            }
        }
        putchar('\n');
    }
}

