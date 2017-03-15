#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    scanf("%d",&n);
    int maxl1, maxl2, minr1, minr2;
    maxl1 = maxl2 = -1;
    minr1 = minr2 = INT_MAX;
    for(int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d",&l, &r);
        maxl1 = max(maxl1, l);
        minr1 = min(minr1, r);
    }
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        int l, r;
        scanf("%d %d",&l, &r);
        maxl2 = max(maxl2, l);
        minr2 = min(minr2, r);
    }
    int ans = max(maxl2 - minr1, maxl1 - minr2);
    printf("%d\n", max(ans, 0));
}

