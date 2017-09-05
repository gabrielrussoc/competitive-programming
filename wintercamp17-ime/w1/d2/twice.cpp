#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;


const int N = 105;
const int M = (1<<11);
int n, f[55];
char s[505], ans[505], loc[505];

void first() {
    for(int i = 0; i < 20; i++) {
        ans[i] = '9' - (i / 2);
    }
    int k = min(20, n-1);
    ans[k] = 0;
}

void calc(int k) {
    for(int d = 0; d < 10; d++) f[d] = 0;
    for(int i = 0; i < k; i++) {
        int d = s[i] - '0';
        loc[i] = s[i];
        f[d]++;
        if(f[d] == 3) return;
    }
    if(s[k] == '0') return;
    bool go = false;
    for(int d = s[k] - '0' - 1; d >= 0 && !go; d--) {
        if(f[d] < 2) {
            go = true;
            if(d == 0) f[d] += !!k;
            else f[d]++;
            loc[k] = d + '0';
        }
    }
    if(!go) return;
    for(int i = k+1; i < n; i++) {
        bool can = false;
        for(int d = 9; d >= 0 && !can; d--) {
            if(f[d] < 2) {
                f[d]++;
                loc[i] = d + '0';
                can = true;
            }
        }
        if(!can) return;
    }
    for(int i = 0; i < n; i++) ans[i] = loc[i];
    ans[n] = 0;
}

bool good() {
    for(int d = 0; d < 10; d++) f[d] = 0;
    for(int i = 0; i < n; i++) {
        int d = s[i] - '0';
        f[d]++;
        if(f[d] == 3) return 0;
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf(" %s", s);
        n = strlen(s);
        if(good()) {
            puts(s);
            continue;
        }
        first();
        for(int p = 0; p < n; p++) {
            calc(p);
        }
        if(ans[0] == '0') puts(ans+1);
        else puts(ans);
    }
}

