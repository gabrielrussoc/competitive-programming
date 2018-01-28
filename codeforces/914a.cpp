#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n;

bool sq(int x) {
    if(x < 0) return false;
    if(x < 2) return true;
    int d = 2;
    for(d = 2; d*d < x; d++);
    return d*d == x;
}

int main() {
    scanf("%d", &n);
    int ans = -1e7;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if(!sq(a)) ans = max(ans, a);
    }
    printf("%d\n", ans);
}

