#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

ll n;
char s[33], ans[33];
int k;

bool build(int i, int l, bool pre) {
    if(i == k) return true;
    int st = 9;
    if(pre) st = s[i] - '0';
    for(int j = st; j >= l; j--) {
        ans[i] = j + '0';
        if(build(i+1, j, pre && s[i]-'0' == j))
            return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        scanf("%lld", &n);
        sprintf(s, "%lld", n);
        k = strlen(s);
        ans[k] = 0;
        printf("Case #%d: ", tc);
        if(build(0, 1, true)) printf("%s", ans);
        else for(int i = 0; i < k-1; i++) putchar('9');
        putchar('\n');
    }
}

