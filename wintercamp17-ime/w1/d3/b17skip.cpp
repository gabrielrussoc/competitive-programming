#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1123456;
int n;
ll s[MAXN];
int mn[MAXN];

int main() {
    scanf("%d", &n);
    for(int a=1;a<=n;a++){
        scanf("%lld", &s[a]);
    }
    mn[n] = n;
    for(int a=n-1;a>=0;a--){
        if(s[a+1] < s[mn[a+1]])
            mn[a] = a+1;
        else
            mn[a] = mn[a+1];
    }
    int u = 0;
    ll res = 0;
    while(u != n){
        res += s[mn[u]]*(mn[u] - u);
        u = mn[u];
    }
    printf("%lld\n", res);
}

