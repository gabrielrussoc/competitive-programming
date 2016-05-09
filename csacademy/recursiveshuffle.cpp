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

int n, m, f, p;
int v[N];

int pos (int i, int n) {
    if(n == 1) return 1;
    if(i&1) return n/2 + pos((i+1)/2, (n+1)/2);
    return pos(i/2, n/2);
}

int main() {
    scanf("%d %d",&n,&m);
    scanf("%d",&f);
    f = pos(f, n);
    for(int i = 1; i < m; i++) {
        scanf("%d", &p);
        p = pos(p,n);
        if(p != f+1) {
            puts("0");
            return 0;
        }
        f = p;
    }
    puts("1");
}

