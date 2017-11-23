#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n;

bool isb(int d) {
    for(int k = 1; ((1<<k) - 1) * (1<<(k-1)) <= d; k++) {
        if(d == ((1<<k) - 1) * (1<<(k-1)))
            return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int d = n; d >= 1; d--) {
        if(n % d != 0) continue;
        if(isb(d)) {
            printf("%d\n", d);
            return 0;
        }
    }
}

