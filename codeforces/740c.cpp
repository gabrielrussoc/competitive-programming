#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int n, m, l, r, ans;

int main() {
    scanf("%d %d",&n,&m);
    ans = N;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        ans = min(ans, r-l+1);
    }
    printf("%d\n",ans);
    for(int i = 0; i < n; i++) printf("%d ", i % ans);
    putchar('\n');
}

