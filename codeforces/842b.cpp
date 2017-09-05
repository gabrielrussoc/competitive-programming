#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int r, d, n, ans = 0;

int sq(int x) {
    return x*x;
}

int main() {
    scanf("%d %d", &r, &d);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y, rd;
        scanf("%d %d %d", &x, &y, &rd);
        int dist = x*x + y*y;
        if(dist >= sq(r-d+rd) && dist <= sq(r-rd)) ans++;
    }
    printf("%d\n", ans);
}

