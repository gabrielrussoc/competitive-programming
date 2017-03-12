#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int v[21234];
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", v+i);
        sort(v, v+n);
        int ans = INT_MAX;
        for(int i = 0; i <= n-k; i++) ans = min(ans, v[i+k-1] - v[i]);
        printf("%d\n", ans);
    }
}