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

int a[N];
int t, n, b;

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%d",a+i);
        int last = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d",&b);
            if(b <= a[i] - last) ans++;
            last = a[i];
        }
        printf("%d\n",ans);
        
    }
}

