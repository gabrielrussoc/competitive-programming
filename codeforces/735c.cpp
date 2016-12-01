#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll n;

int main() {
    scanf("%lld",&n);
    ll a, b, c;
    a = 1;
    b = 1;
    c = a + b;
    int ans = 0;
    while (c <= n){
        a = b;
        b = c;
        c = a + b;
        ans++;
    }
    printf("%d\n",ans);
}
