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

int f[11];

int upd (int n) {
    while (n) {
        f[n%10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) if(!f[i]) return 0;
    return 1;
}

int main() {
    int n, t;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++) {
        memset(f,0,sizeof f);
        scanf("%d",&n);
        int a = n;
        printf("Case #%d: ", i);
        while(1) {
            if(n == 0) {
                printf("INSOMNIA\n");
                break;
            }
            if(upd(a)) {
                printf("%d\n",a);
                break;
            }
            a += n;
        }
    }
}

