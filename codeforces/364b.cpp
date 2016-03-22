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

int n, d, v[55];
set<int> s;
int visi[55][55*N];

void dp (int i, int sum) {
    if(i == n) { s.insert(sum); return; }
    if(visi[i][sum]) return;
    visi[i][sum] = 1;
    dp (i+1,sum+v[i]);
    dp (i+1,sum);
}

int main() {
    scanf("%d %d",&n, &d);
    for (int i = 0; i < n; i++) scanf("%d",v+i);
    dp(0,0);
    int ans, cont;
    ans = cont = 0;
    set<int>::iterator it = s.upper_bound(d);
    while(it != s.begin()) {
        it--;
        if(*it == ans) break;
        ans = *it;
        cont++;
        it = s.upper_bound(ans+d);
    }
    printf("%d %d\n",ans,cont);
}

