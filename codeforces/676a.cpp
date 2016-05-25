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

int main() {
    int n;
    scanf("%d",&n);
    int l, r;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        if(a == 1) l = i;
        else if(a == n) r = i;
    }
    if(l > r) swap (l,r);
    printf("%d\n",max(r, n-1-l));
}

