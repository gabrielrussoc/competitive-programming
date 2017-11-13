#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
const ll MOD = 1e9+7;
ll f[N];
int n;

int main() {
    f[1] = 1;
    f[2] = 4;
    scanf("%d", &n);
    for(int i = 3; i <= n; i++)
        f[i] = (((4ll*f[i-1]) % MOD) + MOD - f[i-2]) % MOD; 
    printf("%lld\n", f[n]);
}

