#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int k, n;
char s[1234];

void flip(int p) {
    for(int i = p; i < p + k; i++) {
        if(s[i] == '-') s[i] = '+';
        else s[i] = '-';
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++) {
        scanf(" %s %d", s, &k);
        n = strlen(s);
        int ans = 0;
        for(int i = 0; i <= n - k; i++) {
            if(s[i] == '-') {
                flip(i);
                ans++;
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == '-') ans = -1;
        }
        printf("Case #%d: ", tc);
        if(ans == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
}

