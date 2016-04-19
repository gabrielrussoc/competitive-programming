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
const int N = 100005;
const int modn = 1000000007;

int v[11];
char s[55];
int t, n, j;

ll base(int a, ll k) {
    ll pot = 1;
    ll ret = 0;
    while(a) {
        ret += (a&1)*pot;
        pot *= k;
        a >>= 1;
    }
    return ret;
}


void bin(int a) {
    s[n] = 0;
    int i = n-1;
    while(a) {
        s[i--] = (a&1) + '0';
        a >>= 1;
    }
    printf("%s",s);
}

ll isp(ll a) {
    for (ll i = 2; i*i <= a; i++)
        if(a%i == 0) return i;
    return 0;
}

int main() {
    int k;
    ll a, r;
    scanf("%d %d %d",&t,&n,&j);
    printf("Case #1:\n");
    for(int i = (1<<(n-1)); i < (1<<(n)); i++) {
        if(!(i&1)) continue;
        for(k = 2; k < 11; k++) {
            a = base(i,k);
            r = isp(a);
            if(!r) break;
            v[k] = r;
        }
        if(k == 11) {
            bin(i);
            for(int p = 2; p < 11; p++) printf(" %d",v[p]);
            printf("\n");
            j--;
        }
        if(!j) break;
    }
}

