#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1123456;
const ll MODN = 1e9+7;

int n;
ll s[MAXN];

int main() {
    scanf("%d", &n);
    for(int a=0;a<n;a++){
        scanf("%lld",  s+a);
    }
    sort(s, s+n);
    ll res = 1;
    ll cnt = 0;
    for(int a=0;a<n;a++){
        res = (res * (s[a] - cnt))%MODN;
        cnt++;
    }
    printf("%lld\n", res);
}

