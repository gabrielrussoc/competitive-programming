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

int a[N], b[N], n;

int main() {
    while(scanf("%d",&n) != EOF) {
        for(int i = 0; i < n; i++) scanf("%d",a+i);
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
            if(ans > 0) ans -= a[i], b[i] = -1;
            else ans += a[i], b[i] = 1;

        if(ans) puts("No");
        else {
            puts("Yes");
            for(int i = 0; i < n; i++) printf("%d%c",b[i],i == n-1 ? '\n' : ' ');
        }


    }
}

