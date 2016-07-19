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
const int N = 200004;
const int modn = 1000000007;

char s[N];
int l[N], r[N], pl, pr;
int n;

int main() {
    scanf("%d",&n);
    scanf(" %s",s);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        if(s[i] == 'L') l[pl++] = x;
        else r[pr++] = x;   
    }
    int ans = inf;
    for(int i = 0; i < pr; i++) {
        int best = lower_bound(l,l+pl,r[i]) - l;
        if(best != pl) ans = min(ans, (-r[i]+l[best])/2);
    }
    if(ans == inf) ans = -1;
    printf("%d\n",ans);

}

