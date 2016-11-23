#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
int n, m, a[N], l[N], r[N];
int memo[N], visi[N];

int dp(int i) {
    if(i == m) return 0;
    int &me = memo[i];
    if(visi[i]) return me;
    visi[i] = 1;
    me = dp(i+1);
    int cont = 0;
    for(int j = l[i]-1; j < r[i]; j++)
        cont += a[j];
    me = max(me, cont + dp(i+1));
    return me;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    for(int i = 0; i < m; i++) scanf("%d %d",l+i,r+i);
    printf("%d\n",dp(0));
}

