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
const int N = 1000007;
const int modn = 1000000007;

struct query {
    int k;
    char type, who;
} q[N];

int n, m, ps;
int a[N], b[N+N], st[N];
ll esq[N], dir[N];

ll acc[3*N];

char opos (char c) {
    if(c == 'D') return 'C';
    return 'D';
}

int main() {
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++) scanf("%d",a+i);
    for (int i = 0; i < m; i++) 
        scanf(" %c %d %c",&q[i].type, &q[i].k, &q[i].who);

    for(int i = 0; i < n; i++) b[i] = a[i];
    for(int i = 0; i < m; i++) b[i+n] = q[i].k;
    sort(b, b+n+m);
    int g = unique(b,b+n+m) - b;
    
    for(int i = 0; i < n; i++) a[i] = lower_bound(b,b+g,a[i]) - b + 1;
    for(int i = 0; i < m; i++) q[i].k = lower_bound(b,b+g,q[i].k) - b + 1;
    
    esq[0] = 1;
    ps = 0;
    st[ps++] = 0;
    for(int i = 1; i < n; i++) {
        while (ps && a[st[ps-1]] < a[i]) ps--; 
        esq[i] = ps ? i-st[ps-1] : i+1;
        st[ps++] = i;
    }
    dir[n-1] = 1;
    ps = 0;
    st[ps++] = n-1;
    for(int i = n-2; i >= 0; i--) {
        while (ps && a[st[ps-1]] <= a[i]) ps--;
        dir[i] = ps ? st[ps-1]-i : n-i;
        st[ps++] = i;
    }

    for(int i = 0; i < n; i++)
        acc[a[i]] += esq[i]*dir[i];
    for(int i = 1; i < 3*N; i++)
        acc[i] += acc[i-1];

    for(int i = 0; i < m; i++) {
        ll ans;
        if(q[i].type == '<') ans = acc[q[i].k-1];
        else if(q[i].type == '=') ans = acc[q[i].k] - acc[q[i].k-1];
        else ans = acc[3*N-1] - acc[q[i].k];
        ans %= 2ll;
        if(ans) putchar(q[i].who);
        else putchar(opos(q[i].who));
    }
    putchar('\n');

}

