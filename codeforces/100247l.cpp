#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

map<int, int> memo;

int dp(int n) {
    if(n == 1) return 1;
    if(memo[n]) return memo[n];
    memo[n] = (n + 2) / 2;
    for(int p = 2; p * p <= n; p++)
        if(!(n%p))
            memo[n] = min(memo[n], dp(n/p) * ((p+2)/2));
    return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", dp(n));
}