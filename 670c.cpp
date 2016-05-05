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
const int N = 200005;
const int modn = 1000000007;

int a[N], b[N], c[N], w[4*N], f[4*N];
int n, m;

int main() {
    scanf("%d",&n);
    int j = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d",a+i);
        w[j++] = a[i];
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        scanf("%d",b+i);
        w[j++] = b[i];
    }
    for(int i = 0; i < m; i++) {
        scanf("%d",c+i);
        w[j++] = c[i];
    }
    sort(w,w+j);
    int g = unique(w,w+j) - w;
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(w,w+g,a[i]) - w;
        f[a[i]]++;
    }
    pii ans = pii(-1,-1);
    int ma;
    for(int i = 0; i < m; i++) {
        b[i] = lower_bound(w,w+g,b[i]) - w;
        c[i] = lower_bound(w,w+g,c[i]) - w;
        if(f[b[i]] > ans.ff) {
            ans = pii(f[b[i]] ,f[c[i]]);
            ma = i+1;
        } else if(f[b[i]] == ans.ff) {
            if(f[c[i]] > ans.ss) {
                ans.ss = f[c[i]];
                ma = i+1;   
            }
        }
    }
    printf("%d\n",ma);
}

