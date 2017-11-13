#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll p, a, t;
    scanf("%d", &n);
    while(n--) {
        scanf("%lld %lld %lld", &p, &a, &t);
        puts(100ll * a > 40ll * t * p ? "Good" : "Bad");
    }
}

